#include "hill.h"
#include "movements.h"

#define SPEED 255

State climbOnHill(State currentState) {
    moveLeftForward(SPEED);
    moveRightForward(SPEED);
    return State::HILL;
}
