#include "main.h"

/**
 * gets_flags - Calcutes all active flags
 * @format: Format string where arguments are to be printed.
 * @i: takes up a parameter
 *
 * Return: 0 (succes)
 */

int gets_flags(const char *format, int *i)
{
/* - + 0 # '' */
/* 1 2 4 8 16 */
	int b, curr_i;
	int flags = 0;

	const char FLAGS_CH[] = {'-', '+', '0', '#', '', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (b = 0; FLAGS_CH[b] != '\0'; b++)
			if (format[curr_i] == FLAGS_CH[b])
			{
				flags |= FLAGS_ARR[b];
				break;
			}

		if (FLAGS_CH[b] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}
