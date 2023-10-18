#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_hex_address - Prints an address in hexadecimal format
 * @address: The memory address to print
 * @specifier: The format specifier to determine the case of the letters
 */

void print_hex_address(uintptr_t address, char specifier)
{
	if (address)
	{
		unsigned int hex_digits[16];
		int i = 0;

		while (address)
		{
			hex_digits[i] = address % 16;
			address /= 16;
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
	}
}
