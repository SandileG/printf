#include "main.h"


/**
 * main - Entry point.
 *
 * Description: Tests the _printf function with various format specifiers.
 *
 * Return: Always 0.
 */

int main(void)
{
	int len;

	len = _printf("Thanos had to die a really painful death in the end!\n");
	_printf("Steve Rpgers:[%d]\n", len);
	_printf("Hulk:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am Thor, son of ODIN!");
	_printf("Percent:[%%]\n");

	return (0);
}
