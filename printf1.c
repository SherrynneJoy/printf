#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
/**
 * base_fn - checks for base 10
 * @base: base to be printed
 * @unsignedlong: unsigned long int
 * Return: count
 */
int base_fn(size_t unsignedlong, int base)
{
	/**we first create an array to store the values*/
	char *arr = malloc(sizeof(char *));
	int i = 0, m;
	int count = 0;

	do {
		m = unsignedlong % 10;
		if (m >= 0 && m < 9)
	{
		arr[i] = m + '0';
	}
		else
			arr[i] = 'a' + m - 10;
		unsignedlong /= base;
	} while (unsignedlong > 0);
	do {
		i--;
		count += _putchar(arr[i]);
	} while (i);
	free(arr);
	return (count);
}
/**
 * printdecimal - prints decimal
 * @list: list from which to loop
 * @format: format specified
 * Return: count
 */
int printdecimal(va_list list, char format)
{
	int c = va_arg(list, int);
	int count = 0;

	if (c < 0)
	{
		c = -c;
		if (format ==  'd')
			count += _putchar('-');
	}
	count += base_fn(c, 10);
	return (count);
}
/**
 * printint - prints integer acccording to its actual base
 * @list: list to go through
 * @base: base of the int as either decimal, hexadecimal/octal
 * Return: base_fn(c, base)
 */
int printint(va_list list, int base)
{
	size_t c = va_arg(list, int);

	return (base_fn(c, base));
}
