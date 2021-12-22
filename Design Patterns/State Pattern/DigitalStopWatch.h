/*
Design Patterns defines DigitalStopWatch as the context. The context has a reference to one of 
our concrete states, without knowing exactly which one. It is the context that specifies the 
interface to the clients.
*/
#ifndef DIGITAL_STOP_WATCH_H
#define DIGITAL_STOP_WATCH_H

#include "WatchState.h"

/* 
A pointer to an incomplete type (hides the implementation details). 
*/
typedef struct DigitalStopWatch* DigitalStopWatchPtr;

/*
A watch is implemented using the First-Class ADT pattern.
*/

DigitalStopWatchPtr createWatch(void);

WatchStatePtr getWatchState(DigitalStopWatchPtr instance);

void destroyWatch(DigitalStopWatchPtr instance);

void startWatch(DigitalStopWatchPtr instance);

void stopWatch(DigitalStopWatchPtr instance);

#endif
