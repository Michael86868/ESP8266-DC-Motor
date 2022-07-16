#ifndef SegmentDisplay_H
#define SegmentDisplay_H

#include "Arduino.h"

class SegmentDisplay
{
    public:
        SegmentDisplay();
        SegmentDisplay(int, int, int, int, int, int);
        void displayDecimal(int);
        void displayDecimalDigit(int, int);
        void displayTest();

    private:
        int _segmentSerialPin;
        int _segmentRegisterClockPin;
        int _segmentShiftRegisterClockPin;
        int _digitSerialPin;
        int _digitRegisterClockPin;
        int _digitShiftRegisterClockPin;
    
};

#endif