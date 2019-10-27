all:
	g++ -o main main.cpp -O3 -s -DNDEBUG -std=c++11 -pthread
clean:
	rm main
