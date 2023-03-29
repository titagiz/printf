#include <stdarg.h>
#include "main.h"

/**
 * chk_flag_chars - handles 'd' conversion specifier
 * @sign: Sign of the number
 * @arg: point to arguments structure
 *
 * Return: Number of characters printed
 */
int chk_flag_chars(int sign, arg_t *arg)
{
	int nchar = 0;

	if (sign && arg->flag_c[1])
		nchar += _putchar('+');
	else if (sign && arg->flag_c[2])
		nchar += _putchar(' ');
	return (nchar);
}
/**
 * handle_dec - handles 'd' conversion specifier
 * @arg: point to arguments structure
 *
 * Return: Number of characters printed
 */
int handle_dec(arg_t *arg)
{
	long int powten, n, num;
	int len, j, digit, count = 0, sign = 1;

	n = arg->len_md[0] ? va_arg(*(arg->ap), long int) :
		arg->len_md[1] ? (short int)va_arg(*(arg->ap), int) :
		(int)va_arg(*(arg->ap), int);
	if (n != 0)
	{
		if (n < 0)
		{
			count += _putchar('-');
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
		count += chk_flag_chars(sign, arg);
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
		count = chk_flag_chars(1, arg);
		count += _putchar('0');
	}
	return (count);
}
