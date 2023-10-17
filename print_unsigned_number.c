/**
 * print_unsigned_number - Prints an unsigned integer
 * @list: A va_list containing the unsigned integer to print
 *
 * Return: The number of characters printed
 */

#include "main.h"

int print_unsigned_number(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	unsigned int div = 1;
	int len = 0;

	while (num / div > 0)
		div *= 10;

	while (div != 0)
	{
		len += write(1, (num / div) + '0', 1);
		num %= div;
		div /= 10;
	}

	return (len);
}
