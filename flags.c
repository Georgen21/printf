#include "main.h"

/**
 * fetch_flag - Calculation of all active flags
 * @format: Formatted string in which to print the arguments
 * @i: takes a param
 * Return: Flags:
 */
int fetch_flag(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int x, current;
	int flags = 0;
	const char FLAGS_CHARAC[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRAYS[] = {F_MINUS, F_PLUS, F_ZERO,
		F_HASH, F_SPACE, 0};

	for (current = *i + 1; format[current] != '\0'; current++)
	{
		for (x = 0; FLAGS_CHARAC[x] != '\0'; x++)
			if (format[current] == FLAGS_CHARAC[x])
			{
				flags |= FLAGS_ARRAYS[x];
				break;
			}

		if (FLAGS_CHARAC[x] == 0)
			break;
	}

	*i = current - 1;

	return (flags);
}
