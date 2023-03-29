#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_flag_chars - handles flag characters
 * @cs: Conversion specifier
 * @arg: point to arguments structure
 *
 * Return: Number of characters printed
 */
int handle_flag_chars(char cs, arg_t *arg)
{
	int nchar = 0;

	if (cs == 'x' && arg->flag_c[0])
	{
		nchar += _putchar('0');
		nchar += _putchar('x');
	}
	if (cs == 'X' && arg->flag_c[0])
	{
		nchar += _putchar('0');
		nchar += _putchar('X');
	}
	return (nchar);
}
/**
 * handle_xX - handles 'x','X' conversion specifier
 * @cs: Conversion specifier
 * @arg: point to arguments structure
 *
 * Return: Number of characters printed
 */
int handle_xX(char cs, arg_t *arg)
{
	unsigned long int n;
	int i, j, count = 1;
	char *buff, tmp;

	n = arg->len_md[0] ? va_arg(*(arg->ap), unsigned long int) :
		arg->len_md[1] ?
		(unsigned short int)va_arg(*(arg->ap), unsigned int) :
		(unsigned int)va_arg(*(arg->ap), unsigned int);
	if (n != 0)
	{
		buff = malloc(8);
		if (!buff)
			return (0);
		count = handle_flag_chars(cs, arg);
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
 * @arg: point to arguments structure
 *
 * Return: number of characters printed
 */
int handle_hex(arg_t *arg)
{
	return (handle_xX('x', arg));
}
/**
 * handle_heX - handles 'x' conversion specifier
 * @arg: point to arguments structure
 *
 * Return: number of characters printed
 */
int handle_heX(arg_t *arg)
{
	return (handle_xX('X', arg));
}
