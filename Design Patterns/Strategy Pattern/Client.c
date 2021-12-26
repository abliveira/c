#include "Customer.h"
#include "CustomerCategories.h"
#include <stdio.h>
#include <stdlib.h>


/*
Based on "Software Design Patterns in C - Educative.io"

The example in this chapter started with a naive implementation where we did a switch-case on 
an enum (CustomerCategorycategory). This approach created control coupling. Since control coupling 
is a common design flaw, it pays off to understand and avoid it. The main problem with control coupling is
When we pass a flag to a function, we’re creating a dependency on the inner logic of that function. 
If our assumptions change, we have to modify multiple parts of our program instead of encapsulating the 
behavior in one place.

According to the open-closed principle:
- Extending the behavior of an ideal module is achieved by adding code instead of changing the existing source.
- Following this principle minimizes the risk of introducing bugs in existing, tested code and typically raises 
the quality of the design by introducing loose coupling.
- Unfortunately, it is virtually impossible to design a module so that it is closed against all kinds of changes.
- Even trying to design software in such a way would overcomplicate the design far beyond suitability.
- Identifying which modules to close and what changes to close them against requires experience and a good understanding 
of the problem domain.

Violation of the Open-Closed Principle#
- By violating the single responsibility principle, a code would be hard to maintain. It is code that one never wants 
to dig into in the future.
- We cannot add new functionality without modifying existing code.

Strategy is often a good approach when refactoring code duplication. You have multiple functions with very 
similar responsibilities. Extracting the varied concepts allows us to reuse the general algorithm. We can 
now represent each varied concept as a strategy passed to the general and reusable algorithm. This is true and 
it’s an example of the benefits of a design following the open-closed principle.
*/

/*
Client code illustrating the binding of a strategy:
*/
static CustomerPtr createBronzeCustomer(
  const char* name,
  const Address* address)
{
  return createCustomer(name, address, bronzePriceStrategy);
}


int main() {

  char *name = "Client Name"; 
	Address* addr = malloc(sizeof *addr);

  CustomerPtr newCustomer = createBronzeCustomer(name, addr);
  printf ("Bronze customer created\n");

  changePriceCategory(newCustomer, silverPriceStrategy);
  printf ("Customer stratgey changed to Silver\n");
}
