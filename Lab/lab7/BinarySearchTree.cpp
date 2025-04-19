#include "BinarySearchTree.h"
using namespace std;

BinarySearchTree::BinarySearchTree(int score, int studentId, bool isRoot) : 
    score(score), studentId(studentId), isRoot(isRoot), leftSubTree(nullptr), rightSubTree(nullptr) {}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& other)
    :
    BinarySearchTree(other.score, other.studentId, other.isRoot)
{
    // TODO #1: Copy constructor
    // should be deep copy
    // checks nullptr first
    if (other.leftSubTree)
        this->leftSubTree = new BinarySearchTree(*other.leftSubTree);
    if (other.rightSubTree)
        this->rightSubTree = new BinarySearchTree(*other.rightSubTree);

    return;
}

BinarySearchTree::~BinarySearchTree() {
    // TODO #2: Destructor
    // shall be recursive deletion
    if (this->leftSubTree)
        delete this->leftSubTree;
    if (this->rightSubTree)
        delete this->rightSubTree;

    return;
}

/*
Implement the findByScore function, which prints the score details using the helper function printStudentInfo and 
returns true if the student with the score exists in the tree. 
Otherwise, it prints a failure message using printFailedInfo and returns false.
Regardless of the outcome, each search should produce exactly one output message.
*/
bool BinarySearchTree::findByScore(int score) const {
    // TODO #3: Search by score
    bool found = false;
    if (this->score == score) 
    {
        // base case: found
        printStudentInfo();
        return true;
    }

    if ((!found) && this->leftSubTree)
        found = this->leftSubTree->findByScore(score);
    if ((!found) && this->rightSubTree)
        found = this->rightSubTree->findByScore(score);

    if ((!found) && this->isRoot) 
    {
        printFailedInfo();
    }
    return found;
}

/*
Implement the insert function, which inserts a student into the tree if they do not already exist.
You may assume that each student has a unique studentId and score.
If the insertion is successful, print: "Inserted successfully."
If the student already exists in the tree, print: "Skipping due to a duplicate."
*/
void BinarySearchTree::insert(int score, int studentId) {
    // TODO #4: Insert a node
    if (studentId == this->studentId) { cout << "Skipping due to a duplicate." << endl; return; }
    if (this->score < score)
    {
        if (this->rightSubTree) this->rightSubTree->insert(score, studentId);
        else
        {
            this->rightSubTree = new BinarySearchTree(score, studentId, false);
            cout << "Inserted successfully." << endl;
        } 
    }
    if (this->score > score)
    {
        if (this->leftSubTree) this->leftSubTree->insert(score, studentId);
        else
        {
            this->leftSubTree = new BinarySearchTree(score, studentId, false);
            cout << "Inserted successfully." << endl;
        }
    }
    return;
}

/*
Implement the function inorderTraversal which go over the tree and 
print the information by an inorder traversal with the helper function printStudentInfo.
*/
void BinarySearchTree::inorderTraversal() const {
    // TODO #5: In-order traversal 
    if (this->leftSubTree) this->leftSubTree->inorderTraversal();
    this->printStudentInfo();
    if (this->rightSubTree) this->rightSubTree->inorderTraversal();
    return;
}

/*
Implement the printAllScoreBelow function, 
which prints the information of all students whose scores are below the given threshold, 
using an inorder traversal and the helper function printStudentInfo.
*/
void BinarySearchTree::printAllScoreBelow(int threshold) const {
    // TODO #6: Print students below a threshold score
    if (this->leftSubTree) this->leftSubTree->printAllScoreBelow(threshold);
    if (this->score < threshold)
    {
        this->printStudentInfo();
        if (this->rightSubTree) this->rightSubTree->printAllScoreBelow(threshold);
    }
    return;
}

// Provided utility functions (no modification needed)
void BinarySearchTree::printStudentInfo() const {
    cout << "Student Info: [SID: " << studentId << ", Score: " << score << "]." << endl;
}


void BinarySearchTree::printFailedInfo() const {
    cout << "Student not found." << endl;
}