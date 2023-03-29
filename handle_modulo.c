#include <stdarg.h>
#include "main.h"

/**
 * handle_mod - handles '%' conversion specifier
 * @arg: point to arguments structure
 *
 * Return: Number of characters printed
 */
int handle_mod(arg_t *arg)
{
	(void) arg;
	return (_putchar('%'));
}
