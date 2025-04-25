#ifndef WORDGAME_H
#define WORDGAME_H

#include "utils.h"

class WordGame
{
private:
    unsigned int tableSize; // Hash table size
    CRAlg alg;              // Collision resolution algorithm for the hash table
    Entry *table;           // An array of Entry objects to act as a hash table
    string prevWord;        // Previous word
    unsigned int score;     // Score for number of valid words in a row

    /*
        TODO 1: tableOffset function (equivalent to f in the lecture notes p.21):
        - i: The number of collisions
        - Returns the offset from the home location according to the current collision resolution algorithm, alg.
    */
    unsigned int tableOffset(int i);

    /*
        TODO 2: tableInsert function
        - key: The key to insert
        - It inserts the key to the hash table. We assume the insertion is always successful in this game.
    */
    void tableInsert(const string &key);

    /*
        TODO 3: tableRemove function
        - key: The key to remove
        - It performs lazy deletion for the key if it is found.
    */
    void tableRemove(const string &key);

    /*
        TODO 4: tableFind function
        - key: The key to find
        - nProbes: number of probes used to find the key
        - Returns whether the key is found
    */
    bool tableFind(const string &key, unsigned int &nProbes);

    /*
        TODO 5: hashFunc function
        - key: The key to hash
        - Returns the hash value of the key. The hash function follows the equation of method 3 from lecture notes p.14.
        - https://course.cse.ust.hk/comp2012/notes/h.hashing.pdf#page=14
    */
    unsigned int hashFunc(const string &key);

public:
    WordGame(unsigned int tableSize, CRAlg alg);
    ~WordGame();

    void init();

    /*
        TODO 6: queryWord function
        - word: The word to query
        - It checks if the word is valid and print the information. If the word is valid, it then removes the word from the table.
        - If the word is valid, score is increased by 1. If the word is invalid, score is reset to 0.
    */
    void queryWord(const string &word);
};

#endif