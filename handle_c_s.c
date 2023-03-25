#include <stdarg.h>
#include "main.h"

/**
  * c_hand - handles 'c' specifier
  * @ap: Pointer to va_list
  *
  * Return: 1
  */
int c_hand(va_list *ap)
{
	return (_putchar(va_arg(*ap, int)));
}
/**
 * s_hand - handles 's' conversion specifier
 * @ap: Pointer to va_list
 *
 * Return: Number of characters printed
 */
int s_hand(va_list *ap)
{
	int i;
	char *s;

	s = va_arg(*ap, char *);
	i = 0;
	while (s[i])
	{
		_putchar(s[i++]);
	}
	return (i);
}
