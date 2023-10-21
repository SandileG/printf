#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _printf - Custom printf function
 * @format: format string
 * Return: the number of characters printed (excluding the null byte)
 */

int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);
	printed_chars = print_format(format, list);
	va_end(list);
	return (printed_chars);
}

/**
 * print_char - Prints a character
 * @c: Character to print
 * Return: Number of characters printed
 */
int print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * print_string - Prints a string.
 * @str: String to print.
 * Return: Number of characters printed.
 */
int print_string(char *str)
{
	int h = 0;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}

	while (str[h] != '\0')
	{
		write(1, &str[h], 1);
		h++;
	}
	return (h);
}

/**
 * print_percent - Prints a percent sign
 * Return: Number of characters printed
 */
int print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

/**
 * print_invalid - Prints an invalid specifier
 * @c: Invalid specifier
 * Return: Number of characters printed
 */
int print_invalid(char c)
{
	write(1, "%", 1);
	write(1, &c, 1);
	return (2);
}
