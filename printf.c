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
	write(1, &c, 1);
	return (1);
}

/**
 * printStr - prints a string
 * @args: prints the next variable argument
 * Return: nothing
 */

int printStr(va_list args)
{
	char c, *str;
	unsigned int i;
	unsigned int length;

	str = va_arg(args, char *);
	length = _strlen(str);

	while (i < length)
	{
		c = str[i];
		write(1, &c, 1);
		i++;
	}
	return (1);
}

/**
 * _printf - prints output of any format
 * @format: a character string
 * Return: 0 when it evaluates
 */

int _printf(const char *format, ...)
{
	va_list args;
	char c;
	int i = 0, numberofchars = 0;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					numberofchars += printChar(args);
					break;
				case 's':
					numberofchars += printStr(args);
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
	va_end(args);
	return (numberofchars);
}
