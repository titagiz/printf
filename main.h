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
  */
typedef struct cs_modifier
{
	char flag_c[3];
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
	int (*func)(va_list *, cs_modifier_t);
} handler_t;

int _putchar(char c);
int handle_char(va_list *ap, cs_modifier_t cs_mod);
int handle_str(va_list *ap, cs_modifier_t cs_mod);
int handle_mod(va_list *ap, cs_modifier_t cs_mod);
int handle_int(va_list *ap, cs_modifier_t cs_mod);
int handle_dec(va_list *ap, cs_modifier_t cs_mod);
int handle_rev(va_list *ap, cs_modifier_t cs_mod);
int handle_bin(va_list *ap, cs_modifier_t cs_mod);
int handle_rot13(va_list *ap, cs_modifier_t cs_mod);
int handle_oct(va_list *ap, cs_modifier_t cs_mod);
int handle_udec(va_list *ap, cs_modifier_t cs_mod);
int handle_hex(va_list *ap, cs_modifier_t cs_mod);
int handle_heX(va_list *ap, cs_modifier_t cs_mod);
int handle_Str(va_list *ap, cs_modifier_t cs_mod);
int handle_ptr(va_list *ap, cs_modifier_t cs_mod);
int (*get_cs_handler(const char *cs))(va_list *, cs_modifier_t);
int _printf(const char *format, ...);




#endif
