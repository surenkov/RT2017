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
