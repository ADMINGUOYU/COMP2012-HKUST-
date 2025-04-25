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
    switch (this->alg)
    {
    case CRAlg::LINEAR:
        return (i);
    case CRAlg::QUADRATIC:
        return (i * i);
    default:
    // enum not matched
        return 0;
    }
    // TODO #1: --- END ---
}

/*
    TODO 2: tableInsert function
    - key: The key to insert
    - It inserts the key to the hash table. We assume the insertion is always successful in this game.
    - You can assume the insertion is always successful in this game.
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
        if (Status::ACTIVE != this->table[j].status)
        {
            // if the cell is not currently in use
            // insert
            this->table[j].key = key;
            this->table[j].status = Status::ACTIVE;
            // return after successful insertion
            return;
        }
        // TODO #2: --- END ---

        j = (index + tableOffset(i)) % tableSize; // Compute the next probe location
        i++;                                      // Number of probes + 1
    }
}

/*
    TODO 3: tableRemove function
    - key: The key to remove
    - It performs lazy deletion for the key if it is found.
    - For performance reasons, this function should early return if the key is found or probing meets an empty slot.
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
        switch (this->table[j].status)
        {
        case Status::ACTIVE:
        {
            // this case, the value is valid
            // check the value first

            if (key == this->table[j].key) 
            {
                // perform lazy deletion
                this->table[j].key = Status::DELETE;
                // early return
                return;
            }

            // if key not matched, break switch
            // continue to next iteration
            break;
        }
        case Status::EMPTY:
            // early return
            return;
        default:
            // this case -> invalid or DELETE
            // go to next iteration
            break;
        }
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
        switch (this->table[j].status)
        {
        case Status::ACTIVE:
        {
            // this case, the value is valid
            // check the value first

            if (key == this->table[j].key) { nProbes = i; return true; }

            // if key not matched, break switch
            // continue to next iteration
            break;
        }
        case Status::EMPTY:
            // early return
            nProbes = i;
            return false;
        default:
            // this case -> invalid or DELETE
            // go to next iteration
            break;
        }
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
    - h(key) = { Σ( L − 1 , i = 0) [37 ^ (L − 1 − i) * k[i]] } mod m
*/
unsigned int WordGame::hashFunc(const string &key)
{
    // TODO #5: --- BEGIN ---
    unsigned int hashedValue {0};
    const int length = key.length();
    const int PRIME = 37;

    // Σ( L − 1 , i = 0) [37 ^ (L − 1 − i) * k[i]]
    for (int i = 0; i < length; i++)
    {
        int poweredPrime {1};
        for (int j = 0; j < (length - i - 1); j++) poweredPrime *= PRIME;
        hashedValue += (poweredPrime * key[i]);
    }

    // mod m
    hashedValue %= this->tableSize;

    // return hashed value
    return hashedValue;
    // TODO #5: --- END ---
}

/*
    TODO 6: queryWord function
    - word: The word to query
    - It checks if the word is valid and print the information. If the word is valid, it then removes the word from the table.
    - If the word is valid, score is increased by 1. If the word is invalid, score is reset to 0.
    - Rule 1: The word should have exactly 5 letters.
    - Rule 2: The first letter of the word should be the same as the last letter of the previous valid word.
*/
void WordGame::queryWord(const string &word)
{
    // TODO #6: --- BEGIN ---
    const int LENGTH = 5;
    std::cout << "Query \"" << word << "\": ";

    // Rule check
    if 
    (
        (word.length() == LENGTH) 
        &&
        (
            ("" == this->prevWord)
            ||
            (this->prevWord[LENGTH - 1] == word[0])
        )
    ) 
    {
        unsigned int nProbes { };
        if (this->tableFind(word, nProbes))
        {
            // if the word is in hash table
            this->tableRemove(word);
            this->score++;
            this->prevWord = word;
            std::cout << "Found ";
        }
        else
        {
            // not found in hash table
            this->score = 0;
            std::cout << "Not found ";
        }
        std::cout << "(probes: " << nProbes << ", score: " << this->score << ")" << std::endl;
    }
    else
    {
        // Here, the word does not follow the rules
        this->score = 0;
        // Here, the score is hard coded
        // To speed up the print process
        std::cout << "Invalid word (score: 0)" << std::endl;
    }

    return;
    // TODO #6: --- END ---
}