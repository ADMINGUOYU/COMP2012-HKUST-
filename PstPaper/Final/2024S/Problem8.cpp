#include <iostream>
#include <cmath>
#include <limits>
using namespace std;
// Template function to compare if two floating-point values are equal
// within a small tolerance (epsilon)
template <typename T>
bool same(T a, T b) { return fabs(a - b) < numeric_limits<T>::epsilon(); }
// User-defined Pair struct template to store two values of different types
template <typename T1, typename T2>
struct Pair
{
    T1 first;
    T2 second;
    Pair() : first(), second() {}
    Pair(const T1 &first, const T2 &second) : first(first), second(second) {}
};
// Struct to store major preferences in a linked list
// The linked list is designed such that the first node of the list is non-dynamic.
// All subsequent nodes are dynamic deep copies of other existing non-dynamic nodes.
struct MajorPref
{
    string maj;
    MajorPref *next = nullptr;
    // **** TODO (a): MajorPref, which performs a deep copy ****
    MajorPref(string maj, MajorPref *next)
        : maj{maj},
          next{next}
    {
        // * if next == nullptr, will not enter this if statement
        if (this->next)
            this->next = new MajorPref{*(this->next)};
        return;
    }

    MajorPref(const MajorPref &m) : MajorPref(m.maj, m.next) {}
    ~MajorPref() { delete next; }
};

