#include "main.h"

/**
 * printing_reverses - prints a string in reverse order.
 * @s: string to be printed in reverse order
 * Return: number printed
 */
int printing_reverses(char *s)
{
	int k, l, m, char_printers = 0;
	char *str;

	k = 0;
	l = 0;
	m = 0;
	if (s)
	{
		while (*(s + k))
			k++;
		str = malloc(sizeof(char) * k);
		if (str == NULL)
		{
			free(str);
			return (0);
		}
		for (l = (k - 1); l >= 0; l--)
		{
			*(str + m) = *(s + l);
			m++;
		}
		*(str + k) = '\0';
		char_printers = printing_strings(str);
		return (char_printers);
	}
	return (0);
}
