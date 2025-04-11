/*
ORDER:
The order of member initializers in the list is irrelevant: the actual order of initialization is as follows:

1) If the constructor is for the most-derived class, virtual bases are initialized in the order in which they appear in depth-first left-to-right traversal of the base class declarations (left-to-right refers to the appearance in base-specifier lists).
2) Then, direct bases are initialized in left-to-right order as they appear in this class's base-specifier list.
3) Then, non-static data member are initialized in order of declaration in the class definition.
4) Finally, the body of the constructor is executed.
(Note: if initialization order was controlled by the appearance in the member initializer lists of different constructors, then the destructor wouldn't be able to ensure that the order of destruction is the reverse of the order of construction.)

link: https://en.cppreference.com/w/cpp/language/constructor#:~:text=Initialization%20order,order%20of%20construction.)
*/

class Base
{
    private:
        int a;
    public:
        Base(int a) {}
};
class Derived : public Base
{
    private:
        int b;

    public:
        Derived(int a, int b) : b(b), Base(a) {}
};

int main(void)
{
    Derived obj(1, 2);

    return 0;
}