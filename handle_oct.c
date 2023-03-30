#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * handle_oct - handles 'o' conversion specifier
 * @arg: point to arguments structure
 *
 * Return: Number of characters printed
 */
int handle_oct(arg_t *arg)
{
	unsigned long int n;
	int i, j, count = 0;
	char *buff;

	n = arg->len_md[0] ? va_arg(*(arg->ap), unsigned long int) :
		arg->len_md[1] ?
		(unsigned short int)va_arg(*(arg->ap), unsigned int) :
		(unsigned int)va_arg(*(arg->ap), unsigned int);
	if (n != 0)
	{
		buff = malloc(22);
		if (!buff)
			return (0);
		i = 0;
		while (n)
		{
			buff[i] = (n % 8) + '0';
			n /= 8;
			i++;
		}
		if (arg->flag_c[0])
			buff[i++] = '0';
		for (; i < arg->field_wd; i++)
			buff[i] = ' ';
		count = i;
		for (j = i - 1; j >= 0; j--)
			_putchar(buff[j]);
		free(buff);
	}
	else
	{
		for (i = 0; i < arg->field_wd - 1; i++)
			count += _putchar(' ');
		count += _putchar('0');
	}
	return (count);
}
