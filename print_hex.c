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
	int hex_digits[32];
	int i = 0;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	
	while (num != 0)
	{
		hex_digits[i] = num % 16;
		num /= 16;
		i++;
	}

	for (i -= 1; i >= 0; i--)
	{
		if (hex_digits[i] < 10)
			write(1, &hex_digits[i] + '0', 1);
		else
		{
			if (specifier == 'x')
				write(1, &hex_digits[i] - 10 + 'a', 1);
			else if (specifier == 'X')
				write(1, &hex_digits[i] - 10 + 'A', 1);
		}
	}

	return (i);
}
