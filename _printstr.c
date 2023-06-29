#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printstr - prints a string
 * @list: list of specifiers
 * Return: strlength
 */
int _printstr(va_list list)
{
	int strlength = 0;
	char *str = va_arg(list, char *);

	if (!str)
		str = "(null)";
	while (str[strlength] != '\0')
	{
		strlength += _putchar(str[strlength]);
	}
	return (strlength);
}
