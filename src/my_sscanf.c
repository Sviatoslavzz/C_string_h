#include "my_sscanf.h"

int my_sscanf(const char* str_orig, const char* format, ...) {
  Keys keys = {0};
  char* str = str_mem_alloc(&keys, str_orig);
  va_list args;
  va_start(args, format);
  while (*format && keys.exit_flag != 2 && !keys.mem_error) {
    Spec spec = {0};
    if (*format == '%' && !keys.exit_flag) {
      keys.exit_flag = 1;
      spec.found = 1;
      spec.index_n = keys.index_n;
      spec.prev_ws = keys.prev_ws;
      spec.pars_count = keys.pars_count;
      sscanf_get_specifier(format, &spec, str, &keys.flag_parser_str);
      if (spec.found) {
        sscanf_handle_specifier(&args, &spec, str, &keys.flag_parser_str);
        keys.index_n = spec.index_n;
        format += spec.count_move;
        keys.return_value += spec.return_value;
        keys.exit_flag = spec.exit_flag;
        keys.prev_ws = 0;
        keys.pars_count = spec.pars_count ? spec.pars_count : keys.pars_count;
      }
      if (spec.skip_percent == 1) {
        format += spec.count_move;
        keys.prev_ws = 0;
        keys.exit_flag = 0;
      } else if (spec.skip_percent == 2) {
        keys.exit_flag = 2;
      }
    } else if (*format == ' ' || *format == '\t' || *format == '\n' ||
               *format == '\v' || *format == '\f' || *format == '\r') {
      keys.prev_ws = 1;
      keys.exit_flag = 0;
    } else {
      spec.prev_ws = keys.prev_ws;
      read_format(&spec, str, format, &keys.flag_parser_str);
      keys.mem_error = spec.mem_error;
      keys.exit_flag = spec.exit_flag;
      keys.index_n += spec.count_move + 1;
      format += spec.count_move;
    }
    format++;
  }
  va_end(args);
  if (!keys.mem_error) free(str);
  return keys.return_value;
}

char* str_mem_alloc(Keys* keys, const char* str_orig) {
  char* str = calloc(my_strlen(str_orig) + 1, sizeof(char));
  if (!str) {
    printf("Memory allocation error function <str_mem_alloc>\n");
    keys->mem_error++;
  } else {
    my_memcpy(str, str_orig, my_strlen(str_orig));
    str[my_strlen(str_orig)] = '\0';
  }
  return str;
}

void read_format(Spec* spec, char* str, const char* format, int* f_p_str) {
  spec->buffer = MY_NULL;
  spec->buffer = malloc(((int)my_strlen(format) + 1) * sizeof(char));
  if (spec->buffer) {
    char* p_buffer = spec->buffer;
    while (*format != '\0' && *format != '%' && *format != ' ' &&
           *format != '\t' && *format != '\n' && *format != '\v' &&
           *format != '\f' && *format != '\r') {
      *p_buffer++ = *format++;
      spec->count_move++;
    }
    spec->count_move--;
    *p_buffer = '\0';
    spec->f_read_format++;
    if (my_strncmp(sscanf_strtok(strtok_str(f_p_str, str), spec), spec->buffer,
                   my_strlen(spec->buffer)) == 0) {
      spec->exit_flag = 0;
    } else {
      spec->exit_flag = 2;
    }
    free(spec->buffer);
  } else {
    printf("Memory allocation error: function <read_format>\n");
    spec->mem_error++;
  }
}

