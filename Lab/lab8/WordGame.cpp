#include "WordGame.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

WordGame::WordGame(unsigned int tableSize, CRAlg alg)
    : tableSize(tableSize), alg(alg)
{
    table = new Entry[tableSize];
    prevWord = "";
    score = 0;
}

WordGame::~WordGame()
{
    delete[] table;
}

void WordGame::init()
{
    score = 0;
    prevWord = "";
    for (unsigned int i = 0; i < tableSize; i++)
    {
        table[i].status = Status::EMPTY;
    }

    cout << "Loading words..." << endl;
    ifstream file(WORD_FILE);
    string word;
    while (getline(file, word))
    {
        tableInsert(word);
    }
    cout << "Loading words finished." << endl;
}

/*
    TODO 1: tableOffset function (equivalent to f in the lecture notes p.21):
    - i: The number of collisions
    - Returns the offset from the home location according to the current collision resolution algorithm, alg.
*/
unsigned int WordGame::tableOffset(int i)
{
    // TODO #1: --- BEGIN ---

    // TODO #1: --- END ---
}

/*
    TODO 2: tableInsert function
    - key: The key to insert
    - It inserts the key to the hash table. We assume the insertion is always successful in this game.
*/
void WordGame::tableInsert(const string &key)
{
    // Given
    unsigned int index = hashFunc(key); // Compute the home location
    unsigned int i = 1;                 // The number of probes
    unsigned int j = index;             // The next probe location

    // Given
    while (i < tableSize * 2) // Assume the number of probes should be less than 2*tableSize
    {
        // TODO #2: --- BEGIN ---

        // TODO #2: --- END ---

        j = (index + tableOffset(i)) % tableSize; // Compute the next probe location
        i++;                                      // Number of probes + 1
    }
}

/*
    TODO 3: tableRemove function
    - key: The key to remove
    - It performs lazy deletion for the key if it is found.
*/
void WordGame::tableRemove(const string &key)
{
    // Given
    unsigned int index = hashFunc(key); // Compute the home location
    unsigned int i = 1;                 // The number of probes
    unsigned int j = index;             // The next probe location

    // Given
    while (i < tableSize * 2) // Assume the number of probes should be less than 2*tableSize
    {
        // TODO #3: --- BEGIN ---

        // TODO #3: --- END ---

        j = (index + tableOffset(i)) % tableSize; // Compute the next probe location
        i++;                                      // Number of probes + 1
    }
}

/*
    TODO 4: tableFind function
    - key: The key to find
    - nProbes: number of probes used to find the key
    - Returns whether the key is found
*/
bool WordGame::tableFind(const string &key, unsigned int &nProbes)
{
    // Given
    unsigned int index = hashFunc(key); // Compute the home location
    unsigned int i = 1;                 // The number of probes
    unsigned int j = index;             // The next probe location

    // Given
    while (i < tableSize * 2) // Assume the number of probes should be less than 2*tableSize
    {
        // TODO #4: --- BEGIN ---

        // TODO #4: --- END ---

        j = (index + tableOffset(i)) % tableSize; // Compute the next probe location
        i++;                                      // Number of probes + 1
    }
    // Key not in the table
    nProbes = i;
    return false;
}

/*
    TODO 5: hashFunc function
    - key: The key to hash
    - Returns the hash value of the key. The hash function follows the equation of method 3 from lecture notes p.14.
    - https://course.cse.ust.hk/comp2012/notes/h.hashing.pdf#page=14
*/
unsigned int WordGame::hashFunc(const string &key)
{
    // TODO #5: --- BEGIN ---

    // TODO #5: --- END ---
}

/*
    TODO 6: queryWord function
    - word: The word to query
    - It checks if the word is valid and print the information. If the word is valid, it then removes the word from the table.
    - If the word is valid, score is increased by 1. If the word is invalid, score is reset to 0.
*/
void WordGame::queryWord(const string &word)
{
    // TODO #6: --- BEGIN ---

    // TODO #6: --- END ---
}