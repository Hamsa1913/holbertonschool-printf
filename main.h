#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* main printf function */
int _printf(const char *format, ...);

/* helper functions */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(void);

#endif /* MAIN_H */

