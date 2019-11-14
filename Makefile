CC = g++
CFLAGS_COMMON = -O3 -std=c++11 -Wall -g -Iinclude
CFLAGS_TEST = -lgtest -lpthread
SRC = src/*.cpp

run: main.cpp
	$(CC) -o main main.cpp $(SRC) $(CFLAGS_COMMON)
test:
	$(CC) -o test tests/*.cpp $(SRC) $(CFLAGS_TEST) $(CFLAGS_COMMON)
clean_main:
	rm main
clean_test:
	rm test
