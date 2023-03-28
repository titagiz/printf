#include <stdarg.h>
#include "main.h"
/**
 * _chk_flag_chars - handles 'd' conversion specifier
 * @sign: Sign of the number
 * @cs_mod: Structure to cs modifier
 *
 * Return: Number of characters printed
 */
int _chk_flag_chars(int sign, cs_modifier_t cs_mod)
{
	int nchar = 0;

	if (sign && cs_mod.flag_c[1])
		nchar += _putchar('+');
	else if (sign && cs_mod.flag_c[2])
		nchar += _putchar(' ');
	return (nchar);
}
/**
 *handle_int - handles 'i' conversion specifier
 * @ap: Pointer to va_list
 * @cs_mod: structure of cs modifier
 *
 * Return: Number of characters printed
 */
int handle_int(va_list *ap, cs_modifier_t cs_mod)
{
	int len, powten, j, digit, n, count = 0, num, sign = 1;

	(void) cs_mod;
	n = va_arg(*ap, int);
	if (n != 0)
	{
		if (n < 0)
		{
			_putchar('-');
			count++;
			sign = 0;
		}
		num = n, len = 0;
		while (num != 0)
		{
			num /= 10;
			len++;
		}
		powten = 1;
		for (j = 1; j <= len - 1; j++)
			powten *= 10;
		count += _chk_flag_chars(sign, cs_mod);
		for (j = 1; j <= len; j++)
		{
			digit = n / powten;
			(n < 0) ? _putchar((digit * -1) + 48) :
				_putchar(digit + '0');
			count++;
			n -= digit * powten;
			powten /= 10;
		}
	}
	else
	{
		if (cs_mod.flag_c[2])
			count += _putchar(' ');
		count += _putchar('0');
	}
	return (count);
}
