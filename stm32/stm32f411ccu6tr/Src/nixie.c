//
// Created by sztuka on 17.03.2023.
//
#include "nixie.h"


void setNixieTime(Nixie_Clock* clock, RTC_TimeTypeDef* time) {
    setNixie(clock->tubes[0], time->Hours/10);
    setNixie(clock->tubes[1], time->Hours%10);
    setNixie(clock->tubes[2], time->Minutes/10);
    setNixie(clock->tubes[3], time->Minutes%10);
}

void NixieShuffle(Nixie_Clock* clock) {
    uint8_t previousValues[4];
    for (int i = 0; i < 4; i++) {
        previousValues[i] = clock->tubes[i]->value;
    }
    for (int i = 0; i < 10; i++) {
        for(int b = 0; b<4; b++){
            setNixie(clock->tubes[b], i);
        }
        HAL_Delay(200);
    }
    for (int i = 0; i < 4; i++) {
        setNixie(clock->tubes[i], previousValues[i]);
    }
}

void setNixie(Nixie_IC* nixie, uint8_t value) {
    if(value>9) value = 15; // if value greater than 9 turn off nixie to signal error
    nixie->value = value;
    for (int i = 0; i < 4; i++) {
        // (value>>i)&1 walks through the bits of value
        HAL_GPIO_WritePin(nixie->ports[i]->port, nixie->ports[i]->pin, (value>>i)&1);
    }
}

void disableNixie(Nixie_IC* nixie) {
    for (int i = 0; i < 4; i++) {
        HAL_GPIO_WritePin(nixie->ports[i]->port, nixie->ports[i]->pin, 1);
    }
}