#include "main.h"

/**
 * prints_char - Prints a character
 * @size: Size of the specifier
 * @types: The list of arguments
 * @flags: Calculates the active flags
 * @width: The width
 * @buffer: The buffer array to handle print
 * @precision: The precision specification
 * Return: The number of chars to be printed
 */
int prints_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width,
				precision, size));
}

/**
 * prints_string - Prints a string
 * @size: Size of the specifier
 * @types: The list of arguments
 * @flags: Calculates the active flags
 * @width: The width
 * @buffer: The buffer array to handle print
 * @precision: The precision specification
 * Return: The number of strings to be printed
 */
int prints_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char*);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	UNUSED(precision);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/**
 * prints_percent - Prints the percentage sign
 * @size: Size specifier
 * @types: The list of arguments
 * @width: To get the width
 * @precision: The precision specification
 * @buffer: The buffer array that handles the print
 * @flags: Calculates the active flags
 * Return: The number percentage printed
 */
int prints_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(size);
	UNUSED(types);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(buffer);
	UNUSED(flags);
	return (write(1, "%%", 1));
}

/**
 * prints_int - Prints int
 * @size: Size specifier
 * @types: The list of arguments
 * @width: To get the width
 * @precision: The precision specification
 * @buffer: The buffer array that handles the print
 * @flags: Calculates the active flags
 * Return: The number of int printed
 */
int prints_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_numbers(is_negative, i, bufer,
		flags, width, precision, size));
}

/**
 * prints_binary - Prints an unsigned number
 * @size: Size specifier
 * @types: The lists of the arguments
 * @width: To get width
 * @precision: The precision specification
 * @flags: Calculates the active flags
 * @buffer: The buffer array to handle print
 * Return: Numbers of char printed
 */
int prints_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, k, i, sum;
	unsigned int b[32];
	int count;

	UNUSED(size);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(flags);
	UNUSED(buffer);

	n = va_arg(types, unsigned int);
	k = 2147483648; /* (2 ^ 31) */
	b[0] = n / k;
	for (i = 1; i < 32; i++)
	{
		k /= 2;
		b[i] = (n / k) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += b[i];
		if (sum || i == 31)
		{
			char z = '0' + b[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}