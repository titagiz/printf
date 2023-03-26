#include "main.h"
/**
* handle_hex - function that prints an unsigned int in hexadecimal
* @n: unsigned to be printed
* @c: case of printing (0 = lower, 1 = upper)
* Descriptions: prints unsigned in hexadecimal with _putchar
* Return: size the output
*/
int handle_hex(unsigned int n, unsigned int c)
{
	unsigned int len, powten, j, digit, num;
	int count = 0;
	char diff;

	if (n != 0)
	{
		num = n;
		len = 0;
		if (c)
			diff = 'A' - ':';
		else
			diff = 'a' - ':';
		while (num != 0)
		{
			num /= 16;
			len++;
		}
		powten = 1;
		for (j = 1; j <= len - 1; j++)
			powten *= 16;
		for (j = 1; j <= len; j++)
		{
			digit = n / powten;
			if (digit < 10)
				_putchar(digit + '0');
			else
				_putchar(digit + '0' + diff);
			count++;
			n -= digit * powten;
			powten /= 16;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
/**
* handle_x - takes an unsigned int an prints it in lowercase hex
* @ap: Pointer to va_list
* Descriptions: prints in lowercase hex with _putchar
* Return: size of the output
*/
int handle_x(va_list *ap)
{
	return (print_hex(va_arg(*ap, unsigned int), 0));
}
/**
* handle_X - takes an unsigned int an prints it in uppercase hex
* @ap: Pointer to va_list
* Descriptions: prints in uppercase hex with _putchar
* Return: size of the output
*/
int handle_X(va_list *ap)
{
	return (print_hex(va_arg(*ap, unsigned int), 1));
}
