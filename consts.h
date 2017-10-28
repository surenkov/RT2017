#pragma once

//ИК датчики
#define LEFT_IR_PIN 11
#define RIGHT_IR_PIN 10

//Драйвер моторов
#define AIN1 7
#define AIN2 4
#define BIN1 9
#define BIN2 8
#define PWMA 3
#define PWMB 5

#define STBY 12
#define SERVO_PWM 6

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

enum class Color {
    BLACK = 1,
    WHITE = 0,
    GREEN = 2,
    YELLOW = 3,
    VIOLET = 4,
    RED = 5,
};