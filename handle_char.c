#include <stdarg.h>
#include "main.h"

/**
  * handle_char - handles 'c' specifier
  *  @arg: point to arguments structure
  *
  * Return: 1
  */
int handle_char(arg_t *arg)
{
	return (_putchar((unsigned char) va_arg(*(arg->ap), int)));
}
