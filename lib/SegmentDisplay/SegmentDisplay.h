#ifndef SegmentDisplay_H
#define SegmentDisplay_H

#include "Arduino.h"

class SegmentDisplay
{
    public:
        SegmentDisplay(int, int, int, int, int, int);
        void displayDecimal(int);
        void displayDecimalDigit(int, int);
        void displayTest();

    private:
	    int displayDigits[4] = {1,2,4,8};
        int segmentSerialPin;
        int segmentRegisterClockPin;
        int segmentShiftRegisterClockPin;
        int digitSerialPin;
        int digitRegisterClockPin;
        int digitShiftRegisterClockPin;
    
};

#endif