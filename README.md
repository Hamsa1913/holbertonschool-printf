Custom printf- Project Overview

This project focuses on creating a simplified custom implementation of the C standard library function printf.
The main objective is to understand how formatted output works internally - how the format string is parsed, how variadic arguments are processed, and how each specifier is handled manually using low-level system calls.

Our _printf currently supports the following conversion specifiers:

%c - prints a single character

%s - prints a string

%% - prints a literal percent sign

%d - prints a signed integer

%i - prints a signed integer

The function loops through each character in the format string, checks if it encounters a %, and then calls the correct helper function depending on the specifier detected.
No buffers and no global variables are used -  only the write() system call and standard C variadic macros.

Authors:

Hamsa Alammar

Project Files Overview
1 -main.h

The header file that contains:

Function prototypes:

_printf

print_char

print_string

print_percent

print_int

Required libraries (stdarg.h, unistd.h)

Include guards

This file links all .c files together.

2 - _printf.c

This is the core engine of the project.
It handles:

Reading and parsing the format string

Detecting conversion specifiers

Calling the appropriate helper function (%c, %s, %i, %d, %%)

Tracking and returning the total printed characters

It uses:

va_list

va_start

va_arg

va_end

3 - functions.c

Contains the helper functions for:

%c - print_char

%s - print_string

%% - print_percent

Each helper is responsible for printing one type only, which keeps the code modular.

4 - print_int.c

This file contains the integer-printing logic for %d and %i.
It handles:

Positive integers

Negative integers

Printing digit by digit

Counting characters printed

5 - man_3_printf

A manual page that explains:

What _printf does

Supported format specifiers

Return value

Usage instructions

Mimics the style of the official printf(3) man page.

6- README.md

This documentation file (the one you are reading) explains:

The purpose of the project

The file structure

How _printf works

Supported specifiers

Compilation

Usage examples
Summary

This project teaches:

Variadic functions

Manual formatted output

Integer-to-string logic

Modular C design

Working with strict coding rules (Betty, no globals, no more than 5 funcs/file)

Designing documentation (man and README)

Git workflow in team projects

It is a foundational low-level programming project that builds understanding for how real system functions like printf work internally.
