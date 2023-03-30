#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
  * handle_char - handles 'c' specifier
  *  @arg: point to arguments structure
  *
  * Return: Number of chars printed
  */
int handle_char(arg_t *arg)
{
	int i = 0;

	if (arg->field_wd > 1)
	{
		for (i = 0; i < arg->field_wd - 1; i++)
			arg->buff[i] = ' ';
		arg->buff[i] = (unsigned char) va_arg(*(arg->ap), int);
	}
	else
		arg->buff[i] = (unsigned char) va_arg(*(arg->ap), int);
	return (write(1, arg->buff, i + 1));
}
