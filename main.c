#include "main.h"

int main(void)
{
    unsigned int ui;
    ui = 2147484671;
    _printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);

    return (0);
}

