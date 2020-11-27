#include <ButtonHandler.h>

ButtonHandler::ButtonHandler(byte pin, unsigned int short_click_event_interval, unsigned int double_click_event_interval, unsigned int long_click_event_interval, unsigned int rattle) {
  this->pin = pin;
  this->short_click_event_interval = short_click_event_interval;
  this->double_click_event_interval = double_click_event_interval;
  this->long_click_event_interval = long_click_event_interval;
  this->rattle = rattle;
  init();
}

void ButtonHandler::init() {
  pinMode(pin, INPUT);
}

void ButtonHandler::processEvents() {
  // If the btn is clicked.
  if (digitalRead(pin) == HIGH) {
    // If btn previous state was released and we clicked it - remember this timestamp as last_press
    // and change the btn status.
    if (btn_status == BTN_STATUS_RELEASED && abs(millis() - last_press) > rattle) {
       last_press = millis();
       btn_status = BTN_STATUS_CLICKED;
    }
  } else {
    // If btn previous status was clicked and we released it - remember this timestamp as last_release
    // and change the btn status.
    if (btn_status == BTN_STATUS_CLICKED && abs(millis() - last_release) > rattle) {
      last_release = millis();
      // If diff between last_release and last_press is less than CLICK_EVENT_INTERVAL value, we can consider it as
      // click event.
      if (abs(last_release - last_press) < short_click_event_interval) {
        // If click happened and diff between last_click_event and current millis is less than DOUBLE_CLICK_EVENT_INTERVAL and
        // last_double_click_event happened more than click + double click time ago - this is another double click.
        if (
          abs(millis() - last_click_event) < double_click_event_interval &&
          // this condition helps to determine that 4 fast clicks are not 3 double_clicks, but 2.
          abs(millis() - last_double_click_event) > (short_click_event_interval + double_click_event_interval)
        ) {
          was_double_click = true;
          last_double_click_event = millis();
        }

        was_click = true;
        last_click_event = millis();
      } else if (abs(last_release - last_press) > long_click_event_interval) {
        was_long_click = true;
      }

      btn_status = BTN_STATUS_RELEASED;
    }
  }

  if (was_click && was_double_click) {
    btn_event = ButtonHandler::EVENT_DOUBLE_CLICK;
    was_click = false;
    was_double_click = false;
  } else if (was_click && millis() - last_release > double_click_event_interval) {
    btn_event = ButtonHandler::EVENT_SHORT_CLICK;
    was_click = false;
  } else if (was_long_click) {
    btn_event = ButtonHandler::EVENT_LONG_CLICK;
    was_long_click = false;
  } else {
    btn_event = ButtonHandler::EVENT_IDLE;
  }
}

char ButtonHandler::getEvent() {
  return btn_event;
}
