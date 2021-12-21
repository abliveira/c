#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Address.h"

/* 
A pointer to an incomplete type (hides the implementation details). 

Instances of this pointer will serve as a handle for the clients of a First-Class ADT. 
This mechanism enforces the constraint on clients to use the provided interface functions 
because there is no way a client can access a field in the Customer structure.
Note: The C language does not allow an incomplete type to be dereferenced.
*/
typedef struct Customer* CustomerPtr;

/* 
Create a Customer and return a handle to it. 
*/
CustomerPtr createCustomer(
  const char* name,
  const Address* address);

/* 
Destroy the given Customer object.
All handles to it will be invalidated. 

As clients only get a handle on the object, the responsibility for creating it rests upon the ADT. 
The straightforward approach is to write one function that encapsulates the allocation of an object 
and initializes it. Similarly, we define a function for destructing the object.
*/
const char* getName(CustomerPtr customer);

void destroyCustomer(CustomerPtr customer);

#endif