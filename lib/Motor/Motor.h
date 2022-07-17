#ifndef Motor_H
#define Motor_H

class Motor
{
    private:
        int motorValue;

    public:
        Motor();
        int getMotorValue();
        void setMotorValue(int motorValue);
};

#endif