#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stddef.h>
/**
 * struct my_func - a structure
 * @p: pointer to a string
 * @f: a function pointer
 */
typedef struct my_func
{
	char *p;
	int (*f)(va_list);
} fmt_t;
int _printf(const char *format, ...);
int printStr(va_list args);
int printChar(va_list args);
int _putchar(char c);
int check_specifier(const char *format, va_list args,
		fmt_t *fmt);
int is_digit(char c);

#endif
