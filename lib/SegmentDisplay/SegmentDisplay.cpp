#include "SegmentDisplay.h"
#include "pins.h"

SegmentDisplay::SegmentDisplay() {
	this->_segmentSerialPin = segmentSerialPin;
	this->_segmentRegisterClockPin = segmentRegisterClockPin;
	this->_segmentShiftRegisterClockPin = segmentShiftRegisterClockPin;

	this->_digitSerialPin = digitSerialPin;
	this->_digitRegisterClockPin = digitRegisterClockPin;
	this->_digitShiftRegisterClockPin = digitShiftRegisterClockPin;

    pinMode(this->_segmentSerialPin, OUTPUT); 
	pinMode(this->_segmentRegisterClockPin, OUTPUT);
	pinMode(this->_segmentShiftRegisterClockPin, OUTPUT);

	pinMode(this->_digitSerialPin, OUTPUT);
	pinMode(this->_digitRegisterClockPin, OUTPUT);
	pinMode(this->_digitShiftRegisterClockPin, OUTPUT);
}

SegmentDisplay::SegmentDisplay(int segmentSerial, int segmentRegisterClock, int segmentShiftRegisterClock, int digitSerial, int digitRegisterClock, int digitShiftRegisterClock) {
	this->_segmentSerialPin = segmentSerial;
	this->_segmentRegisterClockPin = segmentRegisterClock;
	this->_segmentShiftRegisterClockPin = segmentShiftRegisterClock;

	this->_digitSerialPin = digitSerial;
	this->_digitRegisterClockPin = digitRegisterClock;
	this->_digitShiftRegisterClockPin = digitShiftRegisterClock;

    pinMode(this->_segmentSerialPin, OUTPUT); 
	pinMode(this->_segmentRegisterClockPin, OUTPUT);
	pinMode(this->_segmentShiftRegisterClockPin, OUTPUT);

	pinMode(this->_digitSerialPin, OUTPUT);
	pinMode(this->_digitRegisterClockPin, OUTPUT);
	pinMode(this->_digitShiftRegisterClockPin, OUTPUT);
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


	digitalWrite(this->_digitRegisterClockPin, LOW);
	digitalWrite(this->_segmentRegisterClockPin, LOW);
	delay(4);

	shiftOut(this->_digitSerialPin, this->_digitShiftRegisterClockPin, MSBFIRST, displayDigits[digitToDisplay-1]);
	digitalWrite(this->_digitRegisterClockPin, HIGH);
	shiftOut(this->_segmentSerialPin, this->_segmentShiftRegisterClockPin, MSBFIRST, displayNumbers[numberToDisplay]);
	digitalWrite(this->_segmentRegisterClockPin, HIGH);
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
