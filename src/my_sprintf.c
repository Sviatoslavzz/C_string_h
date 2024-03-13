#include "my_sprintf.h"

int my_sprintf(char* str, const char* format, ...) {
  int index = 0;
  if (str && format) {
    va_list args;
    va_start(args, format);
    int prev_percent = 0;
    int mem_error = 0;
    while (*format && !mem_error) {
      if (*format == '%' && !prev_percent) {
        prev_percent = 1;
        Spec spec = {0};
        spec.found = 1;
        get_specifier(format, &args, &spec);
        if (spec.found) {
          handle_specifier(&args, &spec, str, &index);
          format += spec.count_move;
          prev_percent = 0;
          mem_error = spec.mem_error;
        }
      } else {
        prev_percent = 0;
        str[index] = *format;
        index++;
      }
      format++;
    }
    str[index] = '\0';
    va_end(args);
  } else {
    index--;
  }
  return index;
}

void get_specifier(const char* format, va_list* args, Spec* spec) {
  format++;
  spec->count_move = 1;
  format += search_for_flag(format, spec);
  format += search_for_width(format, args, spec);
  if (*format == '.') {
    spec->has_precision++;
    format++;
    spec->count_move++;
    format += precision_search(format, args, spec);
  }

  format += length_search(format, spec);

  search_for_spec(format, spec);
}

int search_for_flag(const char* format, Spec* spec) {
  const char* p = format;
  while (1) {
    if (*p == '-') {
      spec->flag_minus = 1;
    } else if (*p == '+') {
      spec->flag_plus = 1;
    } else if (*p == ' ') {
      spec->flag_ws = 1;
    } else if (*p == '#') {
      spec->flag_sharp = 1;
    } else if (*p == '0') {
      spec->flag_zero = 1;
    } else {
      break;
    }
    p++;
    spec->count_move++;
  }
  return p - format;
}

int search_for_width(const char* format, va_list* args, Spec* spec) {
  const char* p = format;
  while (1) {
    if (*p == '0') {
      spec->width_direct = spec->width_direct * 10;
    } else if (*p >= 49 && *p <= 57) {
      if (spec->width_direct) {
        spec->width_direct = spec->width_direct * 10 + (*p - '0');
      } else {
        spec->width_direct = *p - '0';
      }
    } else if (*p == '*' && !spec->width_direct) {
      spec->width_arg = va_arg(*args, int);
      spec->width_direct = spec->width_arg;
    } else {
      break;
    }
    p++;
    spec->count_move++;
  }

  return p - format;
}

int precision_search(const char* format, va_list* args, Spec* spec) {
  const char* p = format;
  while (1) {
    if (*p == '0') {
      if (spec->precision_direct) {
        spec->precision_direct = spec->precision_direct * 10;
      }
    } else if (*p >= 49 && *p <= 57) {
      if (spec->precision_direct) {
        spec->precision_direct = spec->precision_direct * 10 + (*p - '0');
      } else {
        spec->precision_direct = *p - '0';
      }
    } else if (*p == '*' && !spec->precision_direct) {
      spec->precision_arg = va_arg(*args, int);
      spec->precision_direct = spec->precision_arg;
    } else {
      break;
    }
    p++;
    spec->count_move++;
  }
  return p - format;
}

