#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - produces output according to a format
 * @format: character string containing format specifiers
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '\0')
                return (-1);
            
            if (format[i] == 'b')
            {
                count += print_binary(va_arg(args, unsigned int));
            }
            else if (format[i] == '%')
            {
                write(1, "%", 1);
                count++;
            }
            else
            {
                write(1, "%", 1);
                write(1, &format[i], 1);
                count += 2;
            }
            i++;
        }
        else
        {
            write(1, &format[i], 1);
            count++;
            i++;
        }
    }

    va_end(args);
    return (count);
}

