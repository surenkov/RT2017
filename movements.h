#pragma once

#define FORWARD_MOVE HIGH, LOW
#define BACKWARDS_MOVE LOW, HIGH

// moving abstractions
inline void setUpWheel(int pin1, int pin2, int dir1, int dir2) {
    digitalWrite(STBY, HIGH);
    digitalWrite(pin1, dir1);
    digitalWrite(pin2, dir2);
}

inline void moveRightForward(int speed) {
    setUpWheel(AIN1, AIN2, FORWARD_MOVE);
    analogWrite(PWMA, speed);
}

inline void moveRightBackwards(int speed) {
    setUpWheel(AIN1, AIN2, BACKWARDS_MOVE);
    analogWrite(PWMA, speed);
}

inline void moveLeftForward(int speed) {
    setUpWheel(BIN1, BIN2, FORWARD_MOVE);
    analogWrite(PWMB, speed);
}

inline void moveLeftBackwards(int speed) {
    setUpWheel(BIN1, BIN2, BACKWARDS_MOVE);
    analogWrite(PWMB, speed);
}