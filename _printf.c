#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int check_specifier(const char *format, va_list list, fmt_t *fmt);
/**
 * _printf - prints output according to a format
 * @format: character string
 * Return: numberofchars
 */
int _printf(const char *format, ...)
{
	va_list list;
	int numberofchars = 0;
	fmt_t fmt[] = {
		{"c", _printchar},
		{"s", _printstr},
		{"d", _printdecimal},
		{"i", _printint},
		{NULL, NULL}
	};

	if (!format)
		return (-1);
	va_start(list, format);
	numberofchars = check_specifier(format, list, fmt);

	va_end(list);
	return (numberofchars);
}
/**
 * check_specifier - checks for specifiers
 * @format: pointer pointing to the specifiers
 * @list: list to go through
 * @fmt: pointer of struct myfunc
 * Return: nomberofchars
 */
int check_specifier(const char *format, va_list list, fmt_t *fmt)
{
	int i = 0, j = 0, numberofchars = 0;
	char letters;

	letters = format[i];
	while (letters != '\0')
	{
		if (letters == '%')
		{
			j = 0;
			i++;
			letters = format[i];
			while (fmt[j].p != NULL && letters != *(fmt[j].p))
			{
				j++;
			}
			if (fmt[j].p != NULL)
				numberofchars += fmt[j].f(list);
			else
			{
				if (letters == '\0')
					return (-1);
				if (letters == '%')
				{
					numberofchars += _putchar('%');
				}
				else
					numberofchars += _putchar(letters);
			}
		}
		else
		{
			numberofchars += _putchar(letters);
		}
	i++;
	letters = format[i];
	}
	return (numberofchars);
}