void sscanf_get_specifier(const char* format, Spec* spec, char* str,
                          int* f_pars) {
  format++;
  spec->count_move = 1;
  if (*format == '%') {
    spec->found = 0;
    spec->f_percent++;
    const char* s_percent = sscanf_strtok(strtok_str(f_pars, str), spec);
    if (!s_percent) {
    } else {
      if (*s_percent != '%') {
        spec->skip_percent = 2;
      } else {
        spec->f_ws++;
        sscanf_strtok(strtok_str(f_pars, str), spec);
        spec->skip_percent = 1;
      }
    }
  } else {
    if (*format == '*') {
      spec->consume_record++;
      spec->count_move++;
      format++;
    }
    if (!spec->consume_record) {
      format += sscanf_search_for_width(format, spec);
    }
    format += sscanf_length_search(format, spec);
    sscanf_search_for_spec(format, spec);
  }
}

int sscanf_search_for_width(const char* format, Spec* spec) {
  const char* p = format;
  while (1) {
    if (*p == '0') {
      spec->width *= 10;
    } else if (*p >= 49 && *p <= 57) {
      if (spec->width) spec->width *= 10;
      spec->width += *p - '0';
    } else {
      break;
    }
    p++;
    spec->count_move++;
  }
  return p - format;
}

int sscanf_length_search(const char* format, Spec* spec) {
  const char* p = format;
  if (*p == 'h') {
    spec->length_h++;
    p++;
    spec->count_move++;
    if (*p == 'h') {
      spec->length_h++;
      p++;
      spec->count_move++;
    }
  } else if (*p == 'l') {
    spec->length_l++;
    p++;
    spec->count_move++;
    if (*p == 'l') {
      spec->length_l++;
      p++;
      spec->count_move++;
    }
  } else if (*p == 'L') {
    spec->length_L++;
    p++;
    spec->count_move++;
  }
  return p - format;
}

void sscanf_search_for_spec(const char* format, Spec* spec) {
  if (*format == 'c') {
    spec->c++;
  } else if (*format == 'd') {
    spec->d++;
  } else if (*format == 'i') {
    spec->i++;
  } else if (*format == 'e') {
    spec->e++;
  } else if (*format == 'E') {
    spec->E++;
  } else if (*format == 'f') {
    spec->f++;
  } else if (*format == 'g') {
    spec->g++;
  } else if (*format == 'G') {
    spec->G++;
  } else if (*format == 'o') {
    spec->o++;
  } else if (*format == 's') {
    spec->s++;
  } else if (*format == 'u') {
    spec->u++;
  } else if (*format == 'x') {
    spec->x++;
  } else if (*format == 'X') {
    spec->X++;
  } else if (*format == 'p') {
    spec->p++;
  } else if (*format == 'n') {
    spec->n++;
  } else {
    spec->found = 0;
  }
}

int exit_condition(const char* str) {
  int result = 0;
  result = (my_strlen(str) == 1 &&
            (*str == '-' || *str == '+' || *str == '.' || *str == 'e' ||
             *str == 'E' || *str == 'x' || *str == 'X'));
  result += (my_strlen(str) > 1 && (*str == '-' && *(str + 1) == '-'));
  result += (my_strlen(str) > 1 && (*str == '+' && *(str + 1) == '-'));
  result += (my_strlen(str) > 1 && (*str == '-' && *(str + 1) == '+'));
  result += (my_strlen(str) > 1 && (*str == '+' && *(str + 1) == '+'));
  result += (my_strlen(str) == 2 && (*str == '-' && *(str + 1) == '.'));
  result += (my_strlen(str) == 2 && (*str == '+' && *(str + 1) == '.'));
  result += (my_strlen(str) == 2 && (*str == '+' && *(str + 1) == 'x'));
  result += (my_strlen(str) == 2 && (*str == '+' && *(str + 1) == 'X'));
  result += (my_strlen(str) == 2 && (*str == '-' && *(str + 1) == 'x'));
  result += (my_strlen(str) == 2 && (*str == '-' && *(str + 1) == 'X'));
  result += (my_strlen(str) > 1 && (*str == '.' && *(str + 1) == '-'));
  result += (my_strlen(str) > 1 && (*str == '.' && *(str + 1) == '+'));
  result += (my_strlen(str) > 1 && (*str == '0' && *(str + 1) == 'x') &&
             *(str + 2) == 'X');
  result += (my_strlen(str) > 1 && (*str == '0' && *(str + 1) == 'X') &&
             *(str + 2) == 'x');
  result += (my_strlen(str) > 1 && (*str == 'e' || *str == 'E'));

  return result;
}