// Struct to store student data
struct Student
{
    int id;
    string name;
    double cgpa;
    MajorPref *majorPrefs = nullptr;
    Student(int id, string name, double cgpa, MajorPref *majorPrefs)
        : id(id), name(name), cgpa(cgpa), majorPrefs(majorPrefs) {}
};
// Struct to represent a node in the BST, storing a student and pointers
// to left and right student nodes
struct StudentNode
{
    Student student;
    StudentNode *left = nullptr;
    StudentNode *right = nullptr;
    StudentNode(const Student &s) : student(s), left(nullptr), right(nullptr) {}
    ~StudentNode()
    {
        delete left;
        delete right;
    }
};
// Class to represent the School, using a BST to store and manage students
// based on their CGPA. Please note that the BST in this question allows
// duplicates of CGPA, and the arrangement of the nodes is as follows.
// CGPAs in left < CGPA of root <= CGPAs in the right
class School
{
private:
    StudentNode *root;
    // IMPLEMENTED: Helper function to insert a student into the BST.
    StudentNode *insertStudent(StudentNode *node, const Student &s)
    {
        if (node == nullptr)
            return new StudentNode(s);
        if (s.cgpa < node->student.cgpa)
            node->left = insertStudent(node->left, s);
        else
            node->right = insertStudent(node->right, s);
        return node;
    }
    // IMPLEMENTED: Helper function to find the node with the minimum CGPA
    // value in the BST
    StudentNode *minCGPANode(StudentNode *node) const
    {
        StudentNode *current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }
    // IMPLEMENTED: Helper function to search for a student with the given ID
    // in the BST.
    // It returns the node with the student id.
    StudentNode *searchByID(StudentNode *node, int id)
    {
        if (node == nullptr || node->student.id == id)
            return node;
        StudentNode *leftResult = searchByID(node->left, id);
        if (leftResult != nullptr)
            return leftResult;
        return searchByID(node->right, id);
    }
    // **** TODO (b): Helper function to remove a student with the given
    // id from the BST. ****
    // node: A pointer representing the current node
    // id: The student ID
    // It returns the updated node.
    // Note: The removal strategy for 2-child case is the same as in the lecture
    // notes, i.e. the minimum node of the right subtree is moved to the "removed" node.
    // Also, if the student with the given id is not found in the BST, then the BST will
    // not be updated at all.
    StudentNode *removeStudent(StudentNode *node, int id)
    {
        // check whether this is the end
        if (!node) return nullptr;
        // check if this is the one to delete
        if (id == node->student.id)
        {
            // check if this node has two sub-trees
            if (node->left && node->right)
            {
                // get min of right sub-tree
                StudentNode* right_min = this->minCGPANode(node->right);
                // copy data from right_min
                node->student = right_min->student;
                // delete right_min node
                this->removeStudent(node->right, right_min->student.id);
                // the current node still exists
                return node;
            }
            // only one or no sub-tree
            StudentNode* new_node = (node->left) ? node->left : node->right;
            // detatch this node (prevent recursive deletion)
            node->left = nullptr;
            node->right = nullptr;
            // delete node
            delete node;
            // return the new root
            return new_node;
        }
        // we have to find the node elsewhere
        // and re-attach the new roots (returned)
        node->left = this->removeStudent(node->left, id);
        node->right = this->removeStudent(node->right, id);
        // since this node is still the root
        // return this node
        return node;
    }
    // **** TODO (c): Helper function to print students in the BST whose
    // CGPA is within the specified range (inclusive) ****
    // node: A pointer representing the current node
    // minCgpa and maxCgpa: They represent the range of CGPA
    // Note: If students have the same CGPA, the student with lower depth will be
    // printed first. Also, you may assume that the range will always be valid.
    void printRange(const StudentNode *node, double minCgpa, double maxCgpa) const
    {
        // base case: node == nullptr
        if (!node) return;
        // use in-order approach
        // as CGA allows duplicates, we have to go through all
        // print left
        this->printRange(node->left, minCgpa, maxCgpa);
        // print this node (if criteria matches)
        if (node->student.cgpa >= minCgpa && node->student.cgpa <= maxCgpa)
            std::cout << "[ " 
                    << node->student.id << ", "
                    << node->student.name << ", "
                    << node->student.cgpa
                    << " ] " ;
        // print right
        this->printRange(node->right, minCgpa, maxCgpa);
        // return
        return;
    }
    // **** TODO (d): Helper function to assign majors to students based on their
    // preferences, CGPA, and the availability of slots in each major ****
    // node: A pointer representing the current node
    // majorSlots: An array of Pair objects representing the major slots
    // numSlots: It represents the number of slots
    //
    // The major assignment is based on the criteria:
    //- It assigns majors to students with high CGPA before low CGPA.
    // If two students have the same CGPA, then the major should be assigned first
    // to the student whose node is deeper in the BST.
    //- For each student, he/she is being assigned with the most preferred major
    // if the major slot is available. Otherwise, he/she is being assgined with
    // the next preferred major if the slot is available, and so on.
    // Note: If all of a student's preferences are unavailable, let the student's major
    // remain unassigned. Also, the students do not need to be removed from the BST
    // after they are assigned a major.
    // For your convenience, the print statement is provided for you below:
    // cout << "Assigning major " << major << " to student "
    // << node->student.name << endl;
    void assignMajor(StudentNode *node, Pair<string, int> majorSlots[], int numSlots)
    {
        // check if its nullptr
        if(!node) return;
        // assign right (higher GPA)
        this->assignMajor(node->right, majorSlots, numSlots);
        // assign this
        for (MajorPref* mj = node->student.majorPrefs; mj != nullptr; mj = mj->next)
        {
            bool matched = false;
            // check availability
            for (int i = 0; i < numSlots; i++)
            {
                if ((majorSlots[i].first == (mj->maj)) && (majorSlots[i].second > 0))
                {
                    // now assign
                    std::cout << "Assigning major " << majorSlots[i].first << " to student " << node->student.name << std::endl;
                    // decrease major vacancies
                    majorSlots[i].second--;
                    // set flag
                    matched = true;
                    // break from the loop
                    break;
                }
            }
            if (matched) break;
        }
        // assign left (lower GPA)
        this->assignMajor(node->left, majorSlots, numSlots);
        // return
        return;
    }

public:
    School() : root(nullptr) {}
    ~School() { delete root; }
    // IMPLEMENTED: Insert a student into the BST
    void insertStudent(Student s) { root = insertStudent(root, s); }
    // IMPLEMENTED: Remove a student with the given id from the BST
    void removeStudent(int id) { root = removeStudent(root, id); }
    // IMPLEMENTED: Display all students in the BST whose CGPA is within the
    // specified range (inclusive)
    void displayStudents(double minCgpa = -1, double maxCgpa = 4.3) const
    {
        printRange(root, minCgpa, maxCgpa);
        cout << endl;
    }
    // IMPLEMENTED: Assign majors to students based on their CGPA, preferences,
    // and the availability of slots in each major
    void assignMajors(Pair<string, int> majorSlots[], int numSlots)
    {
        assignMajor(root, majorSlots, numSlots);
    }
};

