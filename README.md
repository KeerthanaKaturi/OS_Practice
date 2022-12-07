# Embedded Operating Systems
## Day1
- General Purpose System
- Embedded Systems
    - Specific or dedicated functionality
- System
    - Hardware
        - CPU
            - PC/IP
            - flags
            - Stack pointer
            - General purpose registers
        - Memory
        - I/O
    - Algorithms
        - Instructions
        - Data
    - RISC/CICS processors architecture
    - Processors
        - Microprocessors
        - Microcontrollers(all in one silicon)
            - CPU
            - Memory
            - I/O
- Basic GIT commands
    ``` bash
    git init
    git add *
    git commit -m "message"
    git log
    git config user.name "keerthanakaturi"
    git config user.email "keerthanakaturi@gmail.com"
    git status
    ```
- Writing makefiles and libraries
    - Basic commands in makefile

    ```bash
        CC=gcc
        main: main.o add.o sub.o
	    $(CC) -o main main.o add.o sub.o
        main.o: main.c
	    $(CC) -c -o main.o main.c
        clean:
	    rm -rf main.o add.o sub.o main
        linking library file
        $(CC) -o main main.o add.o sub.o -larith1 -L.
        creating library file
        ar crv libarith.a add.o sub.o
    ```
## Day2
- Conditional compilation will not work in makefile because "#" will be treated as a comment.

    ```bash
        #ifdef(x86)
        CC=gcc
        #elif(arm)
        CC=arm-linux-gnueabi-gcc
        #endif
    ```
    - Stack, Stack pointer, Stack frame
    - Stack frame
        - Return address
        - arguments
        - local  variables
    - How are arguments passed to function
        - Registers or stack
        - ARM
            - => Args => R0-R3
            - => morethan 4 args => stack
    - Frame pointer
        - It is used to access args and local variables
        - Every stack frame is having different frame pointer
    - Sections
        - .text => Instructions
        - .data => initialized global variables
        - .bss => uninitialized global variables
        - stack => local variables, function arguments and return addresses
        - heap => dynamic memory allocation
    - Program
        - Dormant entity
        - recites in hard disk/secondary memory
    - Process
        - Active entity
        - Program under execution
        - Allocates memory suitable and executes instructions and PC is pointed to the start of .text section
        - Every process has a unique ID (process ID(PID))
        - getpid() function is used to hold the process ID
        - in linux every process is done like tree hierarchy
        - getppid() function is used to hold parent ID(usually the bash which is nothing but the terminal)


