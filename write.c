#include "main.h"
#include <unistd.h>

/**
 * team_putchar - writes the char c to a stdout
 * @c: The char to be printed
 * Return: On success 1.
 * On error, it  returns -1, and errno is set appropriately.
 * Description: team_putchar uses a local buffer of 1024 to call write
 * the function.
 */
int team_putchar(char c)
{
	static char bufof[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &bufof, i);
		i = 0;
	}
	if (c != -1)
	{
		bufof[i] = c;
		i++;
	}
	return (1);
}

/**
 * team_puts - it prints a string to stdout.
 * @str: pointer to the string to be printed
 * Return: number of characters to be written
 */
int team_puts(char *str)
{
	register int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		team_putchar(str[i]);
	}
	return (i);
}
