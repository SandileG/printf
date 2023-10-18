#include "main.h"

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
