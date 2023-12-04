#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_chr - Print a character
 * @c: Character
 *
 * Return: character
 */

int print_chr(int c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - Prints a string
 * @string: Pointer to string
 *
 * Return: count
 */

int print_str(char *string)
{
	int count;

	count = 0;
	while (*string != '\0')
	{
		print_chr((int)*string);
		++count;
		++string;
	}
	return (count);
}

/**
 * print_percnt - prints a percent
 *
 * Return: % - percent
 */

int print_percnt(void)
{
	return (write(1, "%%", 1));
}

/**
 * print_intgr - Prints an integer
 * @n: integer
 *
 * Return: count
 */

int print_intgr(int n)
{
	int count;

	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}
	if (n < 10)
	{
		count += print_chr('0' + n);
	}
	else
	{
		count += print_intgr(n / 10);
		count += print_chr('0' + n % 10);
	}
	return (count);
}

/**
 * handle_format - Handles the different format specifiers
 * @specifier: format specifier
 * @args: Args
 *
 * Return: count
 */

int handle_format(char specifier, va_list args)
{
	int count;

	count = 0;

	if (specifier == 'c')
		count = print_chr(va_arg(args, int));
	else if (specifier == 's')
		count += print_str(va_arg(args, char *));
	else if (specifier == '%')
		count = print_percnt();
	else if (specifier == 'd' || specifier == 'i')
		count += print_intgr(va_arg(args, int));
	else if (specifier == 'b')
		count += print_binry(va_arg(args, unsigned int));
	else
		write(1, &specifier, 1);

	return (count);
}
