#include <stdarg.h>
#include "main.h"

/**
 * handle_udec - handles 'u' conversion specifier
 * @arg: point to arguments structure
 *
 * Return: Number of characters printed
 */
int handle_udec(arg_t *arg)
{
	unsigned long int powten, n, num;
	int len, j, digit, count = 0;

	n = arg->len_md[0] ? va_arg(*(arg->ap), unsigned long int) :
		arg->len_md[1] ?
		(unsigned short int)va_arg(*(arg->ap), unsigned int) :
		(unsigned int)va_arg(*(arg->ap), unsigned int);
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
			count += _putchar(digit + '0');
			n -= digit * powten;
			powten /= 10;
		}
	}
	else
	{
		count = _putchar('0');
	}
	return (count);
}
