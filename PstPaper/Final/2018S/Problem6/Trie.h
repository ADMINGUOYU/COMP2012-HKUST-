/* File: Trie.h */
#ifndef TRIE_H_
#define TRIE_H_

#include <iostream>
#include <cstring>
#include "TrieNode.h"

class Trie
{
public:
    Trie() { root = new TrieNode(false); } // Constructor

    ~Trie() { delete root; } // Destructor

    void printAll() const
    {
        char partialWord[MAX_WORD_LENGTH];
        printAll(root, partialWord, 0);
    }

    Trie &operator+=(const char *s)
    {
        if (!searchWord(s))
        {
            TrieNode *cur = root;
            for (int i = 0; i < strlen(s); i++)
            {
                if (cur->getChild(s[i]) == nullptr)
                    cur->setChild(s[i], new TrieNode(false));
                cur = cur->getChild(s[i]);
            }

            cur->setEndOfWord(true);
        }

        return *this;
    }

    // TODO (c)(i) : Return true if the word is a stored word in the trie;
    // otherwise false
    bool searchWord(const char *s) const;

    // TODO (c)(ii) : Copy constructor
    Trie(const Trie &another);

    // TODO (c)(ii) : Move constructor
    Trie(Trie &&another);

    // TODO (c)(ii) : Copy assignment operator
    Trie &operator=(const Trie &another);

    // TODO (c)(ii) : Move assignment operator
    Trie &operator=(Trie &&another);

private:
    TrieNode *root = nullptr;

    // TODO (d): [BONUS] Print all words in lexicographical order
    void printAll(const TrieNode *n, char *partialWord, int len) const;
};

#endif /* TRIE_H_ */