void sscanf_handle_specifier(va_list* args, Spec* spec, char* str,
                             int* flag_parser_str) {
  const char* tmp = MY_NULL;
  if (!spec->n) {
    tmp = sscanf_strtok(strtok_str(flag_parser_str, str), spec);
    int ex_cond = 0;
    if (spec->d || spec->i || spec->x || spec->X || spec->o || spec->u ||
        spec->f || spec->e || spec->E || spec->g || spec->G || spec->p)
      ex_cond = exit_condition(tmp);
    if (ex_cond || !my_strlen(tmp)) spec->exit_flag = 2;
  }
  if (!spec->consume_record && spec->exit_flag != 2) {
    if (spec->d) {
      sscanf_handle_int(args, spec, tmp);
    }
    if (spec->i) {
      sscanf_handle_i_int(args, spec, tmp);
    }
    if (spec->x || spec->X || spec->o) {
      sscanf_handle_uns_int(args, spec, tmp);
    }
    if (spec->u) {
      sscanf_handle_uns_int(args, spec, tmp);
    }
    if (spec->f || spec->e || spec->E || spec->g || spec->G) {
      sscanf_handle_double(args, spec, tmp);
    }
    if (spec->p) {
      spec->length_l = 1;
      sscanf_handle_ptr(args, spec, tmp);
    }
    if (spec->c) sscanf_handle_char(args, spec, tmp);
    if (spec->s) sscanf_handle_string(args, spec, tmp);
    if (spec->n) {
      if (spec->prev_ws) {
        spec->f_ws++;
        sscanf_strtok(strtok_str(flag_parser_str, str), spec);
      }
      sscanf_handle_n(args, spec);
    }
  }
}

void sscanf_handle_int(va_list* args, Spec* spec, const char* str) {
  const char* p_buff = str;
  long long int num = 0;
  sscanf_str_to_int(&num, spec, p_buff);
  if (spec->length_L || spec->length_l == 2) {
    long long int* i = va_arg(*args, long long int*);
    *i = num;
  } else if (spec->length_l == 1) {
    long int* i = va_arg(*args, long int*);
    *i = (long int)num;
  } else if (spec->length_h) {
    short int* i = va_arg(*args, short int*);
    *i = (short int)num;
  } else {
    int* i = va_arg(*args, int*);
    *i = (int)num;
  }
  spec->return_value++;
}

void sscanf_handle_i_int(va_list* args, Spec* spec, const char* str) {
  int flag_x = 0, hex_char = 0, math = 0;
  my_size_t len_int_str = 0;
  const char* p_buff_2 = str;
  const char* p_buff = MY_NULL;
  if (*p_buff_2 == '+' || *p_buff_2 == '-') {
    p_buff_2++;
    math = 1;
  }
  if (*p_buff_2 == 'x' || *p_buff_2 == 'X') {
    flag_x = 1;
  } else if (*p_buff_2 != '0' && *(p_buff_2 + 1) != 'x' &&
             *(p_buff_2 + 1) != 'X' && !spec->width) {
    len_int_str = len_int(p_buff_2);
    if (!my_strchr("0123456789", *p_buff_2)) hex_char = 1;
    if (len_int_str)
      p_buff = my_strtok((char*)str, &str[len_int_str + (math ? 1 : 0)]);
  }
  if (!flag_x && !hex_char) {
    if (!len_int_str) p_buff = (char*)str;
    long long int num = 0;
    sscanf_str_to_i_int(&num, spec, p_buff);
    if (spec->length_l == 2) {
      long long int* i = va_arg(*args, long long int*);
      *i = num;
    } else if (spec->length_l == 1) {
      long int* i = va_arg(*args, long int*);
      *i = (long int)num;
    } else if (spec->length_h == 1) {
      short int* i = va_arg(*args, short int*);
      *i = (short int)num;
    } else if (spec->length_h == 2) {
      signed char* i = (signed char*)va_arg(*args, int*);
      *i = (signed char)num;
    } else {
      int* i = va_arg(*args, int*);
      *i = (int)num;
    }
    spec->return_value++;
  }
}

