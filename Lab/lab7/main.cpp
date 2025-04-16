#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
    cout << "Start processing binary search tree 1." << endl;
    cout << "Create the tree 1 with SID 202501 with score 60." << endl;
    BinarySearchTree* bst1 = new BinarySearchTree(60, 202501, true);

    cout << "Try to insert SID 202502 with score 75:" << endl;
    bst1->insert(75, 202502);
    cout << "Try to insert SID 202503 with score 55:" << endl;
    bst1->insert(55, 202503);
    cout << "Try to insert SID 202504 with score 65:" << endl;
    bst1->insert(65, 202504);
    cout << "Try to insert SID 202505 with score 80:" << endl;
    bst1->insert(80, 202505);

    cout << "Check the info with Score 100: " << endl;
    bst1->findByScore(100);
    cout << "Check the info with Score 80: " << endl;
    bst1->findByScore(80);

    cout << "Print students by ascending order." << endl;
    bst1->inorderTraversal();

    cout << "End processing binary search tree 1." << endl << endl;
    cout << "Start processing binary search tree 2." << endl;
    cout << "Create the tree by copying tree 1." << endl;

    BinarySearchTree* bst2 = new BinarySearchTree(*bst1);
    cout << "Try to insert SID 202506 with score 90:" << endl;
    bst2->insert(90, 202506);
    cout << "Try to insert SID 202503 with score 55:" << endl;
    bst2->insert(55, 202503);

    cout << "Print students by ascending order." << endl;
    bst2->inorderTraversal();

    cout << "Print students with score below 75." << endl;
    bst2->printAllScoreBelow(75);
    cout << "End processing binary search tree 2." << endl;
    delete bst1;
    delete bst2;
    return 0;
}
