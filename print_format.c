#include "main.h"

/**
 * print_format - Prints the format string
 * @format: Format string
 * @list: List of arguments
 * Return: Number of characters printed
 */

int print_format(const char *format, va_list list)
{
	int printed_chars = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			printed_chars += process_specifier(format, list);
		}
		else
		{
			write(1, format, 1);
			printed_chars++;
		}
		format++;
	}
	return (printed_chars);
}
