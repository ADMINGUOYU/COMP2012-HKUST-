
// b: Bothclassmember functions and global functions can be inline functions.
inline int func1 (int i) {; }

// d: Copy constructor
class A
{
    int x;
public:
    A(const A a) { x = a.x; }
    // ERROR: copy constructor for class "A" may not have a parameter of type "A"C/C++(408)
};

// e: If  objects A and B both belong to the same class, then A and B can access each others
//    private data members through their member functions.
//      -> if you have the address to THAT object