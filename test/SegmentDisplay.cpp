#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <FS.h>
#include <pins.h>

#include "SegmentDisplay.h"

SegmentDisplay display(segmentSerialPin, segmentRegisterClockPin, segmentShiftRegisterClockPin, digitSerialPin, digitRegisterClockPin, digitShiftRegisterClockPin);

void setup() { }

void loop() {
	display.displayTest();
}