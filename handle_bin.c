#include <stdarg.h>
#include "main.h"
/**
 *handle_bin - handles 'b' conversion specifier
 * @ap: Pointer to va_list
 * @cs_mod: structure to conversion specifier modifiers
 *
 * Return: Number of characters printed
 */
int handle_bin(va_list *ap, cs_modifier_t cs_mod)
{
	unsigned int len, powten, j, digit, n, num;
	int count = 0;

	(void) cs_mod;
	n = va_arg(*ap, unsigned int);
	if (n != 0)
	{
		num = n;
		len = 0;
		while (num != 0)
		{
			num /= 2;
			len++;
		}
		powten = 1;
		for (j = 1; j <= len - 1; j++)
			powten *= 2;
		for (j = 1; j <= len; j++)
		{
			digit = n / powten;
			_putchar(digit + '0');
			count++;
			n -= digit * powten;
			powten /= 2;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