int main()
{
    School seng;
    MajorPref prefA2{"MECH", nullptr};
    MajorPref prefA1{"COMP", &prefA2};
    Student s1{1, "John", 3.5, &prefA1}; // 1st: COMP, 2nd: MECH
    MajorPref prefB2{"CPEG", nullptr};
    MajorPref prefB1{"COMP", &prefB2};
    Student s2{2, "Peter", 3.7, &prefB1}; // 1st: COMP, 2nd: CPEG
    MajorPref prefC2{"MECH", nullptr};
    MajorPref prefC1{"ELEC", &prefC2};
    Student s3{3, "Macy", 3.2, &prefC1}; // 1st: ELEC, 2nd: MECH
    MajorPref prefD2{"CPEG", nullptr};
    MajorPref prefD1{"COMP", &prefD2};
    Student s4{4, "Judy", 3.8, &prefD1}; // 1st: COMP, 2nd: CPEG
    MajorPref prefE2{"ELEC", nullptr};
    MajorPref prefE1{"MECH", &prefE2};
    Student s5{5, "Carson", 3.2, &prefE1}; // 1st: MECH, 2nd: ELEC
    seng.insertStudent(s1);
    seng.insertStudent(s2);
    seng.insertStudent(s3);
    seng.insertStudent(s4);
    seng.insertStudent(s5);
    cout << "Students in the school: " << endl;
    seng.displayStudents();
    seng.removeStudent(3);
    cout << "Students after removing Macy: " << endl;
    seng.displayStudents();
    seng.insertStudent(s3);
    cout << "Students after re-inserting Macy: " << endl;
    seng.displayStudents();
    cout << "Students with CGPA between 3.5 and 3.8: " << endl;
    seng.displayStudents(3.5, 3.8);
    Pair<string, int> major_slots[] = {{"COMP", 1}, {"CPEG", 2}, {"MECH", 1}, {"ELEC", 2}};
    seng.assignMajors(major_slots, 4);
}

/*
compile command: g++ -fsanitize=address,undefined,leak Problem8.cpp
*/
/*
output:
Students in the school: 
[ 3, Macy, 3.2 ] [ 5, Carson, 3.2 ] [ 1, John, 3.5 ] [ 2, Peter, 3.7 ] [ 4, Judy, 3.8 ] 
Students after removing Macy: 
[ 5, Carson, 3.2 ] [ 1, John, 3.5 ] [ 2, Peter, 3.7 ] [ 4, Judy, 3.8 ] 
Students after re-inserting Macy: 
[ 5, Carson, 3.2 ] [ 3, Macy, 3.2 ] [ 1, John, 3.5 ] [ 2, Peter, 3.7 ] [ 4, Judy, 3.8 ] 
Students with CGPA between 3.5 and 3.8: 
[ 1, John, 3.5 ] [ 2, Peter, 3.7 ] [ 4, Judy, 3.8 ] 
Assigning major COMP to student Judy
Assigning major CPEG to student Peter
Assigning major MECH to student John
Assigning major ELEC to student Macy
Assigning major ELEC to student Carson
*/