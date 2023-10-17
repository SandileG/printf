#include "main.h"

/**
 * print_octal - Prints an integer in octal format.
 * @list: list containing the integer to print.
 * Return: Number of characters printed.
 */

int print_octal(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	unsigned int octal_num = 0;
	int s = 1;

	while (num != 0)
	{
		octal_num += (num % 8) * s;
		num /= 8;
		s *= 10;
	}

	return (print_unsigned_number(octal_num));
}
