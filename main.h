#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdarg.h>

/**
  * struct arg - struct for va_list, flag characters, field withd
  * precision, length modifier...
  *
  * @ap: Pointer to va_list
  * @flag_c: Flag characters
  *          flag_c[0] for '#'
  *          flag_c[1] for '+'
  *          flag_c[2] for ' '
  * @len_md: Length modifier
  *          len_md[0] for 'l'
  *          len_md[1] for 'h'
  */
typedef struct arg
{
	va_list *ap;
	char flag_c[3];
	char len_md[2];
} arg_t;

/**
  * struct handler - Struct handler
  *
  * @cs: Character specifier
  * @func: The function associated
  */
typedef struct handler
{
	char *cs;
	int (*func)(arg_t *);
} handler_t;

int _putchar(char c);
int handle_char(arg_t *arg);
int handle_str(arg_t *arg);
int handle_mod(arg_t *arg);
int handle_int(arg_t *arg);
int handle_dec(arg_t *arg);
int handle_rev(arg_t *arg);
int handle_bin(arg_t *arg);
int handle_rot13(arg_t *arg);
int handle_oct(arg_t *arg);
int handle_udec(arg_t *arg);
int handle_hex(arg_t *arg);
int handle_heX(arg_t *arg);
int handle_Str(arg_t *arg);
int handle_ptr(arg_t *arg);
int (*get_cs_handler(const char *cs))(arg_t *);
int _printf(const char *format, ...);




#endif
