#include <stdarg.h>
#include "main.h"
/**
 *handle_rot13 - handles 'R' conversion specifier
 * @arg: point to arguments structure
 *
 * Return: Number of charcters printed
 */
int handle_rot13(arg_t *arg)
{
	int count = 0, i;
	char *r;

	r = va_arg(*(arg->ap), char *);
	
	if (r == NULL)
		return (-1);

	for (; *(r + count) != '\0'; count++)
		;

	for (i = 0; i < count; i++)
	{
		if ((r[i] >= 97 && r[i] <= 109) ||
		    (r[i] >= 65 && r[i] <= 77))
			_putchar(*(r + i) + 13);

		else if ((r[i] >= 110 && r[i] <= 122) ||
			 (r[i] >= 78 && r[i] <= 90))
			_putchar(*(r + i) - 13);

		else _putchar(r[i]);
	}

	return (count);
}
