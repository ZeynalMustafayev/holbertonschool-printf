#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <string.h>
#include "main.h"
#include <stdlib.h>
/**
 * _printf - print string
 * @format: format
 * Return: letter count
 */
int _printf(const char *format, ...)
{
        va_list ptr;
        unsigned int j = 0, r = 0;

        if (format == NULL)
                exit(98);
        va_start(ptr, format);
        for (j = 0; *(format + j) != '\0'; j++)
        {
                if (*(format + j) != '%')
                {
                        r++, putchar(*(format + j));
                }
                else if (*(format + j) == '%' && *(format + j + 1) == '%')
                {
                        r++, j++, putchar('%');
                }
                else if (*(format + j) == '%' && *(format + j + 1) == 'c')
                {
                        r = print_char(r, va_arg(ptr, int));
                        j++;
                }
                else if (*(format + j) == '%' && *(format + j + 1) == 's')
                {
                        r = print_string(r, va_arg(ptr, char *));
                        j++;
                }
                else
                        r++, putchar(*(format + j));
        }
        if (r == 0)
                r = -1;
        return (r);
}
