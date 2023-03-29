#include <stdarg.h>
#include "main.h"

#include <stdarg.h>
#include "main.h"

/**
 * dec_to_oct - converts unsigned number into octal
 * @num: unsigned  number to be converted
 *
 * Return: octal of the given number
 */
unsigned long int dec_to_oct(unsigned long int num)
{
	unsigned long int oct = 0, i = 1;
	int rem;

	while (num != 0)
	{
		rem = num % 8;
		num = num / 8;
		oct += (rem * i);
		i *= 10;
	}
	return (oct);
}
/**
 * handle_oct - handles 'o' conversion specifier
 * @arg: point to arguments structure
 *
 * Return: Number of characters printed
 */
int handle_oct(arg_t *arg)
{
	unsigned long int powten, n, num;
	int len, j, digit, count = 0;

	n = arg->len_md[0] ? va_arg(*(arg->ap), unsigned long int) :
		arg->len_md[1] ?
		(unsigned short int)va_arg(*(arg->ap), unsigned int) :
		(unsigned int)va_arg(*(arg->ap), unsigned int);
	if (n != 0)
	{
		num = dec_to_oct(n);
		len = 0;
		while (num != 0)
		{
			num /= 10;
			len++;
		}
		powten = 1;
		num = dec_to_oct(n);
		for (j = 1; j <= len - 1; j++)
			powten *= 10;
		if (arg->flag_c[0])
			count += _putchar('0');
		for (j = 1; j <= len; j++)
		{
			digit = num / powten;
			count += _putchar(digit + '0');
			num -= digit * powten;
			powten /= 10;
		}
	}
	else
	{
		count = _putchar('0');
	}
	return (count);
}
