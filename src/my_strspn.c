#include "my_string.h"

my_size_t my_strspn(const char *str1, const char *str2, const char *ch_repeat) {
  int len_ch_repeat[15] = {0};

  my_size_t len = 0;
  int count_ch = 0;

  while (len < my_strlen(str1) && my_strchr(str2, str1[len]) && count_ch < 2) {
    for (my_size_t i = 0; i < my_strlen(ch_repeat) && *ch_repeat != '1'; i++) {
      char ch = ch_repeat[i];
      if (!!my_strchr(&ch, str1[len])) {
        if (str1[(len > 0 ? len - 1 : len)] != 'e') {
          len_ch_repeat[i] += 1;
          if (len > 0 && (str1[len] == '-' || str1[len] == '+')) {
            count_ch = 2;
          }
        }
        if (len_ch_repeat[i] >= 2) count_ch = 2;
      }
    }
    len++;
  }
  if (count_ch >= 2) len--;

  return len;
}