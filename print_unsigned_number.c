#include "main.h"
#include <stdlib.h>

/**
 * print_unsigned_number - Prints an unsigned integer.
 * @list: A va_list containing the unsigned integer to print.
 * Return: The number of characters printed.
 */

int print_unsigned_number(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	unsigned int temp = num;
	int digits = 0;
	char *buffer;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (temp != 0)
	{
		temp /= 10;
		digits++;
	}

	buffer = malloc(sizeof(char) * (digits + 1));
	if (buffer == NULL)
		return (-1);

	buffer[digits] = '\0';

	while (digits)
	{
		digits--;
		buffer[digits] = num % 10 + '0';
		num /= 10;
	}

	for (digits = 0; buffer[digits]; digits++)
		write(1, &buffer[digits], 1);

	free(buffer);
	return (digits);
}
