#include "main.h"

/**
 * getFlags - Calculate active flags
 * @format: Formatted string to print the arguments
 * @index: take a parameter.
 * Return: Flags:
 */
int getFlags(const char *format, int *index)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, currIndex;
	int flags = 0;
	const char FLAGS_CHARS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (currIndex = *index + 1; format[currIndex] != '\0'; currIndex++)
	{
		for (j = 0; FLAGS_CHARS[j] != '\0'; j++)
			if (format[currIndex] == FLAGS_CHARS[j])
			{
				flags |= FLAGS_ARRAY[j];
				break;
			}

		if (FLAGS_CHARS[j] == 0)
			break;
	}

	*index = currIndex - 1;

	return flags;
}
