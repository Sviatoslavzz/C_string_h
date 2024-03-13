CC = gcc
CFLAGS = -Wall -Wextra -Werror -g --std=c11
OBJ_DIR = objects/
SOURCE = $(wildcard *.c) # get list all *.c
TESTS = $(wildcard tests/*.c)
OBJECT = $(patsubst %.c, %.o, $(SOURCE))  # replace .c -> .o (making object files)
OBJECT_LIBRARY = $(patsubst %.c, %.o, $(SOURCE))
EXECUTABLE = my_test
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	CFLAGS += -DLinux
	GFLAGS = -lcheck_pic -lm -lsubunit
	RM_COMMAND = rm -rf test*.gcda test*.gcno
endif

ifeq ($(UNAME), Darwin)
	CFLAGS += -DDarwin
	GFLAGS = -I/opt/homebrew/include -L/opt/homebrew/lib -lcheck -lm
	RM_COMMAND = rm test*.gcda test*.gcno
endif

.PHONY: all my_string.a test gcov_report style clang clean rebuild valgrind_test cppcheck_test

all: clean my_string.a test gcov_report

my_string.a: clean $(OBJECT_LIBRARY)
	@ar rc my_string.a $(OBJECT_LIBRARY)
	@ranlib my_string.a
	@rm -rf *.o

test: rebuild
	@$(CC) $(CFLAGS) $(TESTS) my_string.a -o $(EXECUTABLE) $(GFLAGS)
	@./$(EXECUTABLE)

gcov_report: clean
	@$(CC) $(CFLAGS) $(SOURCE) $(TESTS) -o $(EXECUTABLE) $(GFLAGS) --coverage 
	@./$(EXECUTABLE)
	@lcov -t "my_tests" -o my_tests.info -c -d . -rc lcov_branch_coverage=1 --exclude "$(PWD)/tests/*"
	@genhtml -o report my_tests.info -rc lcov_branch_coverage=1
	@rm -rf *.gcno *.gcda *.gcov

style: clean
	@cp ../materials/linters/.clang-format ./
	@clang-format -n *.c
	@clang-format -n *.h
	@rm -rf .clang-format

clang: clean
	@cp ../materials/linters/.clang-format ./
	@clang-format -i *.c
	@clang-format -i *.h
	@rm -rf .clang-format

clean:
	@rm -f *.o *.a *.gcno *.gcda *.info $(EXECUTABLE) valgrind_out.txt
	@rm -rf report $(OBJ_DIR)

rebuild: clean my_string.a

valgrind_test: test
	valgrind -s -q --tool=memcheck --leak-check=yes --track-origins=yes --show-leak-kinds=all --verbose --log-file=valgrind_out.txt ./$(EXECUTABLE)

cppcheck_test:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h tests/*.c tests/*.h
 