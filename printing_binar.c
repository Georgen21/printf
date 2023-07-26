#include "main.h"

/**
 * printing_binar - this converts unsigned int to binary
 * @num: int that will be converted
 *
 * Return: number of resulting binary chars
 */
int printing_binar(unsigned int num)
{
	int char_printers = 0, inxe = 0;
	char bin[sizeof(unsigned int) * 8];

	if (num == 0)
	{
		char_printers += team_putchar('0');
		return (char_printers);
	}
	if (num == 1)
	{
		char_printers += team_putchar('1');
		return (char_printers);
	}
	while (num > 0)
	{
		bin[inxe] = '0' + (num % 2);
		num = num / 2;
		inxe++;
	}
	inxe--;
	while (inxe >= 0)
	{
		char_printers += team_putchar(bin[inxe]);
		inxe--;
	}
	return (char_printers);
}
