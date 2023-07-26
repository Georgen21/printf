#include "main.h"

/**
 * _printf - it prints an output according to its format
 * @format: it inputs a string
 * ...: variadic params
 *
 * Return: the numbers of characters printed.
 */

int _printf(const char *format, ...)
{
va_list args;
int i = 0, char_printers = 0;

va_start(args, format);
while (format && format[i])
{
if (format[i] != '%')
{
	char_printers += team_putchar(format[i]);
}
else if (format[i + 1])
{
i++;

if (format[i] == 'c' || format[i] == 's')
	char_printers += format[i] == 'c' ? team_putchar(va_arg(args, int)) :
	printing_strings(va_arg(args, char *));
else if (format[i] == 'd' || format[i] == 'i')
	char_printers += printer_nums(va_arg(args, int));
else if (format[i] == 'b')
	char_printers += printing_binar((unsigned int)va_arg(args, int));
else if (format[i] == 'r')
	char_printers += printing_reverses(va_arg(args, char *));
else if (format[i] == 'R')
	char_printers += printing_rot13(va_arg(args, char *));
else if (format[i] == 'o' || format[i] == 'u' ||
	format[i] == 'x' || format[i] == 'X')
	char_printers += printing_odh(format[i],
	(unsigned int)va_arg(args, int));
else if (format[i] == 'S')
	char_printers += printing_S(va_arg(args, char *));
else if (format[i] == 'p')
	char_printers += printing_pointers
	(va_arg(args, void *));
else
	char_printers += printing_unknown_letter(format[i]);
	}
	i++;
	} va_end(args);
return (char_printers);
}
