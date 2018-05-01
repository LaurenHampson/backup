CPPFLAGS = -g -Wall -std=c++11 
SUBFLAGS = -Wvla -Wshadow -Wunreachable-code -Wconversion
GTEST_LL = -I /usr/include/gtest/ -l gtest -l gtest_main -pthread

all: compile_check

.PHONY: compile_check

compile_check:
	python3 checker.py

splay_test: splay_tree_test.cpp ../splayTree.h
	g++ $(CPPFLAGS) $< $(GTEST_LL) -o $@

test: splay_test
	-valgrind --tool=memcheck --leak-check=yes ./splay_test

piazza: piazza_test piazza_run	

piazza_test: splay_piazza.cpp ../splayTree.h
	g++ $(CPPFLAGS) $< $(GTEST_LL) -o $@

piazza_run:
	valgrind --tool=memcheck --leak-check=yes ./piazza_test 