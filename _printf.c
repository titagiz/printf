#include <stddef.h>
#include <stdarg.h>
#include "main.h"

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
	int (*fp)(va_list *);

	if (format == NULL)
		return (0);

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			fp = get_cs_handler((format + 1));
			if (fp)
			{
				nchar += fp(&ap);
			}
			else
			{
				if (*(format + 1) != '%')
					nchar += _putchar(*format);
				nchar += _putchar(*(format + 1));
			}
		}
		else
		{
			nchar += _putchar(*format++);
		}
		format += 2;
	}
	va_end(ap);
	return (nchar);
}
