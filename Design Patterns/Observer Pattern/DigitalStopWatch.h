#ifndef DIGITAL_STOP_WATCH_H
#define DIGITAL_STOP_WATCH_H

#include "TimeSubject.h"

/* 
A pointer to an incomplete type (hides the implementation details). 
*/
typedef struct DigitalStopWatch* DigitalStopWatchPtr;

/*
A watch is implemented using the First-Class ADT pattern.
*/

static void updateDisplay(DigitalStopWatchPtr watch,
                          const SystemTime* newTime);

static void changedTime(void* instance, const SystemTime* newTime);

DigitalStopWatchPtr createDigitalWatch(void);

void destroyDigitalWatch(DigitalStopWatchPtr instance);

#endif
