#ifndef MAIN_H
#define MAIN_H

/* Standard Libraries */
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

/* Function Declarations */
int _printf(const char *format, ...);
int print_format(const char *format, va_list list);
int process_specifier(const char *format, va_list list);
int print_char(char c);
int print_string(char *str);
int print_percent(void);
int print_invalid(char c);
int print_integer(va_list list);
int print_decimal(va_list list);
int print_unsigned_number(va_list list);
int print_octal(va_list list);
int print_hex(va_list list, char specifier);
int print_binary(va_list list);
void print_hex_address(uintptr_t address, char specifier);


#endif /* MAIN_H */
