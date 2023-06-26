#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdarg.h>

int _printf(const char *format, ...);
size_t _strlen(const char *str);
int printstr(va_list list);
int printchar(va_list list);
#endif
