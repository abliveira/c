Ler:
https://barrgroup.com/embedded-systems/how-to/malloc-free-dynamic-memory-allocation
http://www.embeddedlinux.org.cn/rtconforembsys/5107final/LiB0080.html

Referencias
https://embeddedcomputing.com/technology/software-and-os/ides-application-programming/dynamic-memory-allocation-just-say-no

Increasingly, embedded software developers are realizing that dynamic memory allocation – grabbing chunks of memory as and when needed and relinquishing them later – while convenient and flexible, is fraught with problems. The issues are not confined to embedded code, many desktop applications exhibit memory leaks that impact performance and reliability. But here I want to focus on embedded.

There are three key reasons to question the use of the standard malloc() library function:

Memory allocation can fail. This may be because there is insufficient memory available (in the heap) to fulfill the request. It may also be caused by fragmentation; there is enough memory available, but no contiguous chunks are is large enough.
The function is commonly not reentrant. In a multi-threaded (multi-task) system, functions must be reentrant, if they are called by more than one task. This ensures that, if the call is interrupted, another call to the function will not compromise the first one.
It is not deterministic. In a real-time system, predictability (determinism) is critical. The standard malloc() function’s execution time is extremely variable and impossible to predict.


These are all valid points and there are ways to address them, which are generally a matter of using the provided functionality of a real-time operating system (RTOS).

However, despite their validity, the problems may not always be as significant as they seem:

The function returns a NULL pointer if allocation failure occurs. This is easy to check, and action may be taken.
In many applications, all memory allocation and deallocation is performed in a single task. This renders reentrancy unnecessary.
Not all embedded systems are real time, so determinism may not be required.
Another challenge may be presented by malloc(): it is rather slow. Some systems need speed, rather than predictability, so finding a way to provide this function’s capabilities, with greater performance, needs to be considered.

The primary reason for the function’s lackluster performance is that it provides a lot of functionality. The management of memory chunks of varying size is quite complex. For many applications, this is actually overkill, as required memory allocations are all the same size (or a small number of different, known sizes). It would be quite straightforward to write a memory allocator for fixed-size blocks; just an array with usage flags or maybe a linked list. The code would definitely be faster and could even be done deterministically. Allocation failure could still occur but is straightforward to manage. This type of memory allocation is commonly provided by popular RTOS products.

There are a number of reasons not to use malloc (or equivalent) in an embedded system.

- As you mentioned, it is important that you do not suddenly find yourself out of memory.
- Fragmentation - embedded systems can run for years which can cause a severe waste of memory due to fragmentation.
Not really required. Dynamic memory allocation allows you to reuse the same memory to do different things at different times. Embedded systems tend to do the same thing all the time (except at startup).
- Speed. Dynamic memory allocation is either relatively slow (and gets slower as the memory gets fragmented) or is fairly wasteful (e.g. buddy system).
If you are going to use the same dynamic memory for different threads and interrupts then allocation/freeing routines need to perform locking which can cause problems servicing interrupts fast enough.
- Dynamic memory allocation makes it very difficult to debug, especially with some of the limited/primitive debug tools available on embedded system. If you statically allocate stuff then you know where stuff is all the time which means it is much easier to inspect the state of something.
- Best of all - if you do not dynamically allocate memory then you can't get memory leaks.

However, many embedded systems are also Real Time systems. If your application has hard deadlines for how long it can take to run, you will have trouble with dynamic allocations. Most heap implementations use algorithims that don't have a very well-bounded runtime. In some (perhaps rare) instances, they will take waaaay longer to run than normal. There are some real-time heap implementations, but they aren't in very wide use. The general rule is to avoid any dynamic allocation or deallocation in a hard real-time system after initialization.

Traditionally, embedded devices had microcontrollers on them and generally no operating system. No protected memory, and were single threaded. You would have to be extremely careful with malloced memory because it's so easy to run out of it when you've only got 32KB of it available for example. So generally, we'd write our code with fixed sized buffers (Static Ring Buffer.c) and never use malloc or at if it was every used - very sparingly.

Statically allocated variables and arrays are much faster to allocate and deallocate, and can be faster to access, than dynamically allocated data

Memory leaks are a massive problem on embedded systems, which can sometimes be expected to run for years. Avoiding dynamic allocation is prudent from this perspective.

Embedded devices usually have fairly dependable specifications. You know what the transfer rate is, you know how fast you can deal with information, and so on. In your example, the solution is to use a fixed-size buffer as a circular queue. Make the buffer large enough to handle what your device needs to be capable of handling (and perhaps a tiny bit more). If too much data arrives, it's probably due to a fault or interference somewhere else anyway so there's not much point holding and trying to use all that data.


### Arrays vs Dynamic Allocation

Arrays are faster than dynamic memory allocation.

Arrays are "allocated" at "compile time" whereas malloc allocates at run time. Allocating takes time.

Also, C does not mandate that malloc() and friends are available in free-standing implementations.

Obs: Opaque Pointer.c

```c
Example of array

#define DECK_SIZE 52
int main(void) {
    int deck[DECK_SIZE];
    play(deck, DECK_SIZE);
    return 0;
}
Example of malloc()

int main(void) {
    size_t len = 52;
    int *deck = malloc(len * sizeof *deck);
    if (deck) {
        play(deck, len);
    }
    free(deck);
    return 0;
}

```

In the array version, the space for the deck array was reserved by the compiler when the program was created (but, of course, the memory is only reserved/occupied when the program is being run), in the malloc() version, space for the deck array has to be requested at every run of the program.

Arrays can never change size, malloc'd memory can grow when needed.

If you only need a fixed number of elements, use an array (within the limits of your implementation). If you need memory that can grow or shrink during the running of the program, use malloc() and friends.