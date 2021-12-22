/*
StoppedState and StartedState are concrete states and each one of them encapsulates the 
behavior associated with the state it represents.
*/

#ifndef STOPPED_STATE_H
#define STOPPED_STATE_H

#include "WatchState.h"

void transitionToStopped(WatchStatePtr state);

#endif