void sscanf_str_to_int(long long int* num, const Spec* spec, const char* str) {
  int i = 0, sign = 1, status = 1;
  if (str[i] == '+' || str[i] == '-') {
    if (str[i] == '-') {
      sign = -1;
    }
    i++;
  }
  while (str[i] && status) {
    int digit = char_to_int(str[i]);
    if (spec->length_l == 0 && !spec->length_L &&
        *num > (LONG_MAX - digit) / 10) {
      *num = (sign == -1) ? 0 : -1;
      status = 0;
    }
    if (spec->length_l == 1 && *num > (LONG_MAX - digit) / 10) {
      *num = (sign == 1) ? LONG_MAX : LONG_MIN;
      status = 0;
    } else if ((spec->length_l == 2 || spec->length_L) &&
               *num > (LLONG_MAX - digit) / 10) {
      *num = (sign == 1) ? LLONG_MAX : LLONG_MIN;
      status = 0;
    }
    if (status) {
      *num = *num * 10 + digit;
      i++;
    }
  }
  *num = *num * sign;
}

void sscanf_handle_uns_int(va_list* args, Spec* spec, const char* str) {
  int div = 10;
  const char* p_buff = str;
  if (spec->o) div = 8;
  if (spec->x || spec->X) div = 16;
  unsigned long long int num = 0;
  sscanf_str_to_uns_int(&num, spec, p_buff, div);
  if (spec->length_l == 2) {
    unsigned long long int* i = va_arg(*args, unsigned long long int*);
    *i = num;
  } else if (spec->length_l == 1) {
    unsigned long int* i = va_arg(*args, unsigned long int*);
    *i = (unsigned long int)num;
  } else if (spec->length_h == 1) {
    unsigned short int* i = va_arg(*args, unsigned short int*);
    *i = (unsigned short)num;
  } else if (spec->length_h == 2) {
    unsigned char* i = (unsigned char*)va_arg(*args, unsigned int*);
    *i = (unsigned char)num;
  } else {
    unsigned int* i = va_arg(*args, unsigned int*);
    *i = (unsigned int)num;
  }
  spec->return_value++;
}

void sscanf_handle_ptr(va_list* args, Spec* spec, const char* str) {
  if (!(*str == 'x' || *str == 'X')) {
    unsigned long long int num = 0;
    sscanf_str_to_uns_int(&num, spec, str, 16);
    unsigned long int* ptr = va_arg(*args, unsigned long int*);
    *ptr = num;
    spec->return_value++;
  }
}

void sscanf_handle_char(va_list* args, Spec* spec, const char* str) {
  if (spec->length_l) {
    wchar_t* sym = va_arg(*args, wchar_t*);
    sym[0] = (wchar_t)str[0];
  } else {
    char* sym = (char*)va_arg(*args, int*);
    *sym = *str;
  }
  spec->return_value++;
}

int char_to_int(char c) {
  int result = -1;
  if (c >= '0' && c <= '9') {
    result = c - '0';
  } else if (c >= 'a' && c <= 'f') {
    result = c - 'a' + 10;
  } else if (c >= 'A' && c <= 'F') {
    result = c - 'A' + 10;
  }
  return result;
}

my_size_t len_int(const char* str) {
  const char tokens[] = "-+0123456789";
  my_size_t result = 0;
  int flag = 0;
  while (str != MY_NULL && *str != '\0' && !flag) {
    if (my_strchr(tokens, *str))
      result++;
    else if (!my_strchr(tokens, *str))
      flag = 1;
    str++;
  }
  return result;
}

