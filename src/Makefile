CC = gcc -std=c11
CFLAGS = -Wall -Werror -Wextra
LIBS = -lcheck -lsubunit -lrt -lpthread -lm

all: clean

clean:	
	rm -rf CP_evaluation.a bin/CP_evaluation
	rm -rf *.o *.so *.a fizz *.gc* *.info report *.out *.gcda *.so *.gcno *.info
	rm -rf test/*.o test/*.so test/*.a  test/*.gcda  test/*.so  test/*.gcno  test/*.info

rebuild: clean all

.PHONY: all clean test rebild CP_evaluation.a
