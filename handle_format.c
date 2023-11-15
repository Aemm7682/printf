#include "main.h"
/**
 * handle_format - Handles the format specifier
 * @format: The format string
 * @args: The argument list
 * @i: The current index in the format string
 * @m: The array of format specifiers and corresponding functions
 *
 * Return: The length of the printed string
 */
int handle_format(const char *format, va_list args, int i, convert_match *m)
{
        int j = 13;
        int len = 0;

        while (j >= 0)
        {
                if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
                {
                        if (format[i] == '%' && format[i + 1] == 'r' && !args)
                        {
                                _putchar('%');
                                _putchar('r');
                                len += 2;
                        }
                        else
                        {
                                len += m[j].f(args);
                        }
                        i = i + 2;
                        break;
                }
                j--;
        }
        return (len);
}
