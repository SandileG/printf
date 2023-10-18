#include "main.h"
#include <stdlib.h>

/**
 * print_unsigned_number - Prints an unsigned integer.
 * @list: A va_list containing the unsigned integer to print.
 * Return: The number of characters printed.
 */

/**
 * print_udigits - Prints unsigned integers
 * @num: Unsigned integer to be printed
 *
 * Description: This function prints the digits of an unsigned integer
 * in their decimal representation.
 */

void print_udigits(unsigned int num)
{

	char digit;

	if (num == 0)
		return;

	print_udigits(num / 10);
	digit = (num % 10) + '0';
	write(1, &digit, 1);
}

int print_unsigned_number(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	unsigned int num_copy = num;
	int digits = 0;

	if (num == 0)
    	{
		write(1, "0", 1);
		return (1);
	}

	while (num_copy != 0)
	{
		num_copy /= 10;
		digits++;
	}

	print_udigits(num);

	return (digits);
}
