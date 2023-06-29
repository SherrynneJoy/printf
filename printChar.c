#include "main.h"

/**
 * printChar - prints a char
 * @va_list: prints variable arguments
 * Return: 0 when it evaluates
 */

int printChar(va_list args)
{
	return (_putchar(va_arg(args, int)));
}
