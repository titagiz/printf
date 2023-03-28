#include <stdarg.h>
#include "main.h"

/**
 * handle_mod - handles '%' conversion specifier
 * @ap: Pointer to va_list
 *
 * Return: Number of characters printed
 */
int handle_mod(va_list *ap)
{
	(void) ap;
	return (_putchar('%'));
}
