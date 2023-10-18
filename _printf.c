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

/**
 * process_specifier - Processes the specifier character
 * @format: Format string
 * @list: List of arguments
 * Return: Number of characters printed
 */

int process_specifier(const char *format, va_list list)
{
	int printed_chars = 0;
	char specifier = *format;

	if (specifier == 'c')
		printed_chars += print_char(va_arg(list, int));
	else if (specifier == 's')
		printed_chars += print_string(va_arg(list, char *));
	else if (specifier == '%')
		printed_chars += print_percent();
	else if (specifier == 'd' || specifier == 'i')
		printed_chars += print_integer(list);
	else if (specifier == 'u')
		printed_chars += print_unsigned_number(list);
	else if (specifier == 'o')
		printed_chars += print_octal(list);
	else if (specifier == 'x' || specifier == 'X')
		printed_chars += print_hex(list, specifier);
	else if (specifier == 'b')
		printed_chars += print_binary(list);
	else
		printed_chars += print_invalid(*format);
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
