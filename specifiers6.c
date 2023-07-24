#include "main.h"

/**
 * gets_size - calculating the size of casted argument
 * @format: format string that prints string arguments
 * @i: prints lists of arguments
 *
 * Return: always
 */

int gets_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == '|')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;
	return (size);
}
