#include "state.h"
#include "line.h"
#include "hill.h"
#include "ring.h"

State transitionTable(State currentState) {
    switch (currentState) {
        case State::LINE: return rideOnLine(currentState);
        case State::HILL: return climbOnHill(currentState);
        case State::RING: return winTheFight(currentState);
        default: return State::FINAL;
    }
}

void setup() {
}

auto currentState = State::LINE;
void loop() {
    currentState = transitionTable(currentState);
}
