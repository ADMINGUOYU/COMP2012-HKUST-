#ifndef UTILS_H
#define UTILS_H

#include <string>

using namespace std;

const string WORD_FILE = "words5.txt"; // File containing all words
const unsigned int TABLE_SIZE = 7001;  // Size of the hash table

// Possible status for hash table cell
enum Status
{
    ACTIVE,
    EMPTY,
    DELETE
};

// Collision resolution algorithms
enum CRAlg
{
    LINEAR,
    QUADRATIC
};

// Hash table entry
struct Entry
{
public:
    string key;
    Status status;
    Entry() : status(EMPTY) {} // Set status to EMPTY by default
};

#endif