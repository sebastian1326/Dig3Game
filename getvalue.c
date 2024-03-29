/**
 * @file helloandblink.c
 * @brief This file contains the definitions and functions
 * necessary for reading values from a serial terminal
 */

// Standard libraries
#include <stdio.h>
#include "pico/stdlib.h"

#include "getvalue.h"

uint32_t getValueFromTerminal(void) {
    uint32_t valAcum = 0;
    int c;

    c = getchar_timeout_us(0);
    if (c != PICO_ERROR_TIMEOUT) {
        printf("Ingrese un valor entre %d y %d: ", GV_MIN_VALUE, GV_MAX_VALUE);
        while ((c = getchar()) != CHAR_ENTER) {
            if (c >= '0' && c <= '9')
                valAcum = valAcum*10 + (c & 0x0F);
        }

        if (valAcum < GV_MIN_VALUE || valAcum > GV_MAX_VALUE) {
            printf("Valor por fuera de rango: %d\n", valAcum);
            valAcum = PICO_ERROR_TIMEOUT;
        }
        else
            printf("Valor aceptado: %d\n", valAcum);
    }
    else
        valAcum = PICO_ERROR_TIMEOUT;

    return valAcum;    
}

