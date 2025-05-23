/* File: TrieNode.h */
#ifndef TRIENODE_H_
#define TRIENODE_H_

#include <iostream>
using namespace std;

const int MAX_WORD_LENGTH = 128; // The maximum word length supported
const int ALPHABET_SIZE = 26;    // 26 English characters

class TrieNode
{
public:
    // TODO: (b)(i) : Conversion constructor
    TrieNode(bool endOfWord);

    // TODO: (b)(ii) : Copy constructor; deep copy is required
    TrieNode(const TrieNode &node);

    // TODO: (b)(iii): Destructor; must release all dynamically allocated memory
    ~TrieNode();

    // Helper functions to get or set a child by either a char or an int.
    // For example, both getChild('e') and getChild(4) return the child
    // representing 'e' (i.e., character 'a'+4).
    TrieNode *getChild(char c) const { return children[c - 'a']; }
    TrieNode *getChild(int i) const { return children[i]; }
    void setChild(char c, TrieNode *child) { children[c - 'a'] = child; }
    void setChild(int i, TrieNode *child) { children[i] = child; }
    // Accessor and mutator
    bool getEndOfWord() const { return endOfWord; }
    void setEndOfWord(bool e) { endOfWord = e; }

private:
    // endOfWord is true if the word associated with this node
    // is complete, thus a complete word stored in the trie
    bool endOfWord = false;

    // children is an array of TrieNode pointers. If children[i] is not
    // nullptr, the concatenation of the partial word associated with this
    // node and the character 'a'+i is a prefix of at least one word stored
    // in the trie. In the example given, children[17] of the node with the
    // partial word "ca" is not nullptr. The concatenation of the partial
    // word "ca" and the character 'a'+17, i.e., "car", is a prefix of the
    // words "car" and "care" stored in the trie.
    TrieNode *children[ALPHABET_SIZE] = {};
};

#endif /* TRIENODE_H_ */