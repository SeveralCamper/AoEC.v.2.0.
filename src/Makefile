CC = gcc -std=c11
CFLAGS = -Wall -Werror -Wextra
LIBS = -lcheck -lsubunit -lrt -lpthread -lm
OS := $(shell uname -s)

ifeq ($(OS), Linux)
	OPEN = xdg-open
	ADD_LIB = -lm -lrt -lpthread -D_GNU_SOURCE
	BREW = .
endif
ifeq ($(OS), Darwin)
	OPEN = open
	ADD_LIB = 
	BREW = {$HOME}/homebrew
endif

PATH := $(PATH):$(BREW)/bin
GCOV = --coverage

all: clean CP_evaluation.a run

$(TARGET): obj/CP_evaluation.o CP_evaluation.a
	$(CC) obj/CP_evaluation.o $(CFLAGS) $(LIBS) $(GCOV) -L. CP_evaluation.a -o $@

obj/CP_evaluation.o: 1/CP_evaluation.c
	$(CC) -c 1/CP_evaluation.c $(CFLAGS) $(LIBS) -o $@

CP_evaluation.a: obj/CP_evaluation.o
	ar rcs $@ $^
	ranlib $@
	cp $@ lib$@

run: clean start

start:
	gcc 1/CP_evaluation.c $(CFLAGS) -lm
	./a.out

clean:	
		rm -rf CP_evaluation.a
		rm -rf CP_evaluation
		rm -rf CP_evaluationTest
		rm -rf *.o *.so *.a fizz *.gc* *.info report *.out *.gcda *.so *.gcno *.info
		rm -rf test/*.o test/*.so test/*.a  test/*.gcda  test/*.so  test/*.gcno  test/*.info

rebuild: clean all

.PHONY: all clean test rebild CP_evaluation.a
