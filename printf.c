#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * printchar - prints characters
 * @list: list of chars
 * Return: char
 */
int printchar(va_list list)
{
	char c = va_arg(list, int);

	return (_putchar(c));
}
/**
 * printstr - prints a string
 * @list: list of chars
 * Return: n
 */
int printstr(va_list list)
{
	char c;
	int n = 0;
	char *str;

	str  = va_arg(list, char *);
	while (*str != '\0')
	{
		c = *str;
		n += _putchar(c);
		str++;
	}
	return (n);
}
/**
 * print_format - prints different formats
 * @list: list of formats
 * @format: format to be printed
 * Return: 0
 */
int print_format(va_list list, char format)
{
	switch (format)
	{
		case 'c':
			return (printchar(list));
		case 's':
			return (printstr(list));
	}
	return (0);
}
/**
 * _printf - prints output according to a format
 * @format: character string
 * Return: numberofchars
 */
int _printf(const char *format, ...)
{
	va_list list;
	int i = 0, numberofchars = 0;

	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' || format[i] != '\0')
		{
			numberofchars += print_format(list, *format);
		}
		else
		{
			numberofchars += _putchar(*format);
		}
		i++;
	}
	va_end(list);
	return (numberofchars);
}
