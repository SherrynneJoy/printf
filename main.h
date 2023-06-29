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
/*size_t _strlen(const char *str);*/
int _printstr(va_list list);
int _printchar(va_list list);
int _putchar(char c);
/*int base_fn(size_t unsignedlong, int base);*/
/*int printdecimal(va_list list, char format);*/
/*int printint(va_list list, int base);*/
#endif /*MAIN_H*/
