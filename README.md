# Button Events Handler
## TTP223B Digital Touch Sensor and Tactile buttons lib for handling click events.

Lib helps to handle click events for sensor and tactile buttons.
Supported events:
 - short click
 - long click
 - double click

You can specify button sensitivity for each event, and set rattle value for specific button, by changing the next constants. Values specified in millis.
Default values:
```c++
# button_click.ino

#define SHORT_CLICK_EVENT_INTERVAL 150
#define DOUBLE_CLICK_EVENT_INTERVAL 300
#define LONG_CLICK_EVENT_INTERVAL 500
#define RATTLE_VALUE 200
```
