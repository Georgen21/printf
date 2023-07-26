#include "main.h"
#include <stdio.h>

/**
 * printer_nums - The digits of an interger to be printed
 * @n: The integer to be printed
 * Return: return value
 */
int printer_nums(long int n)
{
	unsigned long int a, b;
	int char_printers = 0;

	a = 0;
	b = 10;
	if (n < 0)
	{
		char_printers += team_putchar(45);
		a = -n;
	}
	else
	{
		a = n;
	}
	if (a < b)
	{
		char_printers += team_putchar('0' + a);
	}
	else
	{
		while (a >= b)
		{
			b *= 10;
			if (b == 1000000000000000000)
				break;
		}
		if (!(a > 1000000000000000000))
			b /= 10;
		char_printers += team_putchar('0' + (a / b));
		b /= 10;
		while (b >= 10)
		{
			char_printers += team_putchar('0' + ((a / b) % 10));
			b /= 10;
		}
		char_printers += team_putchar('0' + (a % 10));
	}
	return (char_printers);
}
