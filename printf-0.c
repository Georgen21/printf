#include "main.h"
#include <string.h>

void prints_buffer(char buffer[], int buff_ind);

/**
 * _printf - produces output according to format.
 * @format: char to be printed
 * @...: variadic parameter
 *
 * Return: number of printed chars.
 */

int _printf(const char *format, ...)
{
	va_list lists;
	int i, prints = 0, prints_char = 0;
	int flags, width, precision, size, buff_ind = 0;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(lists, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				prints_buffer(buffer, &buff_ind);
			/* write (1, &format[i], 1); */
			prints_char++;
		}
		else
		{
			prints_buffer(buffer, &buff_ind);
			flags = gets_flags(format, &i);
			width = gets_width(format, &i, lists);
			precision = gets_precision(format, &i, lists);
			size = gets_size(format, &i);
			i++;
			printed = handle_ prints(format, &i, lists, buffer,
					flags, width, precision, size);
		}
	}
	prints_buffer(buffer, &buff_ind);

	va_end(lists);

	return (printed_chars);
}

/**
 * prints_buffer - displays the buffer content if present.
 * @buffer: character array
 * @buff_ind: An index which will be added to char, reps the length.
 */

void prints_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
