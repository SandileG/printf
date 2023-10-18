#include "main.h"

/**
 * print_binary - Prints an unsigned integer in binary format.
 * @list: A va_list containing the unsigned integer to print.
 *
 * Return: The number of characters printed.
 */

int print_binary(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	int binary_digits[32];
	int s = 0, printed_chars = 0;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (num > 0)
	{
		binary_digits[s] = num % 2;
		num /= 2;
		s++;
	}

	for (s -= 1; s >= 0; s--)
	{
		char digit = binary_digits[s] + '0';

		write(1, &digit, 1);
		printed_chars++;
	}

	return (printed_chars);
}
