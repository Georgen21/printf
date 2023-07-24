#include "main.h"

/**
 * gets_width - Funtion that calculates the width of printing
 * @format: The formatted string to print arguments
 * @list: Lists of arguments
 * @i: List of argument to be printed
 *
 * Return: The width
 */
int gets_width(const char *format, int *i, va_list list)
{
	int current_i;
	int width = 0;

	for (current_i = *i + 1; format[current_i] != '\0'; current_i++)
	{
		if (is_digit(format[current_i]))
		{
			width *= 10;
			width += format[current_i] - '0';
		}
		else if (format[current_i] == '*')
		{
			current_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = current_i;

	return (width);
}
