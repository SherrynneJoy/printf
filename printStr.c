#include "main.h"

/**
 * printStr - prints a string
 * @args: prints the next variable argument
 * Return: nothing
 */

int printStr(va_list args)
{
	char c, *str;
	int lengthStr = 0;

	str = va_arg(args, char *);
	if (str == NULL)
	str = "(null)";
	while (str[lengthStr] != '\0')
	{
	lengthStr += _putchar(str[lengthStr]);
	}
	return (lengthStr);
}
