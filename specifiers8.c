#include "main.h"

/**
 * handler_prints - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: The buffer array to handle print.
 * @flags: Calculates active flags
 * @width: to get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handler_prints(const char *format, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	format_t format_types[] = {
		{'c', prints_char}, {'s', prints_string}, {'%', prints_percent},
		{'i', prints_int}, {'d', prints_int}, {'b', prints_binary},
		{'u', prints_unsigned}, {'o', prints_octal}, {'x', prints_hexadecimal},
		{'X', prints_hexa_upper}, {'p', prints_pointer}, {'S', prints_non_printable},
		{'r', prints_reverse}, {'R', prints_rot13string}, {'\0', NULL}
	};
	for (i = 0; format_types[i].format != '\0'; i++)
		if (format[*ind] == format_types[i].format)
			return (format_types[i].fn(list, buffer, flags, width, precision, size));

	if (format_types[i].format == '\0')
	{
		if (format[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (format[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (format[*ind] != ' ' && format[*ind] != '%')
				--(*ind);
			if (format[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &format[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
