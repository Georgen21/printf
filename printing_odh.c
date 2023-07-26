#include "main.h"

/**
 * deci_to_octal - converts decimal to octal
 *
 * @num: number to be converted
 * Return: characters printed
 */
int deci_to_octal(unsigned int num)
{
	int char_printers = 0;

	if (!num)
		return (0);
	char_printers += (deci_to_octal(num / 8));
	char_printers += team_putchar('0' + num % 8);
	return (char_printers);
}

/**
 * deci_to_hexxa - converts decimal to hexadecimal
 *
 * @c: case specifier
 * @num: number to be converted
 * Return: characters printed
 */
int deci_to_hexxa(char c, unsigned int num)
{
	int char_printers = 0;

	if (!num)
		return (0);
	char_printers += deci_to_hexxa(c, num / 16);
	if (num % 16 < 10)
		char_printers += team_putchar('0' + num % 16);
	else if (num % 16 > 9 && c == 'x')
		char_printers += team_putchar(87 + num % 16);
	else
		char_printers += team_putchar(55 + num % 16);
	return (char_printers);
}

/**
 * printing_odh - prints a number in its octal, decimal or hex representation
 *
 * @c: type to be converted to
 * @num: number to be converted
 * Return: characters printed
 */
int printing_odh(char c, unsigned int num)
{
	int char_printers = 0;

	if (c == 'u')
		char_printers += printer_nums(num);
	else if (c == 'o' && num == 0)
		char_printers = printing_strings("00");
	else if (c == 'o')
		char_printers += deci_to_octal(num);
	else if ((c == 'x' || c == 'X') && num == 0)
		char_printers += printing_strings("00");
	else
		char_printers += deci_to_hexxa(c, num);
	return (char_printers);
}
