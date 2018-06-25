all: example tests


tests: surlparser_tests.o surlparser.h
	g++ -std=c++11 -Os surlparser_tests.o test.cpp -o test

example: surlparser.o surlparser.h
	g++ -std=c++11 -Os surlparser.o example.cpp -o example

surlparser.o: surlparser.h surlparser.cpp
	g++ -std=c++11 -Os -c surlparser.cpp -o $@

surlparser_tests.o: surlparser.h surlparser.cpp
	g++ -std=c++11 -Os -c surlparser.cpp -o $@ -DTESTS

clean:
	rm -f test example surlparser.o

