#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# This Makefile contains a variety of options to build different files for this embedded systems course
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      %.i : Creates a .i file, which is an output of a .c file. -E flag is used for this.
#      %.asm : Creates a .asm file (similar to .s), which is another output of a .c file. This is an assembly language file that has operands used to carry out different operations. -S flag is used here, with an objdump utility (which can take object files and dump the associated assembly code, usually used for debugging)
#      %.o : This is the standard object file that is created using .c and .h files
#      compile-all : Compiles all the .c and .h files and outputs .o files
#      build : Compiles all the .o files and creates an executable file, c1m2.out
#      clean : Removes all non source files (this includes .i, .asm, .o, .out, etc files)
#
# Platform Overrides:
#      There are 2 platforms here - 1st is the Linux host machine. 2nd is the target MSP432 microcontroller
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
#PLATFORM = 
HOST := $ (shell uname -s)
#BUILD_OUTPUT := $(SOURCES: .c = .out)

# Architectures Specific Flags
# These info are taken from assignment 2 page
ifeq ($(PLATFORM), MSP432)
    LINKER_FILE = -T ../msp432p401r.lds
    CPU = cortex-m4
    ARCH = armv7e-m
    SPECS = nosys.specs
# Info for linux, have to use shell cmds
else #($(PLATFORM), HOST)
    #LINKER_FILE = 
    CPU := $(shell uname -p)
    ARCH = $(shell arch)
    SPECS = #use lscpu cmd for full spec
endif

$(info PLEASE REMEMBER TO SPECIFY WHICH PLATFORM YOU ARE USING)

# Compiler Flags and Defines
# Can use gcc --help and ld --help for all options
#
ifeq ($(PLATFORM), MSP432)
    CC = arm-none-eabi-gcc
    LD = arm-none-eabi-ld
    LDFLAGS = $(LINKER_FILE) -Wl -map c1m2.map
    CFLAGS = -Wall -Werror -g -O0 -std=c99 -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mthumb 
    CPPFLAGs = -E
    DFLAG = -DMSP432
endif

ifeq ($(PLATFORM), HOST)
    CC = gcc
    LD = gcc -o
    LDFLAGS = -Wl,-Map=course1.map 
    CFLAGS = -Wall -Werror -g -O0 -std=c99
    CPPFLAGs = -E
    DFLAG = -DHOST
endif



#1. Preprocessed output of c-program implementation files
%.i : %.c
	$(CC) $(CFLAGS) $(CPPFLAGs) $(DFLAG) -o $@ $<
# -E: Preprocess only; do not compile, assemble or link.


#2. Assembly output of c-program implementation files
%.asm : %.c 
	$(CC) $(CFLAGS) $(DFLAG) -S $<
	@echo IF BUILD FAILS, RUN ""make main.o"" TO CREATE OBJ FILE FIRST
	objdump main.o -d


#3. Generate object file for all c-source files with no link
%.o : %.c
	$(CC) $(CFLAGS) $(DFLAG) -c -o $@ $<


#4. Compile (and assemble) all but do not link
.PHONY: compile-all
compile-all : $(SOURCES)
	$(CC) $(CFLAGS) $(DFLAG) -c $(SOURCES)


#5. Compile all and link to final exe
.PHONY: build
build : $(SOURCES)
	$(LD) $(CFLAGS) $(DFLAG) $(LDFLAGS) -o c1m2.out $^
	size c1m2.out

#6. Clean
.PHONY: clean
clean :
	rm -f *.i *.out *.o *.d *.map *.s


#7. Generate output file for all c-source files with no link
%.out : %.c
	#$(CC) $(CFLAGS) -c -o $@ $<
	$(CC) $(DFLAG) $(CFLAGS) $(LDFLAGS) -o course1.out $^ -lm



