#ifndef MAIN_H
#define MAIN_H

/* Standard Libraries */
#include <stdarg.h>
#include <unistd.h>

/* Function Declarations */
int _printf(const char *format, ...);
int print_char(char c);
int print_string(char *str);
int print_percent(void);
int print_invalid(char c);

#endif /* MAIN_H */
