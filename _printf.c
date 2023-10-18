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

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				printed_chars += print_char(va_arg(list, int));
			else if (*format == 's')
				printed_chars += print_string(va_arg(list, char *));
			else if (*format == '%')
				printed_chars += print_percent();
			else if (*format == 'd' || *format == 'i')
				printed_chars += print_integer(list);
			else if (*format == 'u')
				printed_chars += print_unsigned_number(list);
			else if (*format == 'o')
				printed_chars += print_octal(list);
			else if (*format == 'x' || *format == 'X')
				printed_chars += print_hex(list);
			else if (*format == 'b')
				printed_chars += print_binary(list);
			else
				printed_chars += print_invalid(*format);
		}
		else
		{
			write(1, format, 1);
			printed_chars++;
		}
		format++;
	}

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
 * print_string - Prints a string
 * @str: String to print
 * Return: Number of characters printed
 */
int print_string(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
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
