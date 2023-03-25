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
int c_hand(va_list *ap);
int s_hand(va_list *ap);
int per_hand(va_list *ap);
int (*get_cs_handler(const char *cs))(va_list *);
int _printf(const char *format, ...);




#endif
