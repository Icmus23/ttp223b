#include "ttp223b.h"

#define BTNPIN 3

#define SHORT_CLICK_EVENT_INTERVAL 150
#define DOUBLE_CLICK_EVENT_INTERVAL 300
#define LONG_CLICK_EVENT_INTERVAL 500
#define RATTLE_VALUE 200

Ttp223b ttp(
  BTNPIN,
  SHORT_CLICK_EVENT_INTERVAL,
  DOUBLE_CLICK_EVENT_INTERVAL,
  LONG_CLICK_EVENT_INTERVAL,
  RATTLE_VALUE
);

void setup() {
  Serial.begin(9600);
  Serial.println("System started!");
}

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
