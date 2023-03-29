#include <stdarg.h>
#include "main.h"
/**
 *handle_rev - handles 'r' conversion specifier
 * @arg: point to arguments structure
 *
 * Return: Number of characters printed
 */
int handle_rev(arg_t *arg)
{
	char *st;
	int i, j = 0;

	st = va_arg(*(arg->ap), char *);
	if (st == NULL)
		st = ")llun(";
	for (i = 0; st[i] != '\0'; i++)
		;
	for (i -= 1 ; i >= 0; i--)
	{
		_putchar(st[i]);
		j++;
	}
	return (j);
}
