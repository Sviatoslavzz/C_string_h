#ifndef MY_SSCANF_H
#define MY_SSCANF_H

#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>

#include "my_string.h"

typedef struct MainKeys {
  int return_value, exit_flag, prev_ws, flag_parser_str, index_n, prev_percent,
      pars_count, mem_error;
} Keys;

typedef struct Specifiers {
  int c, d, i, e, E, f, g, G, o, s, u, x, X, p, n, f_ws, f_percent,
      f_read_format;
  int consume_record;
  int width;
  int length_h;
  int length_l;
  int length_L;
  int found;
  int count_move;
  int prev_ws;
  int return_value;
  int index_n;
  int pars_count;
  int my_infinity;
  int my_nan;
  int skip_percent;
  int mem_error;
  char* buffer;
  int exit_flag;
} Spec;

int my_sscanf(const char*, const char*, ...);
char* str_mem_alloc(Keys*, const char*);

void read_format(Spec*, char*, const char*, int*);
void sscanf_get_specifier(const char*, Spec*, char*, int*);
int sscanf_search_for_width(const char*, Spec*);
void sscanf_search_for_spec(const char*, Spec*);
int sscanf_length_search(const char*, Spec*);
char* sscanf_strtok(char*, Spec*);
char* strtok_str(int* flag_parser_str, char* str);
my_size_t strtok_parser_string(char* nextToken, Spec* spec);
my_size_t length_string(Spec* spec, char*);
void sscanf_decimal_power(const char*, int*, long double*);
int exit_condition(const char* str);

void sscanf_handle_specifier(va_list*, Spec*, char*, int*);
void sscanf_handle_int(va_list*, Spec*, const char*);
void sscanf_handle_uns_int(va_list*, Spec*, const char*);
void sscanf_handle_double(va_list*, Spec*, const char*);
void sscanf_handle_string(va_list*, Spec*, const char*);
void sscanf_handle_n(va_list*, const Spec*);
void sscanf_handle_char(va_list*, Spec*, const char*);

void sscanf_str_to_int(long long int*, const Spec*, const char*);
void sscanf_str_to_uns_int(unsigned long long int*, const Spec*, const char*,
                           int);

void sscanf_str_to_double(long double*, const char*);
void sscanf_handle_ptr(va_list*, Spec*, const char*);
int char_to_int(char);
void sscanf_str_to_i_int(long long int*, const Spec*, const char*);
void sscanf_handle_i_int(va_list*, Spec*, const char*);

my_size_t len_int(const char* str);
my_size_t find_inf(char*);
my_size_t find_nan(char*);

#endif