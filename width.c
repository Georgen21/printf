#include "main.h"

/**
 * fetch_width - Calculation of the printed width.
 * @format: Formatted string where the arguments will be printed.
 * @i: List of arguments that will be printed.
 * @listingz: lists of arguments.
 *
 * Return: width.
 */

int fetch_width(const char *format, int *i, va_list listingz)
{
	int zyz;
	int width = 0;

	for (zyz = *i + 1; format[zyz] != '\0'; zyz++)
	{
		if (is_digit(format[zyz]))
		{
			width *= 10;
			width += format[zyz] - '0';
		}
		else if (format[zyz] == '*')
		{
		zyz++;
			width = va_arg(listingz, int);
			break;
		}
		else
			break;
	}

	*i = zyz - 1;

	return (width);
}
