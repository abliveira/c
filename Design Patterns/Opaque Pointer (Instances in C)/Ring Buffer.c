/*

https://interrupt.memfault.com/blog/opaque-pointers

The opaque pointer is one of the most useful and frequently-encountered design patterns in C.

Objects are not a native concept in C, but you can achieve something resembling objects by using a design pattern known as the “opaque pointer”. This post will show you what the pattern is, explain some of the finer details, and provide guidance on when you should and shouldn’t use it.

The Opaque Pointer Pattern
opaque: not able to be seen through; not transparent.

In traditional OOP, an object has state (data) and behavior (functions) coupled together in one class.

If you want to have something resembling objects in C, you can:

Define a struct with your state data
Define functions which take a pointer to the struct as the first parameter
Declare a variable with that struct type to create an instance of the “object”
Need another object instance? Declare another variable with that struct type. Boom! Objects in C, baby!

Of course, there’s a little more to it than that (but not much).

Before getting into the details, let me show you the complete pattern first, using a ring buffer that stores uint8_t as an example. This is not a complete ringbuffer implementation. It’s just enough to show you the general pattern.
Object Life Cycle
When you use this pattern, it’s customary to declare *_create and *_destroy functions. These are analogous to constructors and destructors in OOP.

The *_create function will perform allocation and initialization of an instance and return an opaque pointer to the user, which represents the instance. It’s really just a pointer to a struct, but the user can’t see what’s in the struct. The user’s calling code will fail to compile if it tries to dereference the struct pointer because the struct is not defined in the header (it is only declared).

Likewise, *_destroy will clean up the instance, making it null-and-void for future use (it would be user error if they try to use the instance after it’s been destroyed).

After the user has created an instance, they call functions which take the instance as the first parameter. This is analogous to class member functions in C++, which implicitly take a this pointer as the first parameter.

It’s a Handle, Not a Pointer
The opaque pointer typedef is such that it hides the fact that it’s a pointer:

typedef struct ringbuffer_instance_t* ringbuffer_t;
It’s an abstract representation of the instance, often referred to as a handle.

We could just as easily define the handle as a uint32_t (maybe it’s an index into an array), and none of the using code would change:

typedef uint32_t ringbuffer_t;
Once created, the handle is passed in by value to each function. At the call site, a variable of type ringbuffer_t almost looks like a normal value, like a number:

ringbuffer_t rbuf = ringbuffer_create(10);
ringbuffer_enqueue(rbuf, 0xA5);
Using a non-pointer handle type is a stylistic choice, but I think it makes the API easier to use. When it looks like a normal value, users don’t have to use the * or & operators. Conversely, if the user sees an API that deals with pointers, there is a small bit of cognitive overhead and anxiety (questions of ownership, calling mechanics).

Encapsulation
Because the pointer is opaque, the user’s calling code cannot access the data inside the struct. Why is this a good thing?

It simplifies the API. The user does not need to know or care about internal data.
The struct definition can change without impacting any of the using code.
It prevents misuse of internal struct data.
On the topic of misuse, imagine if the user could see inside the opaque pointer. They might think they’re clever enough to manipulate read and write pointers in the ringbuffer themselves, to get some kind of custom behavior they’re looking for, but most likely, they will end up shooting themselves in the foot (maybe they forgot to account for wraparound). Furthermore, it creates hidden coupling in the system. If the ringbuffer implementation changes the way it uses read and write pointers, it will need to visit all the using code that accesses the pointers as well. In effect, the ringbuffer implementation would be spread out across multiple files in the system (good luck finding them all!) instead of being isolated to one file.

By defining the struct in ringbuffer.c, the data is “private” to that file (or more precisely, the translation unit).

What if you have a large module, spread over many .c files, that all need access to the struct? In that case, a good option is to define the struct inside of a private header file - ringbuffer_private.h in the example - which you can #include in other module files. This keeps the public interface in ringbuffer.h clean and minimal, and gives internal module files access to the private struct data.

When Should I Use This Pattern?
Opaque pointers are a good fit if you need multiple instances. They are also a good fit for general-purpose libraries, like cJSON.

If you only ever need one of something (e.g. a state machine), then the pattern can be overkill. Since there’s just one instance (in OOP, a singleton), there’s no need for handles. The opaque pointer would just be useless overhead.

In my experience, a large portion of C modules do not need multiple instances, so I use this pattern sparingly.

Once you are comfortable with the pattern, you may be tempted to apply it to every C module in the system (“We must objectify all the things!”), but this would be a mistake. APIs which don’t have opaque pointers are easier to use than ones that do, so default to not using them. The less “stuff” that’s in the header file, the better.

What If I Don’t Want to Dynamically Allocate Memory?
 - Static Ring Buffer.c & Static Ring Buffer.h
*/

#include "Ring Buffer.h"
#include <stdlib.h>

// Private struct, only accessible from within this file
struct ringbuffer_instance_t {
    volatile uint32_t wr_pos;
    volatile uint32_t rd_pos;
    uint8_t* data;
    uint32_t capacity;
};

ringbuffer_t ringbuffer_create(uint32_t capacity) {
    ringbuffer_t inst = calloc(1, sizeof(struct ringbuffer_instance_t));
    inst->data = calloc(capacity, sizeof(uint8_t));
    inst->capacity = capacity;
    inst->wr_pos = 0;
    inst->rd_pos = 0;
    return inst;
}

uint32_t ringbuffer_capacity(ringbuffer_t instance) {
    return instance->capacity;
}

bool ringbuffer_enqueue(ringbuffer_t instance, uint8_t item) {
    // implementation omitted
    return true;
}

bool ringbuffer_dequeue(ringbuffer_t instance, uint8_t* item) {
    // implementation omitted
    return true;
}

void ringbuffer_destroy(ringbuffer_t instance) {
    if (instance) {
        if (instance->data) {
            free(instance->data);
        }
        free(instance);
    }
}

int main (void) {
    // ringbuffer_create(1);
    
    return 0;
}