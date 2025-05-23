/* File: test-print-trie.cpp */
#include "Trie.h"
int main()
{
    Trie t;
    t += "ease";
    t += "cater";
    t += "easy";
    t += "care";
    t += "car";
    t += "cat";
    t.printAll();
    return 0;
}

/*
compile command:
g++ -fsanitize=address,undefined,leak TrieNode.cpp Trie.cpp test-print-trie.cpp

output:
car
care
cat
cater
ease
easy
*/