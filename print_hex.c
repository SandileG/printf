#include "main.h"

/**
 * print_hex - Prints an unsigned integer in hexadecimal format.
 * @list: A va_list containing the unsigned integer to print.
 * @specifier: Specifier to determine whether the output should be
 * lowercase or uppercase.
 *
 * Return: The number of characters printed.
 */

int print_hex(va_list list, char specifier)
{
	unsigned int num = va_arg(list, unsigned int);
	char hex_digits[32];
	int i = 0;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (num != 0)
	{
		int temp = 0;

		temp = num % 16;

		if (temp < 10)
			hex_digits[i] = temp + '0';
		else
		{
			if (specifier == 'x')
				hex_digits[i] = temp - 10 + 'a';
			else if (specifier == 'X')
				hex_digits[i] = temp - 10 + 'A';
		}
		num /= 16;
		i++;
	}

	for (i -= 1; i >= 0; i--)
	{
		write(1, &hex_digits[i], 1);
	}

	return (i);
}
