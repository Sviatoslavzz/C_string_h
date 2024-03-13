#include "my_test.h"

int main() {
  Suite* cases[] = {suite_memcpy(),   suite_strlen(),   suite_memset(),
                    suite_memchr(),   suite_strncpy(),  suite_memcmp(),
                    suite_strncat(),  suite_strchr(),   suite_strcspn(),
                    suite_strrchr(),  suite_strstr(),   suite_strpbrk(),
                    suite_strncmp(),  suite_strtok(),   suite_strerror(),
                    suite_to_upper(), suite_to_lower(), suite_insert(),
                    suite_trim(),     suite_sprintf(),  suite_sscanf()};
  for (int i = 0; i < 21; i++) {
    printf("\n");
    SRunner* sr = srunner_create(cases[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);
  }
  return 0;
}
