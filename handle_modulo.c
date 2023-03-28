#include <stdarg.h>
#include "main.h"

/**
 * handle_mod - handles '%' conversion specifier
 * @ap: Pointer to va_list
 * @cs_mod: Structure to cs modifier
 *
 * Return: Number of characters printed
 */
int handle_mod(__attribute__((unused)) va_list * ap,
		__attribute__((unused)) cs_modifier_t cs_mod)
{
	return (_putchar('%'));
}
