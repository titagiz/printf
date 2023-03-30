#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * char_to_hex - converts char to hex
 * @c: character to convert
 *
 * Return: None.
 */
void char_to_hex(char c)
{
	char tmp;

	_putchar('\\');
	_putchar('x');
	tmp = c / 16;
	if (tmp < 10)
		_putchar(tmp + 48);
	else
		_putchar(tmp + 55);
	tmp = c % 16;
	if (tmp < 10)
		_putchar(tmp + 48);
	else
		_putchar(tmp + 55);
}
/**
 * handle_S - handles 'S' conversion specifier
 * @s: string to print
 *
 * Return: Number of characters printed
 */
int handle_S(char *s)
{
	int i = 0, count = 0;

	while (s[i])
	{
		if (((s[i] > 0 && s[i] < 32) || s[i] >= 127))
		{
			char_to_hex(s[i]);
			count += 3;
		}
		else
		{
			_putchar(s[i]);
		}
		i++;
	}
	return (i + count);
}
/**
 * handle_s_S - handles 's' and 'S' conversion specifier
 * @arg: point to arguments structure
 *
 * Return: Number of characters printed
 */
int handle_s_S(arg_t *arg)
{
	int i, j, count;
	char *s;

	s = va_arg(*(arg->ap), char *);
	s = s ? s : "(null)";
	i = count = 0;
	if (*(arg->cs) == 'S')
	{
		i = handle_S(s);
	}
	else
	{
		if (arg->field_wd)
		{
			for (; s[i]; i++)
				arg->buff[i] = s[i];
			if (arg->field_wd > i)
				for (j = 0; j < arg->field_wd - i; j++)
					count += _putchar(' ');
			i = write(1, arg->buff, i);
		}
		else
		{
			while (s[i])
			{
				_putchar(s[i]);
				i++;
			}
		}
	}
	return (i + count);
}

