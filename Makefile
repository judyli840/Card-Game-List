all: game unittest

game : cards.cpp main.cpp cards.h
	g++ cards.cpp main.cpp cards.h -o game

unittest : cards.cpp testcards.cpp cards.h
	g++ cards.cpp testcards.cpp cards.h -o unittest
clean :
	rm game unittest
