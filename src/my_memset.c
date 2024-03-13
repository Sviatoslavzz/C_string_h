#include "my_string.h"
/*
Copies the character c (an unsigned char) to the first
n characters of the string pointed to, by the argument str
*/
void* my_memset(void* str, int c, my_size_t n) {
  for (my_size_t i = 0; i < n; i++) {
    *((char*)str + i) = c;
  }
  return str;
}
