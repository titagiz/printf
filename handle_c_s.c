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
	return (_putchar((unsigned char) va_arg(*ap, int)));
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
	s = s ? s : "(null)";
	i = 0;
	while (s[i])
	{
		_putchar(s[i++]);
	}
	return (i);
}
/**
 * per_hand - handles 's' conversion specifier
 * @ap: Pointer to va_list
 *
 * Return: Number of characters printed
 */
int per_hand(__attribute__((unused)) va_list *ap)
{
	_putchar('%');
	return (1);
}
