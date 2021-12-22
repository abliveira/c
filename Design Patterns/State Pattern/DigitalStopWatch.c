#include "DigitalStopWatch.h"

/* We need to know about or initial state: */
#include "StoppedState.h"

#include "WatchStateInternal.h"
#include "error.h"
#include <stdlib.h>

/*
Client Code#
The reward for the struggle so far comes when implementing the context (i.e., the 
client of the state machine). Once we set the initial state, all the client code has 
to do is delegate the requests to the state.
*/

struct DigitalStopWatch 
{
  struct WatchState state; 
  /* The struct can have more memebers */
};

DigitalStopWatchPtr createWatch(void) 
{
  DigitalStopWatchPtr instance = malloc(sizeof *instance);

  if(NULL != instance) {
    /* Specify the initial state. */
    transitionToStopped(&instance->state);
    /* Initialize the other attributes here.*/
  }

  return instance; 
}

WatchStatePtr getWatchState(DigitalStopWatchPtr instance)
{
  if(NULL != instance) {
    return &instance->state;
  }
}

void destroyWatch(DigitalStopWatchPtr instance) 
{
  if(NULL != instance) {
    free(instance);
  }
}

void startWatch(DigitalStopWatchPtr instance) 
{
  if(NULL != instance) {
    instance->state.start(&instance->state);
  }
}

void stopWatch(DigitalStopWatchPtr instance) 
{
  if(NULL != instance) {
    instance->state.stop(&instance->state);
  }
}