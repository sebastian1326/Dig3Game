#ifndef _GETVALUE_H_
#define _GETVALUE_H_

#include "pico/stdlib.h"

#define GV_MIN_VALUE    200
#define GV_MAX_VALUE    5000
#define CHAR_ENTER      13

uint32_t getValueFromTerminal(void);

#endif