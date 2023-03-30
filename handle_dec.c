#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * handle_zero_value - handles zero value for 'd' conversion specifier
 * @arg: point to arguments structure
 *
 * Return: Number of characters printed
 */
int handle_zero_value(arg_t *arg)
{
	int nchar = 0, len = 0, i;

	if (arg->flag_c[1] || arg->flag_c[2])
		len = 2;
	else
		len = 1;
	for (i = 0; i < arg->field_wd - len; i++)
		nchar += _putchar(' ');
	if (arg->flag_c[1])
		nchar += _putchar('+');
	else if (arg->flag_c[2])
		nchar += _putchar(' ');
	nchar += _putchar('0');
	return (nchar);
}
/**
 * handle_none_zero_value - handles none zero value for 'd'
 * conversion specifier
 * @n: Number to print
 * @arg: point to arguments structure
 *
 * Return: Number of characters printed
 */
int handle_none_zero_value(long int n, arg_t *arg)
{
	long int num, powten;
	int len = 0, digit, j, i = 0;

	num = n;
	for (num = n; num; num /= 10, len++)
		;
	j = (n < 0 || arg->flag_c[1] || arg->flag_c[2]) ? 1 : 0;
	for (; i < arg->field_wd - len - j; i++)
		arg->buff[i] = ' ';
	if (n < 0)
	{
		arg->buff[i++] = '-';
	}
	else if (arg->flag_c[1] || arg->flag_c[2])
	{
		if (arg->flag_c[1])
			arg->buff[i++] = '+';
		else
			arg->buff[i++] = ' ';
	}
	powten = 1;
	for (j = 1; j <= len - 1; j++)
		powten *= 10;
	for (j = 0; j < len; j++, i++)
	{
		digit = n / powten;
		arg->buff[i] = (n < 0) ? (digit * -1) + '0' : digit + '0';
		n -= (digit * powten);
		powten /= 10;
	}
	return (write(1, arg->buff, i));
}
/**
 * handle_dec - handles 'd' conversion specifier
 * @arg: point to arguments structure
 *
 * Return: Number of characters printed
 */
int handle_dec(arg_t *arg)
{
	long int n;
	int count;

	n = arg->len_md[0] ? va_arg(*(arg->ap), long int) :
		arg->len_md[1] ? (short int)va_arg(*(arg->ap), int) :
		(int)va_arg(*(arg->ap), int);
	if (n != 0)
		count = handle_none_zero_value(n, arg);
	else
		count = handle_zero_value(arg);
	return (count);
}
