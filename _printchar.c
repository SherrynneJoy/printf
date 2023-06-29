#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printchar - prints a character
 * @list: list of specifiers
 * Return: character
 */
int _printchar(va_list list)
{
	return (_putchar(va_arg(list, int)));
}
