#include "my_string.h"

#define CHAR_REGISTER 32

void* my_to_upper(const char* str) {
  char* str_result = MY_NULL;
  if (str != MY_NULL) {
    my_size_t len_result = my_strlen(str);
    str_result = malloc((len_result + 1) * sizeof(char));
    if (str_result != MY_NULL) {
      for (register my_size_t i = 0; i < len_result; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
          str_result[i] = str[i] - CHAR_REGISTER;
        } else {
          str_result[i] = str[i];
        }
      }
      str_result[len_result] = '\0';
    }
  }
  return str_result;
}

void* my_to_lower(const char* str) {
  char* str_result = MY_NULL;
  if (str != MY_NULL) {
    my_size_t len_result = my_strlen(str);
    str_result = malloc((len_result + 1) * sizeof(char));
    if (str_result) {
      for (register my_size_t i = 0; i < len_result; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          str_result[i] = str[i] + CHAR_REGISTER;
        } else {
          str_result[i] = str[i];
        }
      }
      str_result[len_result] = '\0';
    }
  }
  return str_result;
}

void* my_insert(const char* src, const char* str, my_size_t start_index) {
  char* str_result = MY_NULL;
  if (src != MY_NULL && str != MY_NULL) {
    my_size_t len_src = my_strlen(src);
    my_size_t len_str = my_strlen(str);
    str_result = (char*)malloc((len_src + len_str + 1) * sizeof(char));
    if (str_result) {
      if (start_index > len_src) {
        start_index = len_src;
      }
      for (register my_size_t i = 0; i < start_index; i++) {
        str_result[i] = src[i];
      }
      for (register my_size_t i = 0; i < len_str; i++) {
        str_result[start_index + i] = str[i];
      }
      for (register my_size_t i = start_index; i < len_src; i++) {
        str_result[start_index + len_str + (i - start_index)] = src[i];
      }
      str_result[len_src + len_str] = '\0';
    }
  } else if (str == MY_NULL && src != MY_NULL) {
    str_result = (char*)malloc((my_strlen(src) + 1) * sizeof(char));
    if (str_result) my_strncpy(str_result, src, my_strlen(src) + 1);
  }
  return str_result;
}

void* my_trim(const char* src, const char* trim_chars) {
  char* str_result = MY_NULL;
  const char* trim_my = (char*)trim_chars;
  if (src != MY_NULL) {
    if (trim_chars == MY_NULL || trim_chars[0] == '\0') {
      trim_my = " ";
    }
    my_size_t str_start = 0;
    my_size_t str_end = my_strlen(src);
    while (str_start < str_end &&
           (my_strchr(trim_my, src[str_start]) != MY_NULL)) {
      str_start++;
    }
    while (str_end > str_start &&
           (my_strchr(trim_my, src[str_end]) != MY_NULL)) {
      str_end--;
    }
    my_size_t len_str_result = str_end - str_start + 1;
    str_result = (char*)malloc(len_str_result + 1);
    if (str_result) {
      my_memcpy(str_result, src + str_start, len_str_result);
      str_result[len_str_result] = '\0';
    }
  }
  return str_result;
}