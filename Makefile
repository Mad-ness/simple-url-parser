all: example test

surlparser.o: surlparser.h surlparser.cpp
	g++ -std=c++11 -Os -c surlparser.cpp -o $@

test: surlparser.o surlparser.h
	g++ -std=c++11 -Os surlparser.o test.cpp -o test

example: surlparser.o surlparser.h
	g++ -std=c++11 -Os surlparser.o example.cpp -o example

clean:
	rm -f test example surlparser.o




