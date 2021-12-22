/*
WatchState defines the interface of the state machine, specifying all supported events.
*/

#ifndef WATCH_STATE_H
#define WATCH_STATE_H

/* An incomplete type for the state representation itself. */
typedef struct WatchState* WatchStatePtr;

void defaultImplementation(WatchStatePtr state);

#endif
