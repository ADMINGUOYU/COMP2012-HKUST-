#include "Trie.h"

bool Trie::searchWord(const char *s) const
{
    TrieNode* working_ptr = this->root;
    int letter_count = 0;
    for (char c = s[letter_count]; c != '\0'; letter_count++)
    {
        working_ptr = working_ptr->getChild((char)c);
        // match the letter one-by-one
        if (!working_ptr)
        {
            // nullpter here, no such word
            return false;
        }
        // update letter count
        letter_count++;
    }
    // check for end-of-word
    // if is end-of-word, return true
    return working_ptr->getEndOfWord();
}

Trie::Trie(const Trie &another)
    :
    root{ new TrieNode { *another.root } }
{ return; }

Trie::Trie(Trie &&another)
    :
    root{ another.root }
{
    another.root = nullptr;
    return;
}

Trie &Trie::operator=(const Trie &another)
{
    delete this->root;
    this->root = new TrieNode { *another.root };
    return (*this);
}

Trie &Trie::operator=(Trie &&another)
{
    delete this->root;
    this->root = another.root;
    another.root = nullptr;
    return (*this);
}

void Trie::printAll(const TrieNode *n, char *partialWord, int len) const
{
    // check if this is the ending of a word
    if (n->getEndOfWord())
    {
        // we have to print partial word
        for (int i = 0; i < len; i++)
            std::cout << partialWord[i];
        std::cout << std::endl;
    }
    // go to all its children
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        TrieNode* node;
        if (node = n->getChild((int)i))
        {
            // create a copy of partialWord (for its child to use)
            /*
            If you don't want to copy, you can reuse the buffer
            By cleverly update 'len'
            as 'len' only grows
            the tailing garbage data will not be printed after '\0' is added
            */
            char partialWord_cpy[MAX_WORD_LENGTH];
            // not a valid cstring, have to copy manually
            for (int j = 0; j < len; j++)
                partialWord_cpy[j] = partialWord[j];
            partialWord_cpy[len] = 'a' + i;
            this->printAll(node, partialWord_cpy, len + 1);
        }
        // if a child is nullptr, ignore it
    }
    return;
}
