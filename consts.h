#pragma once

//ИК датчики
#define LEFT_IR_PIN 7
#define RIGHT_IR_PIN 11

//Драйвер моторов
#define AIN1 3
#define AIN2 2
#define BIN1 9
#define BIN2 8
#define PWMA 6
#define PWMB 5
#define STBY 12

#define SWAP_INT(A, B) \
    ((A) ^= (B)); \
    ((B) ^= (A)); \
    ((A) ^= (B));

enum class State {
    LINE,
    HILL,
    RING,
    FINAL,
};


// moving abstractions
inline void setUpWheel(int pin1, int pin2, int dir1, int dir2) {
    digitalWrite(STBY, HIGH);
    digitalWrite(pin1, dir1);
    digitalWrite(pin2, dir2);
}

inline void moveRightForward(int speed) {
    setUpWheel(AIN1, AIN2, HIGH, LOW);
    analogWrite(PWMA, speed);
}

inline void moveRightBackwards(int speed) {
    setUpWheel(AIN1, AIN2, LOW, HIGH);
    analogWrite(PWMA, speed);
}

inline void moveLeftForward(int speed) {
    setUpWheel(BIN1, BIN2, HIGH, LOW);
    analogWrite(PWMB, speed);
}

inline void moveLeftBackwards(int speed) {
    setUpWheel(BIN1, BIN2, LOW, HIGH);
    analogWrite(PWMB, speed);
}