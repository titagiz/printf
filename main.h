#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdarg.h>

/**
  * struct cs_modifier - struct for flag characters, field withd
  * precision, length modifier...
  *
  * @flag_c: Flag characters
  *          flag_c[0] for '#'
  *          flag_c[1] for '+'
  *          flag_c[2] for ' '
  * @len_md: Length modifier
  *          len_md[0] for 'h'
  *          len_md[1] for 'l'
  */
typedef struct cs_modifier
{
	char flag_c[3];
	char len_md[2];
} cs_modifier_t;

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
int handle_ptr(va_list *ap);
int (*get_cs_handler(const char *cs))(va_list *);
int _printf(const char *format, ...);




#endif
