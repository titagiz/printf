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
	int j, i, count = 0;
	int k = 0;
	char *r;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLM nopqrstuvwxyzabcdefghijklm";

	r = va_arg(*(arg->ap), char *);

	if (r == NULL)
		r = "(null)";
	for (j = 0; r[j]; j++)
	{
		k = 0;
		for (i = 0; input[i] && !k; i++)
		{
			if (r[j] == input[i])
			{
				_putchar(output[i]);
				count++;
				k = 1;
			}
		}
		if (!k)
		{
			_putchar(r[i]);
			count++;
		}
	}
		return (count);
}
