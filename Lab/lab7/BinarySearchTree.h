#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>

class BinarySearchTree
{
private:
    int score;
    int studentId;
    bool isRoot;

    BinarySearchTree* leftSubTree;
    BinarySearchTree* rightSubTree;

public:
    // Provided utility functions (no modification needed)
    BinarySearchTree() = delete;
    BinarySearchTree(int score, int studentId, bool isRoot=true); // Constructor

    void printStudentInfo() const;
    void printFailedInfo() const;

    // TODO: Functions to be implemented
    BinarySearchTree(const BinarySearchTree& other); // Copy constructor (TODO #1)
    ~BinarySearchTree();                             // Destructor (TODO #2)
    
    bool findByScore(int score) const;               // Search by score (TODO #3)
    void insert(int score, int studentId);           // Insert a node (TODO #4)
    void inorderTraversal() const;                   // In-order traversal (TODO #5)
    void printAllScoreBelow(int threshold) const;    // Print students below a threshold score (TODO #6)
};

#endif