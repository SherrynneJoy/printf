#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdarg.h>

int _printf(const char *format, ...);
size_t _strlen(const char *str);
int printstr(va_list list);
int printchar(va_list list);
int _putchar(char c);
int base_fn(size_t unsignedlong, int base);
int printdecimal(va_list list, char format);
int printint(va_list list, int base);
/*int main(void);*/
#endif
