#include "main.h"
/**
 * printing_S - prints a string with custom funtion
 *
 * @str: string to be formatted
 * Return: number of chars to be printed
 */
int printing_S(char *str)
{
	int a = 0, char_printers = 0;
	char c;

	while (str[a])
	{
		c = str[a];
		if ((c > 0 && c  < 32) || c >= 127)
		{
			char_printers += team_putchar('\\');
			char_printers += team_putchar('x');
			char_printers += team_putchar('0');
			char_printers += printing_odh('X', (unsigned int)c);
		}
		else
		{
			char_printers += team_putchar(c);
		}
		a++;
	}
	return (char_printers);
}
