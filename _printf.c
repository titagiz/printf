#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * get_cs_modifers - identifies values provided between '%'-'cs'
 * @format: format string
 * @arg: point to arguments structure
 *
 * Return: None
 */
const char *get_cs_modifers(const char *format, arg_t *arg)
{
	arg->flag_c[0] = arg->flag_c[1] = arg->flag_c[2] = 0;
	arg->len_md[0] = arg->len_md[1] = 0, arg->field_wd = 0;

	while (*(format + 1) == '#' || *(format + 1) == '+'
			|| *(format + 1) == ' ')
	{
		if (*(format + 1) == '#')
			arg->flag_c[0] = 1;
		if (*(format + 1) == '+')
			arg->flag_c[1] = 1;
		if (*(format + 1) == ' ')
			arg->flag_c[2] = 1;
		format++;
	}
	if (*(format + 1) == '*')
	{
		arg->field_wd = va_arg(*(arg->ap), int);
		format++;
	}
	else if (*(format + 1) > '0' && *(format + 1) <= '9')
	{
		arg->field_wd = *(format + 1) - '0';
		format++;
	}
	if (*(format + 1) == 'l')
	{
		arg->len_md[0] = 1;
		format++;
	}
	else if (*(format + 1) == 'h')
	{
		arg->len_md[1] = 1;
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
	arg_t arg = {0};
	char *buff;

	if (format == NULL)
		return (-1);
	buff = malloc(1024);
	if (!buff)
		return (-1);
	va_start(ap, format);
	arg.ap = &ap;
	arg.buff = buff;
	while (*format)
	{
		if (*format == '%')
		{
			format = get_cs_modifers(format, &arg);
			if (*(format + 1)  == '\0')
			{
				nchar = -1;
				break;
			}
			arg.cs = (format + 1);
			nchar += get_cs_handler(&arg);
			format += 2;
		}
		else
		{
			nchar += _putchar(*format);
			format++;
		}
	}
	va_end(ap);
	free(buff);
	return (nchar);
}
