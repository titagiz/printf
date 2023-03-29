#include <stddef.h>
#include <stdarg.h>
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
	arg->len_md[0] = arg->len_md[1] = 0;

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
	if (*(format + 1) == 'h')
	{
		arg->len_md[0] = 1;
		format++;
	}
	else if (*(format + 1) == 'l')
	{
		arg->len_md[1] = 1;
		format++;
	}
	return (format);
}
/**
 * handle_invalid_cs - prints string when invalid cs is found
 * @arg: point to arguments structure
 *
 * Return: number of characters
 */
int handle_invalid_cs(arg_t *arg)
{
	int nchars = 0;

	nchars += _putchar('%');
	nchars += arg->flag_c[0] ? _putchar('#') : 0;
	nchars += arg->flag_c[1] ? _putchar('+') : 0;
	nchars += !arg->flag_c[1] && arg->flag_c[2] ? _putchar(' ') : 0;

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
	int (*fp)(arg_t *);
	arg_t arg = {0};

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	arg.ap = &ap;
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
			fp = get_cs_handler((format + 1));
			if (fp)
			{
				nchar += fp(&arg);
			}
			else
			{
				nchar += handle_invalid_cs(&arg);
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
