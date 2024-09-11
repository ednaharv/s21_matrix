
SOURCES = $(wildcard *.c)
TEST_SRCS = $(wildcard tests/*.c)
OBJECTS = $(SOURCES:.c=.o) 
TEST_OBJS = $(TEST_SRCS:.c=.o)
TEST_DIR = tests
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -g -O0 
GCOVFLAGS = -fprofile-arcs -ftest-coverage
LDFLAGS = -lgcov

OS = $(shell uname)

ifeq ($(OS), Linux)
	CHECKFLAGS = -lcheck -lm -lsubunit 
else
	CHECKFLAGS = -lcheck 
endif


all: s21_matrix.a test gcov_report

s21_matrix.a: $(OBJECTS) 
	@ar rcs $@ $^


test :  $(OBJECTS) $(TEST_OBJS)
	$(CC) $^ $(CHECKFLAGS) $(CFLAGS) -o $@

gcov_report:
	$(CC) $(SOURCES) $(TEST_SRCS) $(CHECKFLAGS) $(CFLAGS) $(GCOVFLAGS) $(LDFLAGS) -o report.out
	./report.out
	find ./ -type f -iname '*.gcda'
	lcov -o report.info -c -d .
	rm -rf ./cov-report
	mkdir ./cov-report
	genhtml -o ./cov-report/ report.info
	rm *.gcno *.gcda report.out report.info

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TEST_OBJS) test  s21_matrix.a