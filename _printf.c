#include <stddef.h>
#include <stdarg.h>
#include "main.h"

/**
 * get_cs_modifers - identifies values provided between '%'-'cs'
 * @format: format string
 * @cs_mod: point to cs modifier structure
 *
 * Return: None
 */
const char *get_cs_modifers(const char *format, cs_modifier_t *cs_mod)
{
	cs_mod->flag_c[0] = cs_mod->flag_c[1] = cs_mod->flag_c[2] = 0;
	cs_mod->len_md[0] = cs_mod->len_md[1] = 0;

	while (*(format + 1) == '#' || *(format + 1) == '+'
			|| *(format + 1) == ' ')
	{
		if (*(format + 1) == '#')
			cs_mod->flag_c[0] = 1;
		if (*(format + 1) == '+')
			cs_mod->flag_c[1] = 1;
		if (*(format + 1) == ' ')
			cs_mod->flag_c[2] = 1;
		format++;
	}
	if (*(format + 1) == 'h')
	{
		cs_mod->len_md[0] = 1;
		format++;
	}
	else if (*(format + 1) == 'l')
	{
		cs_mod->len_md[1] = 1;
		format++;
	}
	return (format);
}
/**
 * handle_invalid_cs - prints string when invalid cs is found
 * @cs_mod: structure of cs modifier
 *
 * Return: number of chars
 */
int handle_invalid_cs(cs_modifier_t cs_mod)
{
	int nchars = 0;

	nchars += _putchar('%');
	nchars += cs_mod.flag_c[0] ? _putchar('#') : 0;
	nchars += cs_mod.flag_c[1] ? _putchar('+') : 0;
	nchars += !cs_mod.flag_c[1] && cs_mod.flag_c[2] ? _putchar(' ') : 0;

	return (nchars);
}
/**
 * _printf - produces output according to a format
 * @format: a character string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int nchar = 0;
	va_list ap;
	int (*fp)(va_list *, cs_modifier_t);
	cs_modifier_t cs_mod = {0};

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format = get_cs_modifers(format, &cs_mod);
			if (*(format + 1)  == '\0')
				return (-1);
			fp = get_cs_handler((format + 1));
			if (fp)
			{
				nchar += fp(&ap, cs_mod);
			}
			else
			{
				nchar += handle_invalid_cs(cs_mod);
				nchar += _putchar(*(format + 1));
			}
			format += 2;
		}
		else
		{
			nchar += _putchar(*format);
			format++;
		}
	}
	va_end(ap);
	return (nchar);
}