void sscanf_str_to_i_int(long long int* num, const Spec* spec,
                         const char* str) {
  int sign = 1, status = 1, div = 10;
  if (*str == '+' || *str == '-') {
    if (*str == '-') sign = -1;
    str++;
  }
  if (*str == '0') {
    div = 8;
    str++;
    if (*str == 'x' || *str == 'X') {
      div = 16;
      str++;
    }
  }
  long long max_div = LLONG_MAX / div;
  while (*str && status) {
    int digit = char_to_int(*str);
    if (digit >= div) status = 0;
    if (spec->length_l == 0) {
      if (*num > max_div ||
          (*num == max_div && (long int)digit > LONG_MAX % div)) {
        *num = (sign == 1) ? LONG_MAX : LONG_MIN;
        status = 0;
      }
    } else if (spec->length_l == 1) {
      if (*num > (LONG_MAX - digit) / div) {
        *num = (sign == 1) ? LONG_MAX : LONG_MIN;
        status = 0;
      }
    } else if (spec->length_l == 2) {
      if (*num > max_div ||
          (*num == max_div && (long long int)digit > LLONG_MAX % div)) {
        *num = (sign == 1) ? LLONG_MAX : LLONG_MIN;
        status = 0;
      }
    }
    if (status) {
      *num = *num * div + digit;
      str++;
    }
  }
  *num = *num * sign;
}

void sscanf_str_to_uns_int(unsigned long long int* num, const Spec* spec,
                           const char* str, int div) {
  int status = 1, sign = 1;
  if (*str == '+' || *str == '-') {
    if (*str == '-') sign = -1;
    str++;
  }
  if (*str == '0') {
    str++;
    if (*str == 'x' || *str == 'X') str++;
  }
  unsigned long long max_div = ULLONG_MAX / div;
  while (*str && status) {
    int digit = char_to_int(*str);
    if (spec->length_l == 0) {
      if (*num > max_div ||
          (*num == max_div && (unsigned long int)digit > ULONG_MAX % div)) {
        *num = UINT_MAX;
        status = 0;
      }
    } else if (spec->length_l == 1) {
      if (*num > max_div ||
          (*num == max_div && (unsigned long int)digit > ULONG_MAX % div)) {
        *num = ULONG_MAX;
        status = 0;
      }
    } else if (spec->length_l == 2) {
      if (*num > max_div || (*num == max_div && (unsigned long long int)digit >
                                                    ULLONG_MAX % div)) {
        *num = ULLONG_MAX;
        status = 0;
      }
    }
    if (status) {
      *num = *num * div + digit;
      str++;
    }
  }
  *num = (unsigned long long)(*num * sign);
}

void sscanf_handle_double(va_list* args, Spec* spec, const char* str) {
  long double num = 0;
  if (spec->my_infinity) {
    if (spec->my_infinity == 1) num = INFINITY;
    if (spec->my_infinity == 2) num = -INFINITY;
  } else if (spec->my_nan) {
    num = NAN;
  } else {
    const char* p_buff = str;
    sscanf_str_to_double(&num, p_buff);
  }
  if (spec->length_L) {
    long double* i = va_arg(*args, long double*);
    *i = num;
  } else if (spec->length_l) {
    double* i = va_arg(*args, double*);
    *i = (double)num;
  } else {
    float* i = va_arg(*args, float*);
    *i = (float)num;
  }
  spec->return_value++;
}

