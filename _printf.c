#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_integer - Prints an integer
 * @list: list containing the integer to print
 * Return: Number of characters printed
 */

int print_integer(va_list list)
{
	int num = va_arg(list, int);
	int div = 1;
	int len = 0;

	if (num < 0)
	{
		len += write(1, "-", 1);
		num *= -1;
	}

	while (num / div > 0)
		div *= 10;

	while (div != 0)
	{
		len += write(1, &((num / div) + '0'), 1);
		num %= div;
		div /= 10;
	}

	return (len);
}

/**
 * print_decimal - Prints a decimal number
 * @list: list containing the decimal number to print
 * Return: Number of characters printed
 */
int print_decimal(va_list list)

{
	return (print_integer(list));
}

/**
 * print_unsigned - Prints an unsigned integer
 * @list: list containing the unsigned integer to print
 * Return: Number of characters printed
 */

int print_unsigned(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	unsigned int div = 1;
	int len = 0;

	while (num / div > 9)
		div *= 10;

	while (div != 0)
	{
		len += write(1, &((num / div) + '0'), 1);
		num %= div;
		div /= 10;
	}

	return (len);
}

/**
 * print_octal - Prints an integer in octal format
 * @list: list containing the integer to print
 * Return: Number of characters printed
 */

int print_octal(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	unsigned int octal_num = 0;
	int s = 1;

	while (num != 0)
	{
		octal_num += (num % 8) * s;
		num /= 8;
		s *= 10;
	}

	return (print_unsigned(octal_num));
}

/**
 * print_hex - Prints an integer in hexadecimal format
 * @list: list containing the integer to print
 * Return: Number of characters printed
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
				printed_chars += print_unsigned(list);
			else if (*format == 'o')
				printed_chars += print_octal(list);
			else if (*format == 'x' || *format == 'X')
				printed_chars += print_hex(list);
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
