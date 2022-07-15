#include <Arduino.h>

/* Pin for reading value from potentiometer for controlling DC motor */
int potentiometerPin = A0;

/* Pins for controlling 595 gate for 7 segment */
int segmentSerialPin = D2;             // clock
int segmentRegisterClockPin = D0;      // latch
int segmentShiftRegisterClockPin = D1; // data

/* Pins for controlling 595 gate for 4 7-segments */
int digitSerialPin = D3;             // clock
int digitRegisterClockPin = D8;      // latch
int digitShiftRegisterClockPin = D7; // data

/* Pin for button, which turning LED on or off */
int buttonTurningLedPin = D4;

/* Pin for power deep sleep */
int buttonDeepSleepPin = D5;

/* PWM Pin for controlling DC Motor */
int motorControlPin = D6;

/* Pins for indicate problem */
int errorLedPin = D9;

/* Pin for switching relay for connecting external battery */
int relayPin = D10;
