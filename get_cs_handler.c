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
	unsigned int i = 0;
	handler_t handler[] = {
		{"c", handle_char},
		{"s", handle_str},
		{"%", handle_mod},
		{"i", handle_int},
		{"d", handle_dec},
		{"b", handle_bin},
		{NULL, NULL};
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
