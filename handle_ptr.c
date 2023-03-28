#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_ptr - handles 'p' conversion specifier
 * @ap: Pointer to va_list
 *
 * Return: Number of characters printed
 */
int handle_ptr(va_list *ap)
{
	void *ptr;
	unsigned long n;
	int i, j, count = 5;
	char *buff, tmp;

	ptr  =  va_arg(*ap, void *);
	if (ptr)
	{
		buff = malloc(16);
		if (!buff)
			return (0);
		n = (unsigned long) ptr;
		i = 0;
		_putchar('0');
		_putchar('x');
		while (n != 0)
		{
			tmp = n % 16;
			if (tmp < 10)
				tmp += 48;
			else
				tmp += 87;
			buff[i++] = tmp;
			n /= 16;
		}
		count = i + 2;
		for (j = i - 1; j >= 0; j--)
			_putchar(buff[j]);
		free(buff);
	}
	else
	{
		_putchar('(');
		_putchar('n');
		_putchar('i');
		_putchar('l');
		_putchar(')');
	}
	return (count);
}