int length_search(const char* format, Spec* spec) {
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

void search_for_spec(const char* format, Spec* spec) {
  if (*format == 'c')
    spec->c++;
  else if (*format == 'd')
    spec->d++;
  else if (*format == 'i')
    spec->i++;
  else if (*format == 'e') {
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

  if (spec->e || spec->E || spec->f || spec->g || spec->G) {
    if (!spec->has_precision) spec->precision_direct = 6;
  }
}

void handle_specifier(va_list* args, Spec* spec, char* str, int* index) {
  if (spec->d) handle_int(args, spec, str, index);
  if (spec->i) handle_int(args, spec, str, index);
  if (spec->o || spec->u || spec->x || spec->X)
    handle_uns_int(args, spec, str, index);
  if (spec->c) handle_char(args, spec, str, index);
  if (spec->s) handle_string(args, spec, str, index);
  if (spec->p) handle_ptr(args, spec, str, index);
  if (spec->n) handle_n(spec, args, index);
  if (spec->e || spec->E || spec->g || spec->G || spec->f)
    handle_floating_point(args, spec, str, index);
}

void handle_n(const Spec* spec, va_list* args, const int* index) {
  if (spec->length_l == 2 || spec->length_L) {
    long long int* result = va_arg(*args, long long int*);
    *result = *index;
  } else if (spec->length_l == 1) {
    long int* result = va_arg(*args, long int*);
    *result = *index;
  } else if (spec->length_h == 1) {
    short int* result = va_arg(*args, short int*);
    *result = *index;
  } else if (spec->length_h == 2) {
    signed char* result = va_arg(*args, signed char*);
    *result = *index;
  } else {
    int* result = va_arg(*args, int*);
    *result = *index;
  }
}

void handle_int(va_list* args, const Spec* spec, char* str, int* index) {
  char buff[50] = {"\0"};
  char* p_buff = buff;
  long long int i = 0;
  if (spec->length_l == 2) {
    i = va_arg(*args, long long int);
  } else if (spec->length_l == 1) {
    i = va_arg(*args, long int);
  } else if (spec->length_h == 1) {
    short int a = va_arg(*args, int);
    i = a;
  } else if (spec->length_h == 2) {
    signed char a = va_arg(*args, int);
    i = a;
  } else {
    i = va_arg(*args, int);
  }
  int_to_str(&i, p_buff);
  int has_sign = 1;
  if (!spec->flag_plus && spec->flag_ws && *p_buff == '+') {
    *p_buff = ' ';
    if (spec->has_precision && !spec->precision_direct &&
        *(p_buff + 1) == '0') {
      str[*index] = *p_buff++;
      *index += 1;
    }
  }
  if (!spec->flag_plus && !spec->flag_ws && *p_buff == '+') {
    p_buff++;
    has_sign = 0;
  }
  int_conditions(spec, &has_sign, str, index, p_buff);
}

void int_conditions(const Spec* spec, int* has_sign, char* str, int* index,
                    char* p_buff) {
  int size = (int)my_strlen(p_buff);
  if (spec->flag_zero && (spec->flag_plus || spec->flag_ws || *p_buff == '-') &&
      !spec->has_precision) {
    str[*index] = *p_buff++;
    *index += 1;
    *has_sign = 0;
  }
  if (spec->precision_direct > size - *has_sign) {
    size = spec->precision_direct + *has_sign;
    handle_width_before(spec, str, index, size);
    if (((spec->flag_plus || *p_buff == '-' || spec->flag_ws) && *has_sign)) {
      str[*index] = *p_buff++;
      *index += 1;
      *has_sign = 0;
    }
    int n = spec->precision_direct - (int)my_strlen(p_buff) - *has_sign;
    while (n) {
      str[*index] = '0';
      *index += 1;
      n--;
    }
  } else {
    if ((int)my_strlen(p_buff) == 1 && *p_buff == '0' && spec->has_precision &&
        !spec->precision_direct)
      size--;
    handle_width_before(spec, str, index, size);
  }
  if (!((int)my_strlen(p_buff) == 1 && *p_buff == '0' && spec->has_precision &&
        !spec->precision_direct))
    write_value(str, p_buff, index);

  handle_width_after(spec, str, index, size);
}

void handle_uns_int(va_list* args, const Spec* spec, char* str, int* index) {
  char buff[50];
  char* p_buff = buff;
  int div = 10;
  int x = 'x';
  if (spec->o) div = 8;
  if (spec->x || spec->X) div = 16;
  if (spec->X) x = 'X';
  unsigned long long int i = 0;
  if (spec->length_l == 2) {
    i = va_arg(*args, unsigned long long int);
  } else if (spec->length_l == 1) {
    i = va_arg(*args, unsigned long int);
  } else if (spec->length_h == 1) {
    unsigned short int a = va_arg(*args, unsigned int);
    i = a;
  } else if (spec->length_h == 2) {
    unsigned char a = va_arg(*args, unsigned int);
    i = a;
  } else {
    i = va_arg(*args, unsigned int);
  }
  unsigned_int_to_str(&i, p_buff, div, x);
  uns_int_conditions(p_buff, spec, str, index, x);
}

void uns_int_conditions(char* p_buff, const Spec* spec, char* str, int* index,
                        int x) {
  int size = my_strlen(p_buff);
  if (spec->precision_direct > size) size = spec->precision_direct;
  if (spec->flag_sharp && size > 0 && (spec->o || spec->x || spec->X) &&
      *p_buff != '0')
    size++;
  if (spec->flag_sharp && size > 0 && (spec->x || spec->X) && *p_buff != '0')
    size++;
  int has_sign = 1;
  if (spec->width_direct > size + 2 && spec->flag_sharp && spec->flag_zero &&
      *p_buff != '0') {
    has_sign = 0;
    fill_0x(spec, p_buff, str, index, x);
  }
  if ((int)my_strlen(p_buff) == 1 && *p_buff == '0' && spec->has_precision &&
      !spec->precision_direct && !(spec->o && spec->flag_sharp))
    size--;
  handle_width_before(spec, str, index, size);

  if (!(spec->precision_direct > (int)my_strlen(p_buff) && spec->o) && has_sign)
    fill_0x(spec, p_buff, str, index, x);

  if (spec->precision_direct > (int)my_strlen(p_buff)) {
    int n = spec->precision_direct - (int)my_strlen(p_buff);
    while (n) {
      str[*index] = '0';
      *index += 1;
      n--;
    }
  }
  if ((int)my_strlen(p_buff) == 1 && *p_buff == '0' && spec->has_precision &&
      !spec->precision_direct && !(spec->o && spec->flag_sharp)) {
    ;
  } else {
    write_value(str, p_buff, index);
  }

  handle_width_after(spec, str, index, size);
}

void handle_char(va_list* args, const Spec* spec, char* str, int* index) {
  if (spec->length_l) {
    const wchar_t c = va_arg(*args, wchar_t);
    char buffer[4];
    int len = wctomb(buffer, c);
    if (len == 1) {
      char result = buffer[0];
      handle_width_before(spec, str, index, 1);
      str[*index] = result;
      *index += 1;
      handle_width_after(spec, str, index, 1);
    } else {
      *index = -1;
    }
  } else {
    const char c = va_arg(*args, int);
    handle_width_before(spec, str, index, 1);
    str[*index] = c;
    *index += 1;
    handle_width_after(spec, str, index, 1);
  }
}

void handle_string(va_list* args, Spec* spec, char* str, int* index) {
  spec->flag_zero = 0;
  const char* buffer = MY_NULL;
  if (spec->length_l) {
    const wchar_t* wstr = va_arg(*args, wchar_t*);
    if (wstr) {
      write_wchar_string(spec, str, index, wstr);
    } else {
      buffer = str_null_fill();
      write_str(spec, str, buffer, index);
    }
  } else {
    char* s = va_arg(*args, char*);
    if (s) buffer = s;
    if (!buffer) {
      if (!(spec->precision_direct < 6 && spec->has_precision))
        buffer = str_null_fill();
    }
    write_str(spec, str, buffer, index);
  }
}

void write_wchar_string(Spec* spec, char* str, int* index,
                        const wchar_t* wstr) {
  my_size_t wlen = wcslen(wstr);
  char* p_buff = MY_NULL;
  if (wlen) {
    p_buff = malloc((wlen + 1) * sizeof(char));
    if (!p_buff) {
      printf("Memory allocation error: function <handle_string>\n");
      spec->mem_error = 1;
    } else {
      my_size_t i = 0;
      while (i < wlen) {
        wchar_t wc = wstr[i];
        char c[4];
        int result = wctomb(c, wc);
        if (result == 1) {
          p_buff[i] = c[0];
        } else {
          *index = -1;
          p_buff[0] = '\0';
        }
        i++;
      }
      p_buff[i] = '\0';
      write_str(spec, str, p_buff, index);
      free(p_buff);
    }
  }
}

void write_str(const Spec* spec, char* str, const char* buffer, int* index) {
  int s_size = (int)my_strlen(buffer);
  check_str_precision(spec, &s_size);
  handle_width_before(spec, str, index, s_size);
  int tmp_size = s_size;
  while (tmp_size--) {
    str[*index] = *buffer++;
    *index += 1;
  }
  handle_width_after(spec, str, index, s_size);
}

char* str_null_fill() { return "(null)"; }

void check_str_precision(const Spec* spec, int* s_size) {
  if (spec->has_precision && spec->precision_direct < *s_size)
    *s_size = spec->precision_direct;
}

void handle_ptr(va_list* args, Spec* spec, char* str, int* index) {
  char buff[50] = "";
  char* p_buff = buff;
  int nil_flag = 0;
  void* i = va_arg(*args, void*);
  if (i == MY_NULL) {
    my_strncat(p_buff, "(nil)", 5);
    nil_flag = 1;
  } else
    unsigned_int_to_str((unsigned long long int*)&i, p_buff, 16, 'x');
  int size = (int)my_strlen(p_buff) + 2;
  if (!nil_flag) {
    if (spec->flag_zero && !spec->precision_direct) {
      str[*index] = '0';
      *index += 1;
      str[*index] = 'x';
      *index += 1;
    } else
      spec->flag_zero = 0;
    if (spec->precision_direct > size - 2) size = spec->precision_direct + 2;
    handle_width_before(spec, str, index, size);
    if (!spec->flag_zero) {
      str[*index] = '0';
      *index += 1;
      str[*index] = 'x';
      *index += 1;
    }
    if (size > (int)my_strlen(p_buff)) {
      int n = size - 2 - (int)my_strlen(p_buff);
      while (n) {
        str[*index] = '0';
        *index += 1;
        n--;
      }
    }
  }
  write_value(str, p_buff, index);
  handle_width_after(spec, str, index, size);
}

void handle_floating_point(va_list* args, Spec* spec, char* str, int* index) {
  char* buff = malloc((spec->length_L ? 5000 : 500) * sizeof(char));
  if (buff != NULL) {
    char* p_buff = buff;
    long double i =
        spec->length_L ? va_arg(*args, long double) : va_arg(*args, double);
    if (isnan(i)) {
      spec->flag_zero = 0;
      handle_width_before(spec, str, index, 3);
      char* nan_str = "nan";
      char* p_ns = nan_str;
      write_value(str, p_ns, index);
      handle_width_after(spec, str, index, 3);
    } else if (isinf(i)) {
      spec->flag_zero = 0;
      char inf_str[5];
      char* p_inf_str = inf_str;
      int size = 0;
      if (i < 0) {
        my_strncpy(p_inf_str, "-inf", 4);
        size = 4;
      } else {
        my_strncpy(p_inf_str, "inf", 3);
        size = 3;
      }
      handle_width_before(spec, str, index, size);
      write_value(str, p_inf_str, index);
      handle_width_after(spec, str, index, size);
    } else {
      handle_floating_point_E(spec, p_buff, &i, str, index);
    }

    free(buff);
  } else {
    printf("Memory allocation error: function <handle_floating_point>\n");
    spec->mem_error = 1;
  }
}

void handle_floating_point_E(Spec* spec, char* p_buff, long double* i,
                             char* str, int* index) {
  if (spec->e || spec->E) {
    exponent_to_string(spec, i, p_buff);
  } else if (spec->f) {
    double_to_str(spec, i, p_buff);
  } else {
    short_decimal_to_string(spec, i, p_buff);
  }
  if (!spec->flag_plus && spec->flag_ws && *p_buff == '+') *p_buff = ' ';
  if (!spec->flag_plus && !spec->flag_ws && *p_buff == '+') p_buff++;
  int size = (int)my_strlen(p_buff);
  if (spec->flag_zero && (spec->flag_plus || spec->flag_ws || *p_buff == '-') &&
      !isnan(*i)) {
    str[*index] = *p_buff;
    *index += 1;
    p_buff++;
  }
  handle_width_before(spec, str, index, size);
  write_value(str, p_buff, index);
  handle_width_after(spec, str, index, size);
}

void write_value(char* str, char* buf, int* index) {
  while (*buf != '\0') {
    str[*index] = *buf;
    *index += 1;
    buf++;
  }
}

void int_to_str(long long int* number, char* buf) {
  char const digit[] = "0123456789";
  char* ptr_str = buf;
  if (*number < 0) {
    *ptr_str = '-';
    *number *= -1;
  } else {
    *ptr_str = '+';
  }
  ptr_str++;
  long long int shifter = *number;

  while (shifter) {
    shifter /= 10;
    ptr_str++;
  }
  if (*number == 0) *ptr_str++ = '0';
  *ptr_str = '\0';
  while (*number) {
    ptr_str--;
    *ptr_str = digit[*number % 10];
    *number /= 10;
  }
}

void unsigned_int_to_str(unsigned long long const int* number, char* buf,
                         int div, int x) {
  char digit[] = "0123456789abcdef";
  if (x == 'X') {
    for (int i = 10; i < 16; i++) {
      digit[i] -= 32;
    }
  }
  char* ptr_str = buf;
  unsigned long long int shifter = *number;
  while (shifter > 0 && div > 0) {
    shifter /= div;
    ptr_str++;
  }
  if (ptr_str - buf == 0) {
    *ptr_str++ = '0';
  }
  *ptr_str = '\0';
  shifter = *number;
  while (shifter > 0 && div > 0) {
    ptr_str--;
    *ptr_str = digit[shifter % div];
    shifter /= div;
  }
}

void fill_0x(const Spec* spec, const char* p_buff, char* str, int* index,
             const int x) {
  if (spec->flag_sharp && *p_buff != '0') {
    if (spec->o || spec->x || spec->X) {
      str[*index] = '0';
      *index += 1;
    }
    if (spec->x || spec->X) {
      str[*index] = x;
      *index += 1;
    }
  }
}

void double_to_str(const Spec* spec, long double* number, char* buf) {
  char* str = buf;
  check_sign(number, &str);
  *number = *number + 0.5 * pow(10, -spec->precision_direct);
  long long int degree = (int)floorl(log10l(fabsl(*number)));
  if (degree >= 0) degree++;
  long double left = 0;
  long double right = modfl(*number, &left);
  if (degree >= 0) {
    int int_array[degree + 1];
    int tmp_degree = degree;
    int count = 0;
    while (tmp_degree) {
      int_array[count] = floor(fmodl(left, 10.0));
      left /= 10.0;
      count++;
      tmp_degree--;
    }
    while (count) {
      count--;
      *str++ = int_array[count] + '0';
    }
  } else {
    *str++ = '0';
  }
  if (spec->precision_direct || (spec->flag_sharp && !spec->precision_direct))
    *str++ = '.';
  for (int i = 0; i < spec->precision_direct; i++) {
    write_mantissa(&right, str);
    str++;
  }
  *str = '\0';
}

void check_sign(long double* number, char** ptr_str) {
  if (*number < 0) {
    **ptr_str = '-';
    *number *= -1;
  } else {
    **ptr_str = '+';
  }
  (*ptr_str)++;
}

void handle_width_before(const Spec* spec, char* str, int* index, int size) {
  if (spec->width_direct && !spec->flag_minus) {
    for (int i = 0; i < spec->width_direct - size; i++) {
      if (spec->flag_zero && !spec->i && !spec->d && !spec->u && !spec->o &&
          !spec->x && !spec->X) {
        str[*index] = '0';
      } else if ((spec->i || spec->d || spec->u || spec->o || spec->x ||
                  spec->X) &&
                 spec->flag_zero && !spec->has_precision) {
        str[*index] = '0';
      } else {
        str[*index] = ' ';
      }
      *index = *index + 1;
    }
  }
}

void handle_width_after(const Spec* spec, char* str, int* index, int size) {
  if (spec->width_direct && spec->flag_minus) {
    for (int i = 0; i < spec->width_direct - size; i++) {
      str[*index] = ' ';
      *index = *index + 1;
    }
  }
}

void exponent_to_string(const Spec* spec, long double* number, char* p_buff) {
  char* str = p_buff;
  check_sign(number, &str);
  long long int degree = (int)floorl(log10l(fabsl(*number)));
  if (*number == 0) degree = 0;
  *number = *number * pow(10, -degree);
  *number = *number + 0.5 * pow(10, -spec->precision_direct);
  if (*number > 10) {
    degree++;
    *number = *number / 10;
  }
  *str++ = (int)*number + '0';
  *number = *number - (int)*number;
  if (spec->precision_direct || (spec->flag_sharp && !spec->precision_direct))
    *str++ = '.';
  for (int i = 0; i < spec->precision_direct; i++) {
    write_mantissa(number, str);
    str++;
  }
  *str++ = spec->e ? 'e' : 'E';
  *str++ = (degree >= 0) ? '+' : '-';
  if (llabs(degree) < 10) *str++ = '0';
  char degree_str[20];
  char* p = degree_str;
  int_to_str(&degree, p);
  p++;
  while (*p) {
    *str++ = *p++;
  }
  *str = '\0';
}

void write_mantissa(long double* number, char* str) {
  *number = *number * 10;
  int n = (int)(*number);
  *str = n + '0';
  *number = *number - n;
}

void short_decimal_to_string(Spec* spec, long double* number, char* p_buff) {
  char* str = p_buff;
  long double tmp = *number;
  long long int degree = (int)floorl(log10l(fabsl(*number)));
  if (*number == 0) degree = 0;
  if ((degree < spec->precision_direct && degree >= 0 &&
       spec->precision_direct) ||
      (degree > -5 && degree < 0) ||
      (degree <= spec->precision_direct && degree >= 0 &&
       !spec->precision_direct)) {
    if (degree >= 0 && spec->precision_direct) {
      spec->precision_direct -= (degree + 1);
    } else if (degree < 0 && spec->precision_direct <= llabs(degree) &&
               spec->precision_direct) {
      spec->precision_direct += llabs(degree) - 1;
    } else if (degree < 0 && !spec->precision_direct) {
      spec->precision_direct = llabs(degree);
    }
    double_to_str(spec, number, str);
    int count_zeros = find_zeros(str);
    if (count_zeros && !spec->flag_sharp) {
      spec->precision_direct -= count_zeros;
      double_to_str(spec, &tmp, str);
    }
  } else {
    if (spec->precision_direct) spec->precision_direct--;
    if (spec->G) spec->E++;
    if (spec->g) spec->e++;
    exponent_to_string(spec, number, str);
    int count_zeros = find_zeros(str);
    if (count_zeros && !spec->flag_sharp) {
      spec->precision_direct -= count_zeros;
      exponent_to_string(spec, &tmp, str);
    }
  }
}

int find_zeros(char* str) {
  char* p_str = str;
  int count_zeros = 0;
  while (*p_str != '.' && *p_str != '\0') {
    p_str++;
  }
  if (*p_str == '.') {
    p_str++;
    while (*p_str != 'e' && *p_str != 'E' && *p_str != '\0') {
      if (*p_str == '0') {
        count_zeros++;
      } else {
        count_zeros = 0;
      }
      p_str++;
    }
  }
  return count_zeros;
}
