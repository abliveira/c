#include "StartedState.h"
#include "WatchStateInternal.h"
#include "WatchState.h"

/* Possible transition to the following state: */
#include "StoppedState.h"

static void stopWatch(WatchStatePtr state) 
{
    transitionToStopped(state);
}

void transitionToStarted(WatchStatePtr state) 
{
   /* Initialize with the default implementation before
      specifying the events to be handled in the started
      state. */
   defaultImplementation(state);
   state->stop = stopWatch;
   /* foo->bar is equivalent to (*foo).bar, i.e. it gets the member called bar from the struct that 
   foo points to. */

}
