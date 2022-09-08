/*

Variable : Nothing but a name given to location that can hold our value.
Static variable : Variable which preserve it's value even after it is out of it's scope. Once initialised, not initialised again.
Regular variable : Regular or local variable. It's scope is limited to a function itself or can only be used in a function where it is declared.
Global variable : Global variable is variable that is declared outside all functions. It's scope is throughout the program. It's value can be retrieved by all other functions.
Volatile Variable : Their value can be changed by code outside the scope of current code at any time. The volatile keyword is intended to prevent the compiler from any optimization.
*/

#include<stdio.h> 

// int a, b = 10;

void func_1() { 
    int a = 1; 
    static int b = 100; 
    printf("a = %d\n", a); 
    printf("b = %d\n\n", b); 
    a++; 
    b++; 
} 


// The main difference between static and normal variable is that static variable is initialized only once in the program and retains it’s value, unlike the normal value that gets initialized every time.

// Here is the example , it will help to clear it out
void func() { 
    static int static_var=1; 
    int non_static_var=1; 
 
    static_var++; 
    non_static_var++; 
 
    printf("Static = %d\n", static_var);
    printf("NonStatic = %d\n", non_static_var);
} 


/*
volatile tells the compiler not to optimize anything that has to do with the volatile variable.

There are at least three common reasons to use it, all involving situations where the value
of the variable can change without action from the visible code: 
- When you interface with hardware that changes the value itself; 
- when there's another thread running that also uses the variable;
- when there's a signal handler that might change the value of the variable.

Let's say you have a little piece of hardware that is mapped into RAM somewhere and that has two addresses: a command port and a data port:
*/
typedef struct
{
  int command;
  int data;
  int isBusy;
} MyHardwareGadget;
// Now you want to send some command:

void SendCommand (MyHardwareGadget * gadget, int command, int data) {
  // wait while the gadget is busy:
  while (gadget->isBusy) {
    // do nothing here.
  }
  // set data first:
  gadget->data = data;
  // writing the command starts the action:
  gadget->command = command;
}

/*
Looks easy, but it can fail because the compiler is free to change the order in which data and commands are written. This would cause our little gadget to issue commands with the previous data-value. Also take a look at the wait while busy loop. That one will be optimized out. The compiler will try to be clever, read the value of isBusy just once and then go into an infinite loop. That's not what you want.

The way to get around this is to declare the pointer gadget as volatile. This way the compiler is forced to do what you wrote. It can't remove the memory assignments, it can't cache variables in registers and it can't change the order of assignments either

This is the correct version:
*/
void SendCommand2 (volatile MyHardwareGadget * gadget, int command, int data) {
  // wait while the gadget is busy:
  while (gadget->isBusy) {
    // do nothing here.
  }
  // set data first:
  gadget->data = data;
  // writing the command starts the action:
  gadget->command = command;
}

 
int main() {

    func_1(); 
    func_1(); 
    func_1(); 

    // Expected Output:

    // a = 1 
    // b = 100 
    
    // a = 1 
    // b = 101 
    
    // a = 1 
    // b = 102 

    

    int i; 
    for (i = 0; i < 5; i++) { 
        func(); 
    } 

    // The above gives output as:

    // Static=2 
    // Nonstatic=2 

    // Static=3 
    // Nonstatic=2 

    // Static=4 
    // Nonstatic=2 

    // Static=5 
    // Nonstatic=2 

    // Static=6 
    // Nonstatic=2 

    return 0; 
} 