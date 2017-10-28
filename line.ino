#include "line.h"
#include "movements.h"

//Фунции чтения ИК-датчиков линии
#define GET_LEFT_IR() digitalRead(LEFT_IR_PIN)
#define GET_RIGHT_IR() digitalRead(RIGHT_IR_PIN)

#define SPEED_HIGH 255
#define SPEED_MID 100
#define SPEED_ZERO 0

State rideOnLine(State currentState) {
    int IR_R = GET_RIGHT_IR();
    int IR_L = GET_LEFT_IR();

    // если правый видит черное
    if (IR_L == 0 && IR_R == 1) {
        moveLeftForward(SPEED_ZERO);
        moveRightForward(SPEED_HIGH);
    }

    // если левый видит черное
    else if (IR_L == 1 && IR_R == 0) {
        moveLeftBackwards(SPEED_MID);
        moveRightForward(SPEED_HIGH);
    }

    // если оба видят белое
    else if (IR_L == 0 && IR_R == 0) {
        moveLeftForward(SPEED_HIGH);
        moveRightForward(SPEED_HIGH);
    }

    else if (IR_L == 1 && IR_R == 1) {
        moveLeftForward(SPEED_HIGH);
        moveRightForward(SPEED_HIGH);
    }

    return State::LINE;
}