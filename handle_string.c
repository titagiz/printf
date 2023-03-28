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
 * @ap: Pointer to va_list
 *
 * Return: Number of characters printed
 */
int handle_s_S(char cs, va_list *ap)
{
	int i, count;
	char *s;

	s = va_arg(*ap, char *);
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
 * @ap: Pointer to va_list
 * @cs_mod: Structure of cs modifier
 *
 * Return: Number of characters printed
 */
int handle_str(va_list *ap, cs_modifier_t cs_mod)
{
	(void) cs_mod;
	return (handle_s_S('s', ap));
}
/**
 * handle_Str - handles 'S' conversion specifier
 * @ap: Pointer to va_list
 * @cs_mod: Structure of cs modifier
 *
 * Return: Number of characters printed
 */
int handle_Str(va_list *ap, cs_modifier_t cs_mod)
{
	(void) cs_mod;
	return (handle_s_S('S', ap));
}
