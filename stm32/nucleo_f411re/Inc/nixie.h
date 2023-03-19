//
// Created by sztuka on 17.03.2023.
//

#ifndef STM32_NIXIE_CLOCK_NIXIE_H
#define STM32_NIXIE_CLOCK_NIXIE_H
#include "stm32f4xx_hal.h"


#endif //STM32_NIXIE_CLOCK_NIXIE_H
typedef struct {
    GPIO_TypeDef* port;
    uint16_t pin;
} Nixie_Pin;

typedef struct {
    Nixie_Pin* ports[4]; // A , B , C , D
    uint8_t value;
} Nixie_IC;

typedef struct {
    Nixie_IC* tubes[4];
} Nixie_Clock;

void setNixie(Nixie_IC* nixie, uint8_t value);
void setNixieTime(Nixie_Clock* clock, RTC_TimeTypeDef* time);
void disableNixie(Nixie_IC* nixie);
void NixieShuffle(Nixie_Clock* clock);