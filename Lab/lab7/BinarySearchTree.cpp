#include "BinarySearchTree.h"
using namespace std;

BinarySearchTree::BinarySearchTree(int score, int studentId, bool isRoot) : 
    score(score), studentId(studentId), isRoot(isRoot), leftSubTree(nullptr), rightSubTree(nullptr) {}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& other) : {
    // TODO #1: Copy constructor
}

BinarySearchTree::~BinarySearchTree() {
    // TODO #2: Destructor
}

bool BinarySearchTree::findByScore(int score) const {
    // TODO #3: Search by score
    bool found = false;
    if (found) {
        printStudentInfo();
    } else {
        printFailedInfo();
    }
    return found;
}

void BinarySearchTree::insert(int score, int studentId) {
    // TODO #4: Insert a node
    bool success = false;
    if (success) {
        cout << "Inserted successfully." << endl;
    } else {
        cout << "Skipping due to a duplicate." << endl;
    }
}

void BinarySearchTree::inorderTraversal() const {
    // TODO #5: In-order traversal 
}

void BinarySearchTree::printAllScoreBelow(int threshold) const {
    // TODO #6: Print students below a threshold score
}

// Provided utility functions (no modification needed)
void BinarySearchTree::printStudentInfo() const {
    cout << "Student Info: [SID: " << studentId << ", Score: " << score << "]." << endl;
}


void BinarySearchTree::printFailedInfo() const {
    cout << "Student not found." << endl;
}