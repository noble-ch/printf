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
int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;

    while (*format != '\0') {
        if (*format == '%') {
            format++; // Move past '%'

            // Handle different conversion specifiers
            switch (*format) {
                case 'c': {
                    // Fetch char argument and print
                    char c = (char)va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's': {
                    // Fetch string argument and print
                    char *str = va_arg(args, char *);
                    while (*str != '\0') {
                        putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                }
                case '%':
                    // Handle %%
                    putchar('%');
                    count++;
                    break;
                default:
                    // Handle unsupported conversion specifiers
                    return -1;
            }
        } else {
            // Regular character, print it
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}

int main() {
    _printf("I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life %%\n");
    return 0;
}