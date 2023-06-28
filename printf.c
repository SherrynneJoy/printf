#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * printChar - prints a char
 * @args: prints variable arguments
 * Return: 0 when it evaluates
 */

int printChar(va_list args)
{
	char c;

	c = va_arg(args, int);
	return (_putchar(c));
}

/**
 * printStr - prints a string
 * @args: prints the next variable argument
 * Return: nothing
 */

int printStr(va_list args)
{
	char c, *str;
	int n = 0;

	str = va_arg(args, char *);
	while (*str != '\0')
	{
		c = *str;
		n = n + _putchar(c);
		str++;
	}
	return (n);
}

/**
 * print_format - prints output of any format
 * @format: a character string
 * @args: a variable number of arguments
 * Return: 0 when it evaluates
 */

int print_format(va_list args, char format)
{
	switch (format)
	{
		case 'c':
			return (printChar(args));
		case 's':
			return (printStr(args));
		case 'd':
			return (print_decimal(args, format));
		case 'i':
			return (print_integer(args, format));
	}
	return (0);
}

/**
 * _printf - prints output
 * @format: a string pointer
 * Return: 0 when successful
 */

int _printf(const char *format, ...)
{
	int numberofchars = 0;
	va_list args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%' && *(++format) != '\0')
		numberofchars += print_format(args, *format);
		else
			numberofchars += _putchar(*format);
		if (*format != '\0')
			format++;
	}
	va_end(args);
	return (numberofchars);
}
