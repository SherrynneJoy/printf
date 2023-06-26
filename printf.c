#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - prints output according to a format
 * @format: character string
 * Return: numberofchars
 */
int _printf(const char *format, ...)
{
	va_list list;
	int i = 0, numberofchars;
	char c;

	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			switch (format[i])
			{
				case 'c':
					numberofchars += printchar(list);
					break;
				case 's':
					numberofchars += printstr(list);
					break;
				default:
					i++;
					break;
			}
		}
		else
		{
			write(1, &c, 1);
			numberofchars++;
		}
		i++;
	}
	va_end(list);
	return (numberofchars);
}
/**
 * printchar - prints characters
 * @list: list of chars
 * Return: 1
 */
int printchar(va_list list)
{
	char c = va_arg(list, int);

	write(1, &c, 1);
	return (1);
}
/**
 * printstr - prints a string
 * @list: list of chars
 * Return: 1
 */
int printstr(va_list list)
{
	char c;
	int i = 0;
	int strlength;
	char *str  = va_arg(list, char *);

	strlength = _strlen(str);

	while (i < strlength)
	{
		c = str[i];
		write(1, &c, 1);
		i++;
	}
	return (1);
}
