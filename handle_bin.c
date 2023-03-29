#include <stdarg.h>
#include "main.h"
/**
 *handle_bin - handles 'b' conversion specifier
 * @arg: point to arguments structure
 *
 * Return: Number of characters printed
 */
int handle_bin(arg_t *arg)
{
	unsigned int len, powten, j, digit, n, num;
	int count = 0;

	n = va_arg(*(arg->ap), unsigned int);
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
		count = _putchar('0');
	}
	return (count);
}
