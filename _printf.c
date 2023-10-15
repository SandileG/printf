#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: format string
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list list;
	va_start(list, format);

	if (format == NULL)
		return -1;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(list, int);
				write(1, &c, 1);
				printed_chars++;
			}
			else if (*format == 's')
			{
			char *str = va_arg(list, char *);
			int i = 0;
			while (str[i] != '\0')
			{
				write(1, &str[i], 1);
					i++;
				printed_chars++;
			}
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				printed_chars++;
			}
			else
			{
				write(1, "%", 1);
				write(1, format, 1);
				printed_chars += 2;
			}
			}
			else
			{
				write(1, format, 1);
				printed_chars++;
			}
			format++;
	}

	va_end(list);
	return printed_chars;
}
