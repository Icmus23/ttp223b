# TTP223B Digital Touch Sensor lib for handling click events.

Lib helps to handle short click, double click and long click events. You can specify button sensitivity by changing interval constants values like described below.

Example of usage:
```c++
#define SHORT_CLICK_EVENT_INTERVAL 100
#define DOUBLE_CLICK_EVENT_INTERVAL 250
#define LONG_CLICK_EVENT_INTERVAL 500

Ttp223b ttp(
  BTNPIN,
  SHORT_CLICK_EVENT_INTERVAL,
  DOUBLE_CLICK_EVENT_INTERVAL,
  LONG_CLICK_EVENT_INTERVAL
);

void loop() {
    // Call this function in loop to make Ttp223b class process button events.
    ttp.processEvents();

    // Example of handling events from button.
    switch (ttp.getEvent()) {
        case Ttp223b::EVENT_SHORT_CLICK:
        Serial.println("short");
        break;
        case Ttp223b::EVENT_DOUBLE_CLICK:
        Serial.println("double");
        break;
        case Ttp223b::EVENT_LONG_CLICK:
        Serial.println("long");
        break;
    }
}
```