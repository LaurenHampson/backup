# Let's declare some variables

CC       = g++

CPPFLAGS = -Wall -g

BIN_DIR  = bin

GTEST_LL = -I /usr/local/opt/gtest/include/ -l gtest -l gtest_main -pthread


search: search.cpp querysearch.cpp lowercase.cpp webpage.cpp parser.cpp 

	$(CC) $(CPPFLAGS)  -std=c++11 $^ -o $@

clear:
	
	rm search