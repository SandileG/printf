#include "main.h"

/**
 * print_octal - Prints an integer in octal format.
 * @list: A va_list containing the integer to print
 *
 * Return: The number of characters printed
 */

int print_octal(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	unsigned int temp = num;
	int octal_digits = 0;
	char *octal;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (temp != 0)
	{
		temp /= 8;
		octal_digits++;
	}

	octal = malloc(sizeof(char) * (octal_digits + 1));
	if (octal == NULL)
		return (-1);

	octal[octal_digits] = '\0';

	while (octal_digits)
	{
		octal_digits--;
		octal[octal_digits] = num % 8 + '0';
		num /= 8;
	}

	for (octal_digits = 0; octal[octal_digits]; octal_digits++)
		write(1, &octal[octal_digits], 1);

	free(octal);
	return (octal_digits);
}
