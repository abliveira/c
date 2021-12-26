#include "DiagnosticsServer.h"
#include "ReactorEventLoop.h"
#include "Error.h"
#include <stddef.h>
#include <stdio.h>
#include <pthread.h>

/*
Based on "Software Design Patterns in C - Educative.io"

The intent of the Reactor pattern is: “The Reactor architectural pattern allows event-driven applications to demultiplex and 
dispatch service requests that are delivered to an application from one or more clients”

The roles of the involved participants are:
- EventHandler: An EventHandler defines an interface to be implemented by modules reacting to events. Each EventHandler owns 
its Handle.
- Handle: An efficient implementation of the Reactor pattern requires an OS that supports handles (examples of Handles include 
system resources like files, sockets, and timers).
- DiagnosticsServer and DiagnosticsClient: These two are concrete event handlers, each one encapsulating one responsibility. To 
be able to receive event notifications, the concrete event handlers have to register themselves at the Reactor.
- Reactor: The Reactor maintains registrations of EventHandlers and fetches the associated Handles. The Reactor waits for 
events on its set of registered Handles and invokes the corresponding EventHandler as a Handle indicates an event.



Pattern-Oriented Software Architecture (Schmidt et al.) describes two general strategies for dispatching event notifications:

Single-method interface: An event handler is notified about all events through one, single function. The type of event 
(typically in the form of an enum) is passed as a parameter to the function. The disadvantage of this approach is that it sets 
the stage for conditional logic, which soon gets hard to maintain.
Multi-method interface: In this case, the event handler declares separate functions for each supported event (e.g. handleRead, 
handleWrite, handleTimeout). As the Reactor knows what event occurred, it invokes the corresponding function immediately, thus 
avoiding placing the burden on the event handler to re-create the event from a parameter.

Although the mechanisms used to implement them are related, there are differences between these two patterns. The main 
difference is in the notification mechanism. As a Subject changes its state in an Observer implementation, all its dependents 
(observers) are notified. In a Reactor implementation, this relationship is one to one – a detected event leads the Reactor to 
notify exactly one dependent (EventHandler).
*/

void *EventHandlerLoop(){
   /* Enter the eternal reactive event loop. */
   for(;;){
      HandleEvents();
   }
}

int main(void){
   
   /* Create a server and enter an eternal event loop, watching 
      the Reactor do the rest. */
   
   const unsigned int serverPort = 7000;
   DiagnosticsServerPtr server = createServer(serverPort);

   if(NULL == server) {
      error("Failed to create the server");
   }

   EventHandlerLoop();
}
