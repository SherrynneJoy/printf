#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
size_t _strlen(const char *str);
int printChar(va_list args);
int printStr(va_list args);
int main(void);

#endif
