#include <stdarg.h>
#include "main.h"

/**
 * handle_mod - handles '%' conversion specifier
 * @ap: Pointer to va_list
 *
 * Return: Number of characters printed
 */
int handle_mod(__attribute__((unused))va_list *ap)
{
	return (_putchar('%'));
}
