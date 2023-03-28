#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_flag_chars - handles flag characters
 * @cs: Conversion specifier
 * @cs_mod: structure to cs modifier
 *
 * Return: Number of characters printed
 */
int handle_flag_chars(char cs, cs_modifier_t cs_mod)
{
	int nchar = 0;

	if (cs == 'x' && cs_mod.flag_c[0])
	{
		nchar += _putchar('0');
		nchar += _putchar('x');
	}
	if (cs == 'X' && cs_mod.flag_c[0])
	{
		nchar += _putchar('0');
		nchar += _putchar('X');
	}
	return (nchar);
}
/**
 * handle_xX - handles 'x','X' conversion specifier
 * @cs: Conversion specifier
 * @ap: Pointer to va_list
 *
 * Return: Number of characters printed
 */
int handle_xX(char cs, va_list *ap)
{
	unsigned int n;
	int i, j, count = 1;
	char *buff, tmp;

	n = va_arg(*ap, unsigned int);
	if (n != 0)
	{
		buff = malloc(8);
		if (!buff)
			return (0);
		count = 0;
		i = 0;
		while (n != 0)
		{
			tmp = n % 16;
			if (tmp < 10)
				tmp += 48;
			else
				if (cs == 'X')
					tmp += 55;
				else
					tmp += 87;
			buff[i++] = tmp;
			n /= 16;
		}
		count += i;
		for (j = i - 1; j >= 0; j--)
			_putchar(buff[j]);
		free(buff);
	}
	else
	{
		_putchar('0');
	}
	return (count);
}
/**
 * handle_hex - handles 'x' conversion specifier
 * @ap: point to va_list
 *
 * Return: number of characters printed
 */
int handle_hex(va_list *ap)
{
	return (handle_xX('x', ap));
}
/**
 * handle_heX - handles 'x' conversion specifier
 * @ap: point to va_list
 *
 * Return: number of characters printed
 */
int handle_heX(va_list *ap)
{
	return (handle_xX('X', ap));
}
