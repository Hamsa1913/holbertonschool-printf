#include "main.h"
#include <unistd.h>

/**
 * print_binary - converts unsigned int to binary and prints it
 * @num: number to convert
 * Return: number of characters printed
 */
int print_binary(unsigned int num)
{
    char buffer[32];
    int i = 0, count = 0;

    if (num == 0)
    {
        write(1, "0", 1);
        return (1);
    }

    while (num > 0)
    {
        buffer[i] = (num % 2) + '0';
        num /= 2;
        i++;
    }

    count = i;
    while (i > 0)
    {
        write(1, &buffer[i - 1], 1);
        i--;
    }

    return (count);
}

