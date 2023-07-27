#ifndef MAIN_H_
#define MAIN_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>


#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

int fetch_precision(const char *format, int *i, va_list list);
int fetch_size(const char *format, int *i);
int team_putchar(char c);
int _printf(const char *format, ...);
int printer_nums(long int n);
int printing_strings(char *str);
int printing_binar(unsigned int num);
int printing_unknown_letter(char c);
int printing_unknownr(char c);
int printing_odh(char c, unsigned int num);
int deci_to_octal(unsigned int num);
int deci_to_hexxa(char c, unsigned int num);
int printing_S(char c);
int printing_reverses(char *s);
int printing_rot13(char *c);
int printing_pointers(void *p);
int team_puts(char *str);
int fetch_flag(const char *format, int *i);
int is_digit(char c);
int printing_str(const char *format, ...);

#endif
