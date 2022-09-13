CC = gcc -std=c11
CFLAGS = -Wall -Werror -Wextra
LIBS = -lcheck -lsubunit -lrt -lpthread -lm
TARGET = ../bin/CP_evaluation

all: clean add_report CP_evaluation.a run

$(TARGET): ../obj/CP_evaluation.o ../obj/report.o ../obj/s21_matrix.o CP_evaluation.a
	$(CC) ../obj/CP_evaluation.o ../obj/report.o ../obj/s21_matrix.o $(CFLAGS) $(LIBS) -L. CP_evaluation.a -o $@

../obj/CP_evaluation.o: CP_evaluation.c
	$(CC) -c CP_evaluation.c $(CFLAGS) $(LIBS) -o $@

../obj/s21_matrix.o: my_matrix/s21_matrix.c
	$(CC) -c my_matrix/s21_matrix.c $(CFLAGS) $(LIBS) -o $@

../obj/report.o: create_report/report.c
	$(CC) -c create_report/report.c $(CFLAGS) $(LIBS) -o $@

CP_evaluation.a: ../obj/CP_evaluation.o ../obj/s21_matrix.o ../obj/report.o
	ar rcs $@ $^
	ranlib $@
	cp $@ lib$@

add_report:
	touch report.csv

run: clean start

start: $(TARGET)
	./../bin/CP_evaluation
clean:	
		rm -rf CP_evaluation CP_evaluation.a ../bin/CP_evaluation report.csv
		rm -rf *.o *.so *.a fizz *.gc* *.info report *.out *.gcda *.so *.gcno *.info
		rm -rf test/*.o test/*.so test/*.a  test/*.gcda  test/*.so  test/*.gcno  test/*.info

rebuild: clean all

.PHONY: all clean test rebild CP_evaluation.a
