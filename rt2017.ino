#include "consts.h"
#include "color.h"
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
    Serial.begin(9600);

    pinMode(PWMA, OUTPUT);
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);

    pinMode(PWMB, OUTPUT);
    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);

    pinMode(STBY, OUTPUT);

    apds.init();
    apds.enableLightSensor(false);
    delay(500);
}

auto currentState = State::LINE;
void loop() {
    currentState = transitionTable(currentState);
    Serial.println(int(getColor()));
}
