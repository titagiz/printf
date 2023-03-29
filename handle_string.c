#include <stdarg.h>
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
 * handle_s_S - handles 's' and 'S' conversion specifier
 * @cs: conversion specifier
 * @arg: point to arguments structure
 *
 * Return: Number of characters printed
 */
int handle_s_S(char cs, arg_t *arg)
{
	int i, count;
	char *s;

	s = va_arg(*(arg->ap), char *);
	s = s ? s : "(null)";
	i = count = 0;
	while (s[i])
	{
		if (cs == 'S' && ((s[i] > 0 && s[i] < 32) || s[i] >= 127))
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
 * handle_str - handles 's' conversion specifier
 * @arg: point to arguments structure
 *
 * Return: Number of characters printed
 */
int handle_str(arg_t *arg)
{
	return (handle_s_S('s', arg));
}
/**
 * handle_Str - handles 'S' conversion specifier
 * @arg: point to arguments structure
 *
 * Return: Number of characters printed
 */
int handle_Str(arg_t *arg)
{
	return (handle_s_S('S', arg));
}
