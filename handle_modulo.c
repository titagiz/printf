#include <stdarg.h>
#include "main.h"

/**
 * handle_mod - handles '%' conversion specifier
 * @ap: Pointer to va_list
 * @cs_mod: Structure to cs modifier
 *
 * Return: Number of characters printed
 */
int handle_od(va_list *ap, cs_modifier_t cs_mod)
{
	(void) ap;
	(void) cs_mod;
	return (_putchar('%'));
}
