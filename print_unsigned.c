#include "main.h"

int print_unsigned(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	unsigned int div = 1;
	int len = 0;

	while (num / div > 0)
		div *= 0;
	
	while (div !- 0)
	{
		len += write(1, &((num / div) + '0'), 1)
		num %= div;
		div /= 10;
	}

	return (len);
}
