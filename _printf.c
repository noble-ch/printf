#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf() function
 *
 * @format: format
 *
 * Return: Printed characters
 */

int _printf(const char *format, ...)
{
	int count;
	va_list args;

	count = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			count += handle_format(*(++format), args);
		}
		else
		{
			count += write(1, format, 1);
		}
		++format;
	}
	va_end(args);
	return (count);
}
