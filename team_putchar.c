#include <unistd.h>

/**
 * team_putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int team_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