void sscanf_str_to_double(long double* num, const char* str) {
  int i = 0, sign = 1;
  int degree = -1;
  long double right = 0;
  if (str[i] == '+' || str[i] == '-') {
    if (str[i] == '-') {
      sign = -1;
    }
    i++;
  }
  while (str[i] && degree < 4933 &&
         (str[i] >= '0' && str[i] <= '9' && str[i] != '.')) {
    *num = *num * 10 + (str[i] - '0');
    i++;
    degree++;
  }
  if (degree == 4932) {
    *num = (sign == 1) ? LDBL_MAX : LDBL_MIN;
  } else if (degree > 4932) {
    *num = INFINITY;
  }
  if (str[i] == '.' && degree < 21) {
    i++;
    int j = 0;
    while (str[i] && (str[i] >= '0' && str[i] <= '9')) {
      right = right * 10 + (str[i] - '0');
      i++;
      j++;
    }
    for (int k = 0; k < j; k++) {
      right /= 10;
    }
  }
  *num = (*num + right) * sign;
  sscanf_decimal_power(str, &i, num);
}

void sscanf_decimal_power(const char* str, int* i, long double* num) {
  if (str[(*i)] == 'e' || str[(*i)] == 'E') {
    (*i)++;
    int digit = 0;
    int max = my_strlen(&str[(*i)]);
    if (max > 0 && !(str[(*i)] == '+' || str[(*i)] == '-')) {
      (*i)--;
      max++;
    }
    for (int j = 0; j < max - 1; j++) {
      digit = (digit * 10) + char_to_int(str[++(*i)]);
    }
    for (int j = 0; j < digit; j++) {
      *num = (str[*(i)-max + 1] == '-') ? *num / 10 : *num * 10;
    }
  }
}

void sscanf_handle_string(va_list* args, Spec* spec, const char* str) {
  if (spec->length_l) {
    wchar_t* wstr = va_arg(*args, wchar_t*);
    my_size_t s_len = my_strlen(str);
    for (my_size_t i = 0; i < s_len; i++) {
      wstr[i] = (wchar_t)str[i];
    }
    wstr[s_len] = L'\0';
  } else {
    char* strg = va_arg(*args, char*);
    my_strncpy(strg, str, my_strlen(str) + 1);
  }
  spec->return_value++;
}

void sscanf_handle_n(va_list* args, const Spec* spec) {
  if (spec->length_L || spec->length_l == 2) {
    long long int* result = va_arg(*args, long long int*);
    *result = spec->index_n;
  } else if (spec->length_l == 1) {
    long int* result = va_arg(*args, long int*);
    *result = spec->index_n;
  } else if (spec->length_h == 1) {
    short int* result = va_arg(*args, short int*);
    *result = spec->index_n;
  } else if (spec->length_h == 2) {
    signed char* result = va_arg(*args, signed char*);
    *result = spec->index_n;
  } else {
    int* result = va_arg(*args, int*);
    *result = spec->index_n;
  }
}

char* sscanf_strtok(char* str, Spec* spec) {
  char* token = MY_NULL;
  static char* nextToken = MY_NULL;
  static char last_symbol = '\0';
  int flag_next = 0;
  if (str != MY_NULL)
    nextToken = str;
  else if (nextToken == MY_NULL)
    flag_next = 1;
  else
    *nextToken = last_symbol;
  if (!flag_next) {
    if (!(spec->c && !spec->prev_ws) && (!spec->buffer || spec->prev_ws)) {
      spec->index_n += my_strspn(nextToken, "\v\t\r\n\f ", "1");
      nextToken += my_strspn(nextToken, "\v\t\r\n\f ", "1");
    }
    spec->pars_count++;
    if (*nextToken == '\0') {
      nextToken = MY_NULL;
      if (spec->pars_count == 1) spec->return_value = -1;
    } else {
      token = nextToken;
      my_size_t add = strtok_parser_string(nextToken, spec);
      spec->index_n += add;
      nextToken += add;
      if (*nextToken == '\0') {
        nextToken = MY_NULL;
      } else {
        last_symbol = *nextToken;
        *nextToken = '\0';
      }
    }
  }
  return token;
}

