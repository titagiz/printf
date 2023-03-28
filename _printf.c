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

	while (*(format + 1) == '#' || *(format + 1) == '+'
			|| *(format + 1) == ' ')
	{
		if (*(format + 1) == '#')
			cs_mod->flag_c[0] = 1;
		else if (*(format + 1) == '+')
			cs_mod->flag_c[1] = 1;
		else
			cs_mod->flag_c[2] = 1;
		format++;
	}
	return (format);
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
				nchar += _putchar('%');
				nchar += cs_mod.flag_c[0] ? _putchar('#') : 0;
				nchar += cs_mod.flag_c[1] ? _putchar('+') : 0;
				nchar += !cs_mod.flag_c[1] && cs_mod.flag_c[2] ?
					_putchar(' ') : 0;
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
