// Button click events handler lib.
#ifndef BUTTON_HANDLER_H
#define BUTTON_HANDLER_H

#include <Arduino.h>

class ButtonHandler {
  const byte BTN_STATUS_CLICKED = 0;
  const byte BTN_STATUS_RELEASED = 1;

  private:
    byte pin;

    unsigned int short_click_event_interval;
    unsigned int double_click_event_interval;
    unsigned int long_click_event_interval;
    unsigned int rattle;

    long last_press = 0;
    long last_release = 0;
    long last_click_event = 0;
    long last_double_click_event = 0;

    bool was_click = false;
    bool was_double_click = false;
    bool was_long_click = false;

    byte btn_status = BTN_STATUS_RELEASED;
    char btn_event = EVENT_IDLE;

  public:
    static const char EVENT_SHORT_CLICK = 's';
    static const char EVENT_DOUBLE_CLICK = 'd';
    static const char EVENT_LONG_CLICK = 'l';
    static const char EVENT_IDLE = 'i';

    // Setup pin and call init()
    ButtonHandler(byte pin, unsigned int short_click_event_interval, unsigned int double_click_event_interval, unsigned int long_click_event_interval, unsigned int rattle);
    // Setup the button pin as INPUT
    void init();
    // Process click events
    void processEvents();
    // Returns event status happened with button. e.g. double
    char getEvent();
};

#endif
