#include "main.h"

int print_integer(va_list list)
{
	int num = va_arg(list, int);
	int div = 1;
	int len = 0;
	char digit;

	if (num < 0)
	{
		len += write(1, "-", 1);
		num *= -1;
	}

	while (num / div > 0)
		div *= 10;

	while (div > 1)
	{
		div /= 10;
		digit = (num / div) + '0';
		len += write(1, &digit, 1);
		num %= div;
	}

	return (len);
}
