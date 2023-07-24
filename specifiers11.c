#include "main.h"

/**
 * is_printable - checks if a char can be printed
 * @c: character to be checked
 *
 * Return: 1 if c is printef otherwise print Zero.
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascci in hexa code to buffer
 * @ascii_code: ASCII CODE.
 * @i:index where appendation starts
 * @buffer: Arrays of characters
 *
 * Return: always 3.
 */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/** the hexadecimal format code is always 2 digit **/

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies if the character is a digit
 * @c: Char to be verified
 *
 * Return: returns 1 if c is a digit, 0 otherwise
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts a number to its specified size.
 * @number: number casted
 * @size: number indicating the type of cast to be casted
 *
 * Return: value of casted numbers
 */

long int convert_size_number(long int number, int size)
{
	if (size == S_LONG)
		return (number);
	else if (size == S_SHORT)
		return ((short)number);

	return ((int)number);
}

/**
 * convert_size_unsgnd - it casts the number to its specified size
 * @number: number that would be casted
 * @size: number indicating the type cast that will be casted
 *
 * Return: values of numbers casted
 */

long int convert_size_unsgnd(unsigned long int number, int size)
{
	if (size == S_LONG)
		return (number);
	else if (size == S_SHORT)
		return ((unsigned short)number);

	return ((unsigned int)number);
}
