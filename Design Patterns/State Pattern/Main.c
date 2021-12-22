/*
Based on "Software Design Patterns in C - Educative.io"

Introducing state in our programs has implications for our ability to reason about them. Not only do we 
have to consider the algorithm in the light of its input arguments:
We must also determine the current state.
How will it impact the computation?
To complicate matters more, most of these states are hidden as implicit elements within the design. 
They’re expressed as combinations of different variables. It would be easier to express these as state 
machines in our code.

A traditional and direct way to implement this behavior in C is with conditional logic in the shape of 
switch/case statements and if-else chains. Conditional logic is perfectly fine for simple scenarios with 
2 or 3 possible states.
This is a superficially simple solution. While the coding construct may be simple, the approach introduces 
several potential problems:
It doesn’t scale: In large state machines, the code may stretch over page after page of nested conditional 
logic. Imagine the true maintenance nightmare of changing large, monolithic segments of conditional statements
No separation of concerns: When using conditional logic for implementing state machines, there is no clear 
separation between the code of the state machine itself and the actions associated with the various events. 

In many programs, state transitions are often implicit in the design in the shape of conditional logic. 
It’s a superficially simple solution that’s easy to understand for simple state handling. However, 
expressing state handling with conditional logic doesn’t scale well. What are the main scaling challenges?
Complex state handling can become opaque and hard to fit in one’s head when reasoning about the code.
The state handling becomes implicit, meaning the actual state is a combination of different variables, 
making it hard to debug and maintain the code.
It lacks a clear separation between the code of the state machine itself and the actions associated with 
the various events.
Encourages code duplication as it’s easy to repeat the same logic in multiple places inside larger 
conditional chains.
State is useful for more complex state handling when there’s application logic associated with each state

The key idea in the State pattern implementation is to represent each state as a distinct object. 
A state transition means changing the reference from one of the concrete states to another; 
our state representation appears to change behaviour at run-time. This achieved in the C language by 
letting the actual state be a pointer to a function. Changing state simply means pointing to a different 
function.

A state transition simply means changing the reference in the context (DigitalStopWatch) from one of the 
concrete states to the other.
 
When modeling our code as a finite state machine, there are always going to be certain events that aren’t 
valid in a given state. 
How does the State pattern help in writing robust and secure code? Our implementation of State lets us 
initialize our state representation with a default implementation for each event. That way, there’s 
always a fallback with the controls built into the design.

One trade-off with the State pattern is that you end up with more compilation units (e.g., files) and 
less compact code.

*/

#include "DigitalStopWatch.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    DigitalStopWatchPtr watchPtr = createWatch();
    printf("Digital StopWatch created\n");

    startWatch(watchPtr);
    printf("StopWatch started\n");

    stopWatch(watchPtr);
    printf("StopWatch stopped\n");
    
    destroyWatch(watchPtr);
    printf("Digital StopWatch destroyed\n");
}