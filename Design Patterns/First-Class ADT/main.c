/*
Based on "Software Design Patterns in C - Educative.io"

In this code you can see the First-Class ADT pattern in action. 
You can uncomment the code on line 13 and try to access a field in 
the Customer structure. You will see an error regarding the invalid 
use of undefined type ‘struct Customer’. We will have to use the provided 
interface functions to access the struct members.

Why We Need First-Class ADT Pattern?
Well, in an ideal world, in a single module, each change would be isolated to the other.
Given the interface above, clients depend upon the internal structure in at least one way. 
At worst, though, the clients would alter the internals of the data structure themselves, 
leading to costly changes for all clients.

Frequent code inspections and programmer discipline can prevent this. In any case, we still 
have the compile-time dependencies. Changes require a post-re-compilation of all clients, 
and the compilation time may be significant in large systems.

The First-Class ADT pattern eliminates both dependency problems. 
The pattern provides us with a method of separating interface from implementation, 
achieving true information hiding.

Main consequences of applying the First-Class ADT:
 - Improved encapsulation: We decouple interface and implementation, following the recommended 
 principle of programming towards an interface rather than implementation.
 - Loose coupling: As illustrated, all dependencies on the internals of the data structure 
 are eliminated from client code.
 - Controlled construction and destruction: Gives us full control over the construction 
 and destruction of objects. We can ensure the proper de-allocation of all elements of the object.
 - Extra level of indirection: There is a slight performance cost involved. It implies one extra 
 level of indirection on all operations on the data structure.
 - Increased dynamic memory usage: In problem domains where there may be potentially 
 many instances of a quantity unknown at compile-time, we cannot use a static allocation strategy.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Customer.h"

int main() {
	// Employee definition

	char *name = "Smith"; 
	Address* addr = malloc(sizeof *addr);

	CustomerPtr cptr = createCustomer(name, addr);
	// printf ( "Hello world, %s\n", cptr->name);
	printf ( "Hello world, %s\n", getName(cptr));
}