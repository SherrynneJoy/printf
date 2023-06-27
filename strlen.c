#include <stdio.h>
#include "main.h"

/**
 * _strlen - returns the length of a string
 * @str: string to be measured
 * Return: length of the string
 */

size_t _strlen(const char *str)
{
	unsigned int len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}
