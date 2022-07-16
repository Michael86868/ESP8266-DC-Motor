#include "SegmentDisplay.h"

SegmentDisplay::SegmentDisplay(int segmentSerialPin, int segmentRegisterClockPin, int segmentShiftRegisterClockPin, int digitSerialPin, int digitRegisterClockPin, int digitShiftRegisterClockPin) {
	this->segmentSerialPin = segmentSerialPin;
	this->segmentRegisterClockPin = segmentRegisterClockPin;
	this->segmentShiftRegisterClockPin = segmentShiftRegisterClockPin;

	this->digitSerialPin = digitSerialPin;
	this->digitRegisterClockPin = digitRegisterClockPin;
	this->digitShiftRegisterClockPin = digitShiftRegisterClockPin;

    pinMode(this->segmentSerialPin, OUTPUT); 
	pinMode(this->segmentRegisterClockPin, OUTPUT);
	pinMode(this->segmentShiftRegisterClockPin, OUTPUT);

	pinMode(this->digitSerialPin, OUTPUT);
	pinMode(this->digitRegisterClockPin, OUTPUT);
	pinMode(this->digitShiftRegisterClockPin, OUTPUT);
}

void SegmentDisplay::displayDecimalDigit(int digitToDisplay, int numberToDisplay) {

	byte displayNumbers[10] = {
		B11000000,
		B11111001,
		B10100100,
		B10110000,
		B10011001,
		B10010010,
		B10000010,
		B11111000,
		B10000000,
		B10011000
	};

	byte displayDigits[4] = {
		B00000001,
		B00000010,
		B00000100,
		B00001000
	};


	digitalWrite(this->digitRegisterClockPin, LOW);
	digitalWrite(this->segmentRegisterClockPin, LOW);
	delay(4);

	shiftOut(this->digitSerialPin, this->digitShiftRegisterClockPin, MSBFIRST, displayDigits[digitToDisplay-1]);
	digitalWrite(this->digitRegisterClockPin, HIGH);
	shiftOut(this->segmentSerialPin, this->segmentShiftRegisterClockPin, MSBFIRST, displayNumbers[numberToDisplay]);
	digitalWrite(this->segmentRegisterClockPin, HIGH);
}

void SegmentDisplay::displayDecimal(int numberToDisplay) {
	for(int i = 3; i >= 0; i--) {
		displayDecimalDigit(i, numberToDisplay % 10);
		numberToDisplay /= 10;
	}
}

void SegmentDisplay::displayTest() {
	for(int i = 0; i < 10; i++) {
		displayDecimalDigit(1 ,i);
		delay(1000);
	}
}

