#include <stdarg.h>
#include "main.h"

/**
 * dec_to_oct - converts unsigned number into octal
 * @num: unsigned  number to be converted
 *
 * Return: octal of the given number
 */
long dec_to_oct(unsigned int num)
{
	long oct = 0, i = 1;
	int rem;

	while (num != 0)
	{
		rem = num % 8;
		num = num / 8;
		oct += (rem * i);
		i *= 1;
	}
	return (oct);
}
/**
 * handle_oct - handles 'o' conversion specifier
 * @ap: Pointer to va_list
 * @cs_mod: Structure of cs modifier
 *
 * Return: Number of characters printed
 */
int handle_oct(va_list *ap, cs_modifier_t cs_mod)
{
	unsigned long int len, powten, j, digit, n, count = 0, num;

	n = cs_mod.len_md[1] == 1 ? va_arg(*ap, unsigned long int) :
		cs_mod.len_md[0] == 1  ?
		(unsigned short int)va_arg(*ap, unsigned int) :
		(unsigned int)va_arg(*ap, unsigned int);
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
		if (cs_mod.flag_c[0])
			count += _putchar('0');
		for (j = 1; j <= len; j++)
		{
			digit = num / powten;
			_putchar(digit + '0');
			count++;
			num -= digit * powten;
			powten /= 10;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
