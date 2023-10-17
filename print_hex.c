#include "main.h"

/**
 * print_hex - Prints an integer in hexadecimal format.
 * @list: list containing the integer to print.
 * Return: Number of characters printed.
 */

int print_hex(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	unsigned int temp;
	char hex[100];
	int h = 0;
	int len = 0;

	while (num != 0)
	{
		temp = 0;
		temp = num % 16;
		if (temp < 10)
		{
			hex[h] = temp + 48;
			h++;
		}
		else
		{
			hex[h] = temp + 55;
			h++;
		}
		num = num / 16;
	}

	while (h > 0)
	{
		len += write(1, &hex[h - 1], 1);
		h--;
	}
	return (len);
}
