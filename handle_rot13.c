#include <stdarg.h>
#include "main.h"
/**
 *handle_rot13 - handles 'R' conversion specifier
 * @ap: Pointers to va_list
 *
 * Return: Number of charcters printed
 */
int handle_rot13(va_list *ap)
{
	int j, i, count = 0;
	char *r;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLM nopqrstuvwxyzabcdefghijklm";

	r = va_arg(*ap, char *);

	if (r == NULL)
		r = "(AHYY)";
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
		if (!input[i])
		{
			_putchar(r[i]);
			count++;
		}
	}
		return (count);
}
