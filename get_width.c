#include "main.h"

/**
 * determineWidth - Calculates the width for printing
 * @formatString: Formatted string for printing the arguments.
 * @index: Index of arguments to be printed.
 * @argsList: List of arguments.
 *
 * Return: Calculated width.
 */
int determineWidth(const char *formatString, int *index, va_list argsList)
{
	int currIndex;
	int width = 0;

	for (currIndex = *index + 1; formatString[currIndex] != '\0'; currIndex++)
	{
		if (isDigit(formatString[currIndex]))
		{
			width *= 10;
			width += formatString[currIndex] - '0';
		}
		else if (formatString[currIndex] == '*')
		{
			currIndex++;
			width = va_arg(argsList, int);
			break;
		}
		else
			break;
	}

	*index = currIndex - 1;

	return width;
}
