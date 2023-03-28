#include <stdarg.h>
#include "main.h"
/**
 *handle_rev - handles 'r' conversion specifier
 * @ap: Pointer to va_list
 * @cs_mod: Structure of cs modifier
 *
 * Return: Number of characters printed
 */
int handle_rev(va_list *ap, cs_modifier_t cs_mod)
{
	char *st;
	int i, j = 0;

	(void) cs_mod;
	st = va_arg(*ap, char *);
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
