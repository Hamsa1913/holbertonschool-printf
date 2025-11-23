#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/**
 * print_binary - converts unsigned int to binary
 * @num: number to convert to binary
 * Return: number of characters printed
 */
int print_binary(unsigned int num)
{
	char binary[32];
	int i = 0, len = 0;

	if (num == 0)
		return (write(1, "0", 1));

	while (num > 0)
	{
		binary[i++] = (num % 2) + '0';
		num /= 2;
	}

	len = i;
	while (i > 0)
		write(1, &binary[--i], 1);

	return (len);
}

/**
 * handle_binary - handles %b specifier for different types
 * @args: arguments list
 * Return: number of characters printed
 */
int handle_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	return (print_binary(num));
}

/**
 * _printf - produces output according to a format
 * @format: format string containing conversion specifiers
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return (-1);

			if (format[i] == 'b')
				count += handle_binary(args);
			else if (format[i] == '%')
				count += write(1, "%", 1);
			else
			{
				count += write(1, "%", 1);
				count += write(1, &format[i], 1);
			}
			i++;
		}
		else
			count += write(1, &format[i++], 1);
	}

	va_end(args);
	return (count);
}
