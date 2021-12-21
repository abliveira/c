#include "Customer.h"
#include "Order.h"
#include <stdlib.h>

/*
As soon as the compiler detects a subsequent specifier with the same tag and a declaration list 
containing the members, the type is considered complete.
*/
struct Customer 
{
  const char* name;
  Address address; 
  size_t noOfOrders; 
  Order orders[42];
};
/* At this point, struct Customer is considered complete. */

/* 
In many embedded applications, this may not be an option. However, as we 
have encapsulated the memory allocation completely, we are free to choose another approach.
In embedded programming, where the maximum number of needed resources is typically known, 
the simplest allocator is an array.
If deallocation is needed, an array will still do.
*/

CustomerPtr createCustomer(
  const char* name,
  const Address* address) 
{
  CustomerPtr customer = malloc(sizeof *customer);

  if (customer) {
    customer->name= name; 
    customer->address = *address; 
  }

  return customer; 
}

const char* getName(CustomerPtr customer){
  if (customer) {
    return customer->name;
  }
}

void destroyCustomer(
  CustomerPtr customer) 
{
  /* Perform clean-up of the customer internals, if necessary. */
  if (customer) {
    free(customer);
  }
}