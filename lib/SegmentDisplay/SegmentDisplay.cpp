#include "SegmentDisplay.h"
#include "pins.h"

SegmentDisplay::SegmentDisplay() {
	_segmentSerialPin = segmentSerialPin;
	_segmentRegisterClockPin = segmentRegisterClockPin;
	_segmentShiftRegisterClockPin = segmentShiftRegisterClockPin;

	_digitSerialPin = digitSerialPin;
	_digitRegisterClockPin = digitRegisterClockPin;
	_digitShiftRegisterClockPin = digitShiftRegisterClockPin;

    pinMode(_segmentSerialPin, OUTPUT); 
	pinMode(_segmentRegisterClockPin, OUTPUT);
	pinMode(_segmentShiftRegisterClockPin, OUTPUT);

	pinMode(_digitSerialPin, OUTPUT);
	pinMode(_digitRegisterClockPin, OUTPUT);
	pinMode(_digitShiftRegisterClockPin, OUTPUT);
}

SegmentDisplay::SegmentDisplay(int segmentSerial, int segmentRegisterClock, int segmentShiftRegisterClock, int digitSerial, int digitRegisterClock, int digitShiftRegisterClock) {
	_segmentSerialPin = segmentSerial;
	_segmentRegisterClockPin = segmentRegisterClock;
	_segmentShiftRegisterClockPin = segmentShiftRegisterClock;

	_digitSerialPin = digitSerial;
	_digitRegisterClockPin = digitRegisterClock;
	_digitShiftRegisterClockPin = digitShiftRegisterClock;

    pinMode(_segmentSerialPin, OUTPUT); 
	pinMode(_segmentRegisterClockPin, OUTPUT);
	pinMode(_segmentShiftRegisterClockPin, OUTPUT);

	pinMode(_digitSerialPin, OUTPUT);
	pinMode(_digitRegisterClockPin, OUTPUT);
	pinMode(_digitShiftRegisterClockPin, OUTPUT);
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


	digitalWrite(_digitRegisterClockPin, LOW);
	digitalWrite(_segmentRegisterClockPin, LOW);
	delay(4);

	shiftOut(_digitSerialPin, _digitShiftRegisterClockPin, MSBFIRST, displayDigits[digitToDisplay-1]);
	digitalWrite(_digitRegisterClockPin, HIGH);
	shiftOut(_segmentSerialPin, _segmentShiftRegisterClockPin, MSBFIRST, displayNumbers[numberToDisplay]);
	digitalWrite(_segmentRegisterClockPin, HIGH);
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

