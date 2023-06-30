#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdarg.h>

/**
 * struct myfunc - structure for format
 * @p: pointer to char/string
 * @f: function pointer
 */
typedef struct myfunc
{
	char *p;
	int (*f)(va_list);
} fmt_t;

int _printf(const char *format, ...);
int _printstr(va_list list);
int _printchar(va_list list);
int _putchar(char c);
int base_fn(size_t unsignedlong, int base);
int _printdecimal(va_list list, char format);
int _printint(va_list list, int base);
/*size_t _strlen(const char *str);*/
#endif /*MAIN_H*/
