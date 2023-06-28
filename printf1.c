#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_base - prints number to a base
 * @unsigned_long: accepts an unsigned int
 * @base: specifies the base to be used
 * Return: 0 when successful
 */

int print_base(size_t unsigned_long, int base)
{
	char *my_array = malloc(sizeof(char *));
	int i = 0, total = 0;

	do {
		int modulo = unsigned_long % base;

		if (modulo >= 0 && modulo < 10)
			my_array[i] = modulo + '0';
		else
			my_array[i] = 'a' + modulo - 10;
		unsigned_long = unsigned_long / base;
	} while (unsigned_long > 0);

	do {
		i--;
		total = total + _putchar(my_array[i]);
	} while (i);
	free(my_array);
	return (total);

}
/**
 * print_decimal - prints a number in base 10
 * @args: prints the next variable argument
 * @format: checks the conversion specifier
 * Return: nothng
 */

int print_decimal(va_list args, char format)
{
	int c = va_arg(args, int);
	int count = 0;

	if (c < 0)
	{
		c = -c;
		if (format == 'd')
			count = count + _putchar('-');
	}
	count = count + print_base(c, 10);
	return (count);
}

/**
 * print_integer - prints any number
 * @args: prints the next variable argument
 * @base: prints numbers to any base
 * Return: 0 when successful
 */

int print_integer(va_list args, int base)
{
	size_t c = va_arg(args, size_t);

	return (print_base(c, base));
}
