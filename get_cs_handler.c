#include <stddef.h>
#include <stdarg.h>
#include "main.h"

/**
 * get_cs_handler - selects the correct function to perform
 *                  the operation asked by the user
 * @cs: conversion specifier
 *
 * Return: a pointer to the function that corresponds to
 *         the operator given as a parameter
 */
int (*get_cs_handler(const char *cs))(va_list *)
{
	handler_t handler[] = {
		{"c", handle_char},
		{"s", handle_str},
		{"%", handle_mod},
		{"d", handle_dec},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (handler[i].cs)
	{
		if (*(handler[i].cs) == *cs)
			return (handler[i].func);
		i++;
	}
	return (NULL);
}
