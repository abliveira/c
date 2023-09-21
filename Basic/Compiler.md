## gcc

gcc is the GNU C compiler; its proper name is the GNU Compiler Collection
g++ is the C++ compiler; it can also be invoked as c++
gcc works closely with the GNU libc, glibc, and the debugger, gdb
Virtually every operating system you can think of has a version of gcc, and it can be used for cross-compilation on different architectures

### Compiling Stages

Invoking gcc actually entails a number of different programs or stages, each of which has its own man page, and can be independently and directly invoked; these are:

|Stage  |Command  |Default Input  |Default Output  |W Switch  |
|---------|---------|---------|---------|---------|
|Preprocessing     |cpp         |.c         |.i         |-Wp....         |
|Compilation     |gcc         |.i         |.s         |N/A         |
|Assembly     |as         |.a         |.o         |-Wa....         |
|Linking     |ld         |.o         |a.out         |-Wl....         |

Depending on your Linux distribution, details about the gcc installation and defaultscan be found in the /usr/lib/gcc, /usr/lib64/gcc and/or /usr/libexec/gcc directories

### gcc Options

The compiled code format will be ELF (Executable and Linkable Format), which makes using shared libraries easy

**Compiler Path Options**

|Option  |Description  |
|---------|---------|
|-I dir     |Include dir in search for included files; cumulative         |
|-L dir     |Search dir for libraries; cumulative         |
|-l     |Link to lib; -lfoo links to libfoo.so if it exists, or to libfoo.a as a second choice         |

**Compiler Preprocessor Options**

|Option  |Description  |
|---------|---------|
|-M     |Do not compile; give dependencies for make         |
|-H     |Print out names of included files         |
|-E     |Preprocess only         |
|-D def     |Define def         |
|-U def     |Undefine def         |
|-d     |Print #defines         |

**Compiler Warning Options**

|Option  |Description  |
|---------|---------|
|-v     |Verbose mode, gives version number         |
|-pedantic     |Warn very verbosely         |
|-w     |Suppress warnings         |
|-W     |More verbose warnings         |
|-Wall     |Enable a bunch of important warnings         |

**Compiler Debugging and Profiling Options**

|Option  |Description  |
|---------|---------|
|-g     |Include debugging information         |
|-pg     |Provide profile information for gprof         |

**Compiler Input and Output Options**

|Option  |Description  |
|---------|---------|
|-c     |Stop after creating object files, do not link         |
|-o file     |Output is file ; default is a.out         |
|-x lang     |Expect input to be in lang, which can be c, objective-c, c++ (and some others); otherwise, guess by input file extension         |

**Compiler Control Options**

|Option  |Description  |
|---------|---------|
|-ansi     |Enforce full ANSI compliance         |
|-pipe     |Use pipes between stages         |
|-static     |Suppress linking with shared libraries         |
|-O[lev]     |Optimization level; 0, 1, 2, 3; default is 0         |
|-Os     |Optimize for size; use all -O2 options except those that increase the size         |

### Static Libraries

Static libraries have the extension .a. When a program is compiled, full copies of any loaded library routines are incorporated as part of the executable.

### Shared Libraries

A single copy of a shared library can be used by many applications at once; thus, both executable sizes and application load time are reduced.

Shared libraries have the extension .so. Typically, the full name is something like libc.so.N where N is a major version number.

## Para ler:
https://embarcados.com.br/gnu-cross-toolchain-processo-de-build/
https://cets.seas.upenn.edu/answers/gcc.html
https://embarcados.com.br/cross-compiling-com-a-raspberry-pi/
https://dnedic.github.io/blog/the-most-thoroughly-commented-embedded-cmakelists/
https://gist.github.com/mbinna/c61dbb39bca0e4fb7d1f73b0d66a4fd1