#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdarg.h>

/**
  * struct handler - Struct handler
  *
  * @cs: Character specifier
  * @func: The function associated
  */
typedef struct handler
{
	char *cs;
	int (*func)(va_list *);
} handler_t;

int _putchar(char c);
int handle_char(va_list *ap);
int handle_str(va_list *ap);
int handle_mod(va_list *ap);
int handle_int(va_list *ap);
int handle_dec(va_list *ap);
int handle_rev(va_list *ap);
int handle_bin(va_list *ap);
int handle_rot13(va_list *ap);
int handle_oct(va_list *ap);
int handle_udec(va_list *ap);
int handle_hex(va_list *ap);
int handle_heX(va_list *ap);
int handle_Str(va_list *ap);
int (*get_cs_handler(const char *cs))(va_list *);
int _printf(const char *format, ...);




#endif
