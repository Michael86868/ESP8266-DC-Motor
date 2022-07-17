#include "Motor.h"

Motor::Motor(){
    ;
}

int Motor::getMotorValue() {
    return this->motorValue;
}

void Motor::setMotorValue(int motorValue) {
    this->motorValue = motorValue;
}