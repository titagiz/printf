#include <stddef.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_invalid_cs - prints string when invalid cs is found
 * @arg: point to arguments structure
 *
 * Return: number of characters
 */
int handle_invalid_cs(arg_t *arg)
{
	int nchars = 0;

	nchars += _putchar('%');
	nchars += arg->flag_c[0] ? _putchar('#') : 0;
	nchars += arg->flag_c[1] ? _putchar('+') : 0;
	nchars += !arg->flag_c[1] && arg->flag_c[2] ? _putchar(' ') : 0;

	return (nchars);
}
/**
 * get_cs_handler - selects the correct function to perform
 *                  the operation asked by the user
 * @arg: point to arg structure
 *
 * Return: Number of characters displayed
 */
int get_cs_handler(arg_t *arg)
{
	handler_t handler[] = {
		{"c", handle_char}, {"s", handle_s_S},   {"%", handle_mod},
		{"i", handle_dec},  {"d", handle_dec},   {"r", handle_rev},
		{"b", handle_bin},  {"R", handle_rot13}, {"o", handle_oct},
		{"u", handle_udec}, {"x", handle_hexX},  {"X", handle_hexX},
		{"S", handle_s_S},  {"p", handle_ptr},
		{NULL, NULL},
	};
	int i;

	i = 0;
	while (handler[i].cs)
	{
		if (*(handler[i].cs) == *(arg->cs))
			return (handler[i].func(arg));
		i++;
	}
	i = handle_invalid_cs(arg);
	i += _putchar(*(arg->cs + 1));
	return (i);
}
