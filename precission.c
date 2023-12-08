#include "main.h"

/**
 * get_prec - Calculates the prec for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: prec.
 */
int get_prec(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int prec = -1;

	if (format[curr_i] != '.')
		return (prec);

	prec = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			prec *= 10;
			prec += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			prec = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (prec);
}
