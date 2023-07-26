#include "main.h"

/**
 * printing_pointers - prints a pointer
 * @p: pointer to be printed
 *
 * Return: number of characters printed
 */
int printing_pointers(void *p)
{
	int char_printers = 0;

	char_printers += printing_strings("0x");
	char_printers += printing_odh('x', (unsigned long int)p);
	return (char_printers);
}
