all: example tests test_ll


test_ll: linkedlist.h linkedlist.o
	g++ -std=c++11 -Os linkedlist.o test_ll.cpp -o test_ll

tests: surlparser_tests.o surlparser.h
	g++ -std=c++11 -Os surlparser_tests.o test.cpp -o test

example: surlparser.o surlparser.h
	g++ -std=c++11 -Os surlparser.o example.cpp -o example

surlparser.o: surlparser.h surlparser.cpp
	g++ -std=c++11 -Os -c surlparser.cpp -o $@

linkedlist.o: linkedlist.h linkedlist.cpp
	g++ -std=c++11 -Os -c linkedlist.cpp -o $@

surlparser_tests.o: surlparser.h surlparser.cpp
	g++ -std=c++11 -Os -c surlparser.cpp -o $@ -DTESTS

clean:
	rm -f test example surlparser.o linkedlist.o

