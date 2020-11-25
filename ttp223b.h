// TTP223B button click handler lib.
#ifndef TTP223B_H
#define TTP223B_H

#include <Arduino.h>

class Ttp223b {
  const byte BTN_STATUS_CLICKED = 0;
  const byte BTN_STATUS_RELEASED = 1;

  private:
    byte pin;
    
    byte short_click_event_interval;
    byte double_click_event_interval;
    byte long_click_event_interval;
    
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
    Ttp223b(byte pin, byte short_click_event_interval, byte double_click_event_interval, byte long_click_event_interval);
    // Setup the button pin as INPUT
    void init();
    // Process click events
    void processEvents();
    // Returns event status happened with button. e.g. double 
    char getEvent();
};

#endif
