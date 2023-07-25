#include "main.h"

/**
 * prints_pointer - To print value of pointer variable
 * @size: The size of specifier
 * @types: The list of arguments
 * @width: To get the width
 * @flags: To calculate the active flags
 * @buffer: The buffer array to handle the print
 * @precision: The precision specification
 * Return: The number of chars printed
 */
int prints_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	/*length = 2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(size);
	UNUSED(width);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	return (write_pointer(buffer, ind, length, width,
				flags, padd, extra_c, padd_start));
}

/**
 * prints_non_printable - Prints ascii codes in hexa non printable char
 * @size: The size of specifier
 * @types: The list of arguments
 * @width: To get the width
 * @buffer: The buffer array to handle print
 * @flags: To calculate active flags
 * @precision: The precision specification
 * Return: The char to be printed
 */
int prints_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offs = 0;
	char *str = va_arg(types, char *);

	UNUSED(size);
	UNUSED(width);
	UNUSED(flags);
	UNUSED(precision);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offs] = str[i];
		else
			offs += append_hexa_code(str[i], buffer, i + offs);

		i++;
	}

	buffer[i + offs] = '\0';

	return (write(1, buffer, i + offs));
}

/**
 * prints_reverse - funtion that prints reverse string
 * @size: The specifiers size
 * @types: The list of arguments
 * @width: To get the width
 * @flags: To calculate active flags
 * @buffer: The buffer array that handle print
 * @precision: The precision specification
 * Return: The printed chars
 */
int prints_reverse(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(size);
	UNUSED(width);
	UNUSED(flags);
	UNUSED(buffer);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")NULL(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * prints_rot13string - function that prints the rot13'ed string
 * @size: The specifiers size
 * @types: The list of arguments
 * @width: To get the width
 * @buffer: The buffer array that handles print
 * @flags: To calculate active flags
 * @precision: The specification precision
 * Return: The number of string printed
 */
int prints_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, k;
	int count = 0;
	char enter[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(size);
	UNUSED(width);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(precision);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (k = 0; enter[k]; k++)
		{
			if (enter[k] == str[i])
			{
				x = out[k];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!enter[k])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
