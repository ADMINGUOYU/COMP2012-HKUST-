#include "TrieNode.h"

TrieNode::TrieNode(bool endOfWord)
    :
    endOfWord{ endOfWord },
    children{ }
{ return; }

/*
Recursive deep copy constructor
*/
TrieNode::TrieNode(const TrieNode &node)
    :
    endOfWord{ node.endOfWord },
    children{ }
{
    // create (copy) nodes
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        // if one is not nullptr, copy
        if (node.children[i]) this->children[i] = new TrieNode { *node.children[i] };
    }
    return;
}

TrieNode::~TrieNode()
{
    // delete nullptr is safe
    // just do it recursively
    for (int i = 0; i < ALPHABET_SIZE; i++)
        delete this->children[i];
    // since children[] is stack allocated
    // no need to delete
    return;
}
