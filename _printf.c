#include "main.h"

/**
 * write_char - Writes a character to the standard output.
 * @c: The character to be written.
 *
 * Return: The number of characters written.
 */
int write_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * write_str - Writes a string to the standard output.
 * @str: The string to be written.
 *
 * Return: The number of characters written.
 */

int write_str(char *str)
{
	int len = 0;
	
	while (str[len] != '\0')
		len++;
	
	return (write(1, str, len));
}

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte
 * used to end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr;

	va_start(args, format);
	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%' && *(ptr + 1) != '\0')
		{
			ptr++;
			switch (*ptr)
			{
			case 'c':
				count += write_char(va_arg(args, int));
				break;
			case 's':
				count += write_str(va_arg(args, char *));
				break;
			case '%':
				count += write_char('%');
				break;
			default:
				count += write_char(*ptr);
				break;
			}
		}
		else
		{
			count += write_char(*ptr);
		}
	}
	va_end(args);
	return (count);
}
