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
	unsigned int j, i;
	int count = 0;
	char *r;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLM nopqrstuvwxyzabcdefghijklm";

	r = va_arg(*(arg->ap), char *);

	for (j = 0; r[j] != '\0'; j++)
	{
		for (i = 0; input[i] != '\0'; i++)
		{
			if (r[j] == input[i])
			{
				_putchar(output[i]);
				count++;
				break;
			}
		}
		if (!input[j])
		{
			_putchar(r[i]);
			count++;
		}
	}
		return (count);
}
