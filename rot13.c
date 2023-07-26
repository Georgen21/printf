#include "main.h"

/**
 * printing_rot13 - encoding a string using rot13 encryption
 * @s: strings that will be encoded
 *
 * Return: number of chars printed
 */

int printing_rot13(char *s)
{
	char nor[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
		      'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
		      'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
		      'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
		      'Z', ' '};
	char rot[] = {'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
		      'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
		      'm', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
		      'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
		      'M', ' '};
	int count, lengthz, count2 = 0, char_print = 0;
	char before, *rot13d;

	lengthz = 0;
	while (*(s + lengthz))
		lengthz++;
	rot13d = malloc(sizeof(char) * lengthz);
	if (rot13d == NULL)
	{
		free(rot13d);
		return (0);
	}
	lengthz = 0;
	while (*(s + lengthz))
	{
		before = *(s + lengthz);
		for (counterz = 0; counterz < 53; counterz++)
		{
			if (before == nor[counterz])
			{
				*(rot13d + lengthz) = rot[counterz];
				counterz2 = counterz;
				break;
			}
		}
		if (*(rot13d + lengthz) != rot[counterz2])
			*(rot13d + lengthz) = brfore;
		if (*(rot13d + lengthz) == '\\')
		{
			*(rot13d + lengthz + 1) = *(s + lengthz + 1);
			lengthz++;
		}
		lengthz++;
	}
	*(rot13d + lengthz) = '\0';
	char_print = printing_strings(rot13d);
	free(rot13d);
	return (char_print);
}
