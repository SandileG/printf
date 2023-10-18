#ifndef MAIN_H
#define MAIN_H

/* Standard Libraries */
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/* Function Declarations */
int _printf(const char *format, ...);
int print_char(char c);
int print_string(char *str);
int print_percent(void);
int print_invalid(char c);
int print_integer(va_list list);
int print_decimal(va_list list);
int print_unsigned_number(va_list list);
int print_octal(va_list list);
int print_hex(va_list list);
int print_binary(va_list list);

#endif /* MAIN_H */
