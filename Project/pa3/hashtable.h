#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <iostream>
#include "hash.h"

using namespace std;

template <typename T>
class HashTable {

    private:
        struct TableNode {
		    // The number of elements in this table node
            int table_size;

            // The number of buckets in this table node equals to (2^exponent_size)
            int exponent_size;
            
            // An array of vectors that act as the buckets
            // Separate chaining is used to resolve collisions
            vector<T>* table;

            // TableNodes are linked together - just like a linked list
            // The next TableNode in the linked list - nullptr if no next TableNode
            TableNode* next;
        };

        // Head TableNode (i.e. head node of the linked list) - use for searching
        TableNode* head_node;

        // The total element stored in all the table nodes
        int total_size;

        // Current TableNode (i.e. last node of the linked list) - use for inserting
        TableNode* cur_node;

        // The maximum load factor of a TableNode
        double max_load_factor;

    public:
        
        // Return the size of the hash table
        int size() const { return total_size; }

        // TODO: Implement the constructor in hashtable.tpp
        HashTable(int base_exponent = 2, double max_load_factor = 2);

        // TODO: Implement the destructor in hashtable.tpp
        ~HashTable();

        // TODO: Implement the operator= in hashtable.tpp
        HashTable& operator=(const HashTable& other);

        // TODO: Implement the copy constructor in hashtable.tpp
        HashTable(const HashTable& other);

        // TODO: Implement the exists function in hashtable.tpp
        bool exists(const T& value) const;

        // TODO: Implement the insert function in hashtable.tpp
        bool insert(const T& value);

        // TODO: Implement the remove function in hashtable.tpp
        bool remove(const T& value);

        // Return all the elements in the hash table
        vector<T> to_vector() const;

};

#include "hashtable.tpp"

#endif