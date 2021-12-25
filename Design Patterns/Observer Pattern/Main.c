#include "DigitalStopWatch.h"
#include "TimeSource.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


/*
Based on "Software Design Patterns in C - Educative.io"

The Observer pattern may serve as a tool for making a design follow the open-closed principle. Design Patterns captures 
the intent of Observer as “Define a one-to-many dependency between objects so that when one object changes state, all its 
dependents are notified and updated automatically”

The main consequences of applying the Observer pattern are:
- Observer gives the subject one extra responsibility that isn’t part of the core domain. That is, the subject gets a lower cohesion.
- The management of notifications can become complex if observers are temporary and unregistered during a notification chain.
- The introduction of a void-pointer means that the compiler doesn’t have any way to detect an erroneous conversion.

The core idea of the Stable Dependencies Principle is that Software entities should depend on the direction of stability.

An Observer has a one-to-many dependency. That dependency could be one-to-zero, and it’s a powerful way of avoiding special cases; 
a subject might not have any observers registered, and it’s a perfectly valid case. For example, consider program initialization 
where the observers might get registered after the subject is already running.

The one-to-many mechanism where a subject can notify multiple observers leads to an interesting implementation challenge: each specific observer can be of a different type. We solved this using void* pointers. The property of the void* type is that we can 
convert any pointer to void* and back to its original type again without losing any information.

Throughout the patterns, we have seen that the First-Class ADT pattern offers several benefits as the foundation when implementing more complex patterns. The main benefit of implementing the Observer pattern as a First-Class ADT is information hiding. Any 
implementation details – such as using the Observer pattern to register/deregister notifications – are encapsulated in the ADT 
creation and destruction API.

*/

int main() {

    DigitalStopWatchPtr watchPtr = createDigitalWatch();
    printf("1st Digital StopWatch created\n");

    // wait some time before time update
    sleep(1);
    msTick();

    // wait some more time before time update
    sleep(3);
    msTick();

    DigitalStopWatchPtr watchPtr2 = createDigitalWatch();
    printf("2nd Digital StopWatch created\n");

    // wait some more time before time update
    sleep(2);
    msTick();

    destroyDigitalWatch(watchPtr);
    printf("1st Digital StopWatch destroyed\n");

    // wait some more time before time update
    sleep(2);
    msTick();
}