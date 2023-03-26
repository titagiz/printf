#ifndef MAIN_H
#define MAIN_H

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
int handle_dec(va_list d);
int (*get_cs_handler(const char *cs))(va_list *);
int _printf(const char *format, ...);




#endif
