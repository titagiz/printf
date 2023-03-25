#include <stdarg.h>
#include "main.h"

/**
  * handle_char - handles 'c' specifier
  * @ap: Pointer to va_list
  *
  * Return: 1
  */
int handle_char(va_list *ap)
{
	return (_putchar((unsigned char) va_arg(*ap, int)));
}
