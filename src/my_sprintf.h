#ifndef MY_SPRINTF_H
#define MY_SPRINTF_H

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "my_string.h"

typedef struct Specifiers {
  int c, d, i, e, E, f, g, G, o, s, u, x, X, p, n;
  int flag_plus;
  int flag_minus;
  int flag_ws;
  int flag_sharp;
  int flag_zero;
  int width_direct;
  int width_arg;
  int precision_direct;
  int precision_arg;
  int length_h;
  int length_l;
  int length_L;
  int found;
  int count_move;
  int has_precision;
  int mem_error;
} Spec;

int my_sprintf(char *, const char *, ...);

void get_specifier(const char *, va_list *, Spec *);
int search_for_flag(const char *, Spec *);
int search_for_width(const char *, va_list *, Spec *);
int precision_search(const char *, va_list *, Spec *);
int length_search(const char *, Spec *);
void search_for_spec(const char *, Spec *);

void handle_specifier(va_list *, Spec *, char *, int *);
void handle_int(va_list *, const Spec *, char *, int *);
void int_conditions(const Spec *, int *, char *, int *, char *);
void handle_uns_int(va_list *, const Spec *, char *, int *);
void uns_int_conditions(char *, const Spec *, char *, int *, int x);
void handle_char(va_list *, const Spec *, char *, int *);
void handle_string(va_list *, Spec *, char *, int *);
void handle_ptr(va_list *, Spec *, char *, int *);
void handle_floating_point(va_list *, Spec *, char *, int *);
void handle_n(const Spec *, va_list *, const int *);

void int_to_str(long long int *, char *);
void unsigned_int_to_str(unsigned long long const int *, char *, int, int);
void double_to_str(const Spec *, long double *, char *);
void short_decimal_to_string(Spec *, long double *, char *);
void handle_floating_point_E(Spec *, char *, long double *, char *, int *);

void exponent_to_string(const Spec *, long double *, char *);
void write_mantissa(long double *, char *);
int find_zeros(char *);

void fill_0x(const Spec *, const char *, char *, int *, int);
void write_wchar_string(Spec *, char *, int *, const wchar_t *);
void write_str(const Spec *, char *, const char *, int *);
char *str_null_fill();
void check_str_precision(const Spec *, int *);
void handle_width_before(const Spec *, char *, int *, int);
void handle_width_after(const Spec *, char *, int *, int);

void check_sign(long double *, char **);
void write_value(char *, char *, int *);

#endif