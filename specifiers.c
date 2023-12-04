#include "main.h"

/**
 * print_binry - Prints an unsigned integer in binary
 * @n: unsigned int
 *
 * Return:count
 */

int print_binry(unsigned int n)
{
	int count = 0;

	if (n > 1)
	{
		count += print_binry(n / 2);
	}
	count += print_chr('0' + n % 2);
	return (count);
}
