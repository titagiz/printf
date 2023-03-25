#include <stdarg.h>
#include "main.h"

/**
 * handle_str - handles 's' conversion specifier
 * @ap: Pointer to va_list
 *
 * Return: Number of characters printed
 */
int handle_str(va_list *ap)
{
	int i;
	char *s;

	s = va_arg(*ap, char *);
	s = s ? s : "(null)";
	i = 0;
	while (s[i])
		_putchar(s[i++]);
	return (i);
}
