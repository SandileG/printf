#include "main.h"

/**
 * print_address - Prints the memory address
 * @list: List of arguments
 */
void print_address(va_list list)
{
	void *ptr = va_arg(list, void *);
	uintptr_t address = (uintptr_t)ptr;

	if (!address)
	{
		write(1, "(nil)", 5);
		return;
	}

	write(1, "0x", 2);
	print_hex_address(address, 'x');
}
