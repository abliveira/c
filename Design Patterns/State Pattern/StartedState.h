/*
StoppedState and StartedState are concrete states and each one of them encapsulates the 
behavior associated with the state it represents.
*/

#ifndef STARTED_STATE_H
#define STARTED_STATE_H

#include "WatchState.h"

void transitionToStarted(WatchStatePtr state);

#endif
