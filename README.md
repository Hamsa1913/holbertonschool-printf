Custom printf  Project Overview

This project focuses on creating a simplified custom implementation of the C standard library function printf.
The main objective is to understand how formatted output works internally how the format string is parsed, how variadic arguments are processed, and how each specifier is handled manually using low-level system calls.

Our _printf currently supports the following conversion specifiers:

%c - prints a single character

%s - prints a string

%% - prints a literal percent sign

(Additional specifiers such as %d / %i for signed integers can be added later in future tasks.)

The function loops through each character in the format string, checks if it encounters a %, and then calls the correct helper function depending on the specifier detected.
No buffers and no global variables are used - only the write() system call and C variadic macros.

Authors:

Hamsa Alammar

Abdulrahman Alqadhibi

Project Files Overview
1 - main.h

This header file contains:

All required function prototypes:

_printf

print_char

print_string

print_percent

All needed includes (<stdarg.h>, <unistd.h>)

Include guards to prevent double inclusion

This file links all .c files together and ensures modular compilation.

2 - _printf.c

This is the core engine of the project.

It is responsible for:

Reading the format string character by character

Detecting when a format specifier starts (%)

Calling the correct helper function based on the specifier

Using variadic macros:

va_list

va_start

va_arg

va_end

Returning the total count of printed characters

The file contains only the main _printf function, keeping the project clean and respecting the limit of no more than 5 functions per file.

3 - functions.c

This file contains the helper functions that handle each supported specifier:

print_char - handles %c

print_string - handles %s

print_percent - handles %%

Each helper is focused on a single task, which keeps the code modular and aligned with project structure guidelines.

4- man_3_printf

This manual page describes:

What _printf does

The supported format specifiers

The function prototype

How to use it

The return value behavior

It mimics the style of the official printf(3) manual page.

5- README.md

This documentation file (the one you are reading) explains:

The purpose of the entire project

How _printf works internally

What files exist and what each one does

Compilation instructions

Usage examples 

Summary

This project teaches:

How variadic functions work (va_list, va_start, va_arg, va_end)

How to manually implement formatted output

How to design modular C programs using multiple files

How to respect system-level constraints:

No global variables

No more than 5 functions per file

Manual man page

Strict Betty coding style

How to collaborate within a shared GitHub repository and maintain clean commit history

It is a foundational project for understanding low-level programming, system design, and how the real printf function behaves internally.
