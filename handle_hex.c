#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_flag_chars - handles flag characters
 * @arg: point to arguments structure
 *
 * Return: Number of characters printed
 */
int handle_flag_chars(arg_t *arg)
{
	int nchar = 0;

	if (*(arg->cs) == 'x' && arg->flag_c[0])
	{
		nchar += _putchar('0');
		nchar += _putchar('x');
	}
	if (*(arg->cs) == 'X' && arg->flag_c[0])
	{
		nchar += _putchar('0');
		nchar += _putchar('X');
	}
	return (nchar);
}
/**
 * handle_hexX - handles 'x','X' conversion specifier
 * @arg: point to arguments structure
 *
 * Return: Number of characters printed
 */
int handle_hexX(arg_t *arg)
{
	unsigned long int n;
	int i, j, count = 0;
	char tmp;

	n = arg->len_md[0] ? va_arg(*(arg->ap), unsigned long int) :
		arg->len_md[1] ?
		(unsigned short int)va_arg(*(arg->ap), unsigned int) :
		(unsigned int)va_arg(*(arg->ap), unsigned int);
	if (n != 0)
	{
		i = 0;
		while (n != 0)
		{
			tmp = n % 16;
			if (tmp < 10)
				tmp += 48;
			else
				if (*(arg->cs) == 'X')
					tmp += 55;
				else
					tmp += 87;
			arg->buff[i++] = tmp;
			n /= 16;
		}
		count += i;
		count += arg->flag_c[0] ? 2 : 0;
		for (j = count; j < arg->field_wd; j++)
			count += _putchar(' ');
		handle_flag_chars(arg);
		for (j = i - 1; j >= 0; j--)
			_putchar(arg->buff[j]);
	}
	else
	{
		for (i = 0; i < arg->field_wd - 1; i++)
			count += _putchar(' ');
		count += _putchar('0');
	}
	return (count);
}