my_size_t strtok_parser_string(char* nextToken, Spec* spec) {
  int condition = 1;
  my_size_t width = (my_size_t)spec->width;
  my_size_t string = length_string(spec, nextToken);
  if (!(spec->c && spec->width > 1)) condition = (string > width && width);
  return condition ? width : string;
}

char* strtok_str(int* flag_parser_str, char* str) {
  return !((*flag_parser_str)++) ? str : MY_NULL;
}

my_size_t length_string(Spec* spec, char* nextToken) {
  my_size_t result = 0;
  if (spec->s) result = my_strcspn(nextToken, "\v\t\r\n\f ");
  if (spec->d) result = my_strspn(nextToken, "+-1234567890", "-+");
  if (spec->i)
    result = my_strspn(nextToken, "+-xX0123456789abcdefABCDEF", "+-xX");
  if (spec->f || spec->e || spec->E || spec->g || spec->G) {
    result = my_strspn(nextToken, "-+1234567890.eE", ".eE+");
    if (!result || (result == 1 && (*nextToken == '-' || *nextToken == '+'))) {
      result = find_inf(nextToken);
      if (result) {
        spec->my_infinity = 1;
        if (*nextToken == '-') spec->my_infinity = 2;
      }
    }
    if (!result || (result == 1 && (*nextToken == '-' || *nextToken == '+'))) {
      result = find_nan(nextToken);
      if (result) spec->my_nan = 1;
    }
  }
  if (spec->c) result++;
  if (spec->x || spec->X)
    result = my_strspn(nextToken, "+-xX1234567890abcdefABCDEF", "+-xX");
  if (spec->o) result = my_strspn(nextToken, "+-12345670", "+-");
  if (spec->u) result = my_strspn(nextToken, "+-1234567890", "+-");
  if (spec->p)
    result = my_strspn(nextToken, "+-xX0123456789abcdefABCDEF", "+-xX");
  if (spec->f_ws) {
    result = my_strspn(nextToken, "\v\t\r\n\f ", "1");
    spec->f_ws = 0;
  }
  if (spec->f_percent) {
    result = my_strspn(nextToken, "%", "%");
    spec->f_percent = 0;
  }
  if (spec->f_read_format) {
    const char* p = my_strstr(nextToken, spec->buffer);
    if (p == nextToken) {
      result = my_strlen(spec->buffer);
    }
  }
  return result;
}

my_size_t find_inf(char* str) {
  char* p = str;
  int n = 4;
  my_size_t flag_sign = 0;
  my_size_t flag_inf = 0;
  while (*p != '\0' && n != 0) {
    if ((*p == '+' || *p == '-') && n == 4) flag_sign++;
    if ((*p == 'I' || *p == 'i') && ((n == 3 && flag_sign) || n == 4))
      flag_inf++;
    if ((*p == 'N' || *p == 'n') && ((n == 2 && flag_sign) || n == 3))
      flag_inf++;
    if ((*p == 'F' || *p == 'f') && ((n == 1 && flag_sign) || n == 2))
      flag_inf++;
    n--;
    p++;
  }
  if (flag_inf != 3) {
    flag_inf = 0;
    flag_sign = 0;
  }
  return flag_inf + flag_sign;
}

my_size_t find_nan(char* str) {
  char* p = str;
  int n = 4;
  my_size_t flag_sign = 0;
  my_size_t flag_nan = 0;
  while (*p != '\0' && n != 0) {
    if ((*p == '+' || *p == '-') && n == 4) flag_sign++;
    if ((*p == 'N' || *p == 'n') && ((n == 3 && flag_sign) || n == 4))
      flag_nan++;
    if ((*p == 'A' || *p == 'a') && ((n == 2 && flag_sign) || n == 3))
      flag_nan++;
    if ((*p == 'N' || *p == 'n') && ((n == 1 && flag_sign) || n == 2))
      flag_nan++;
    n--;
    p++;
  }
  if (flag_nan != 3) {
    flag_nan = 0;
    flag_sign = 0;
  }
  return flag_nan + flag_sign;
}