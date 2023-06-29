#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int check_specifier(const char *format, va_list args,
		fmt_t *fmt);

/**
 * _printf - prints output
 * @format: a string pointer
 * Return: 0 when successful
 */

int _printf(const char *format, ...)
{
	va_list args;
	int numberofchars = 0;
	fmt_t fmt[] = {
		{"c", printChar},
		{"s", printStr},
		{NULL, NULL}
	};

	if (format == NULL)
		return (-1);
	va_start(args, format);
	numberofchars = check_specifier(format, args, fmt);
	va_end(args);
	return (numberofchars);
}

/**
 * check_specifier - checks if the specifiers are valid
 * @format: the specifier (char *)
 * @args: prints the next variable argument
 * @fmt: pointer to structure fmt_t
 * Return: 0 when it evaluates
 */

int check_specifier(const char *format, va_list args, fmt_t *fmt)
{
	int i = 0;
	int j = 0;
	int numberofchars = 0;
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
				numberofchars += fmt[j].f(args);
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
