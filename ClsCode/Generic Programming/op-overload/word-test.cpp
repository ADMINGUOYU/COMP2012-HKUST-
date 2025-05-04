#include <iostream>     /* File: word-test.cpp */
using namespace std;
#include "word.h"

int main()
{
    Word ship("Titanic");      // Which constructor? -> Word(const char* s, int k = 1) -> conversion
    Word movie(ship);          // Which constructor? -> copy
    Word song("My heart will go on"); // Which constructor? -> Word(const char* s, int k = 1) -> conversion

    song = song;               // Call assignment operator
    song = movie;              // Call assignment operator
}
