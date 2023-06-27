#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stddef.h>

int _printf(const char *format, ...);
int print_format(va_list args, char format);
int printStr(va_list args);
int printChar(va_list args);
int _putchar(char c);

#endif
