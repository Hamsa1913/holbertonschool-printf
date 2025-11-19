#include "main.h"

/**
 * print_int - prints an integer
 * @args: argument list
 *
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	long int n = va_arg(args, int);
	long int num = n;
	int digit, count = 0;
	char c;
	long int divisor = 1;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	/* Handle negative numbers */
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		num = -num;
	}

	/* Find highest divisor */
	while ((num / divisor) > 9)
		divisor *= 10;

	/* Print digits */
	while (divisor > 0)
	{
		digit = (num / divisor) % 10;
		c = digit + '0';
		write(1, &c, 1);
		count++;
		divisor /= 10;
	}

	return (count);
}

