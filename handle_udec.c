#include <stdarg.h>
#include "main.h"

/**
 * handle_udec - handles 'u' conversion specifier
 * @ap: Pointer to va_list
 * @cs_mod: Structure of cs modifier
 *
 * Return: Number of characters printed
 */
int handle_udec(va_list *ap, cs_modifier_t cs_mod)
{
	unsigned long int len, powten, j, digit, n, count = 0, num;

	n = cs_mod.len_md[1] ? va_arg(*ap, unsigned long int) :
		cs_mod.len_md[0] ? (unsigned short int)va_arg(*ap, unsigned int)
		: (unsigned int)va_arg(*ap, unsigned int);
	if (n != 0)
	{
		num = n;
		len = 0;
		while (num != 0)
		{
			num /= 10;
			len++;
		}
		powten = 1;
		for (j = 1; j <= len - 1; j++)
			powten *= 10;
		for (j = 1; j <= len; j++)
		{
			digit = n / powten;
			_putchar(digit + '0');
			count++;
			n -= digit * powten;
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
