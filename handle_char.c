#include <stdarg.h>
#include "main.h"

/**
  * handle_char - handles 'c' specifier
  * @ap: Pointer to va_list
  * @cs_mod: structure to cs modifier
  *
  * Return: 1
  */
int handle_char(va_list *ap, cs_modifier_t cs_mod)
{
	(void) cs_mod;
	return (_putchar(va_arg(*ap, int)));
}
