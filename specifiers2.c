#include "main.h"

/*****UNSIGNED NUMBERS WILL BE PRINTED*****/

/**
 * prints_unsigned - this will print unsigned number.
 * @types: argument lists
 * @flags: calculating all active flags
 * @width: get width
 * @precision: precision specification.
 * @size: specifies size
 * @buffer: buffer array which handles string
 * Return: Number of chars to be printed.
 */

int prints_unsigned(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num /= 10;
}

/***** PRINTS OCTAL UNSIGNED NUMBERS *****/

/**
 * prints_octal - displays unsigned nums in an octal notation.
 * @types: listing arguments
 * @buffer: Buffer array to handle print.
 * @flags: calculating all active flags
 * @precision: specifies precisions
 * @width: gets the width.
 * @size: Specifying the size
 *
 * Return: numbers of chars that will be printed.
 */

int prints_octal(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int number = var_arg(types, unsigned long int);
	unsigned long int init_num = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[i--] = '0';

	buffer[BUFF_size - 1] = '\0';

	while (number > 0)
	{
		buffer[i--] = (number % 8) + '0';
		number /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/***** PRINTING  OF UNSIGNED NUMBER IN HEXADECIMAL FORMAT *****/

/**
 * prints_hexadecimal - displays an unsigned number in hexadecimal notation
 * @types: listing of arguments
 * @buffer: Buffer array which handle prints
 * @precision: specifies precision
 * @width: gets its width.
 * @flags: calculates all active flags
 * @size: specifies its size.
 *
 * Return: numbers of characters to be printed
 */

int prints_hexadecimal(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	return (prints_hexa(types, "0123456789abcdef", buffer, flags, 'x',
				width precision, size));
}

/****** PRINTING OF UNSIGNED NUMBERS IN UPPER HEXADECIMAL FORMAT *****/

/**
 * prints_hexa_upper - displays an unsigned number in upper
 * hexadecimal notation.
 * @buffer: buffer array that handles printing
 * @types: listing of arguments
 * @width: gets the width
 * @precision: specifies precision
 * @size: specifies its size
 * @flags: caculating all active flag
 *
 * Return: number of characters to be printed
 */
int prints_hexa_upper(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
return (prints_hexa(types, "0123456789ABCDEF", buffer, flags,
			'X', width, precision, size));
}

/**** PRINTING OF HEXA NUMBERS IN AN UPPER OR LOWER FORMAT ****/


/**
 * prints_hexa - prints a hexadecimal in either lower or upper format.
 * @types: listing of arguments
 * @flags: calculation of all active flags
 * @flag_ch: also calcutes active flags
 * @precision: specifies its precision
 * @width: gets the width
 * @size: specifies it size
 * @map_to: arrays of value that the num will be mapped to.
 * @buffer: buffer array to handle the print
 *
 * Return: number of chars to be printed
 */

int prints_hexa(va_list types, char map_to[], char buffer[], int flags,
		char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0\;

	while (number > 0)
	{
		buffer[i--] = map_to[number % 16];
		number /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
