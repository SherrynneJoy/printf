#include <stdio.h>
#include "main.h"
/**
 * _strlen - measures length of string
 * @str: string being measured
 * Return: len
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
