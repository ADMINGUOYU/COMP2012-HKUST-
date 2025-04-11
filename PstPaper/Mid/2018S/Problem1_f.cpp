#include <iostream>

class Object
{
    public:
    int var_a;
    int var_b;
};

Object func_1(Object obj) { return obj; }
Object func_2(Object& obj) { return obj; }
Object& func_3(Object obj) { return obj; }
Object& func_4(Object& obj) { return obj; }

int main (void)
{
    Object obj_0 { 10, 20 };

    func_1(obj_0).var_a = 100;  // ERROR: expression must be a modifiable lvalue
    func_2(obj_0).var_a = 100;  // ERROR: expression must be a modifiable lvalue

    // g++ Warning: warning: reference to local variable ‘obj’ returned [-Wreturn-local-addr]
    // Runtime ERROR (potential): Segmentation fault (core dumped)
    func_3(obj_0).var_a = 100;
    std::cout << obj_0.var_a << std::endl; 
    // OK
    func_4(obj_0).var_a = 100;
    std::cout << obj_0.var_a << std::endl;

    return 0;
}

/*
Basically there are two different scenarios (shown above),
But the actual thing you have to consider is -> whether the object is VALID
-> whether its a temp object (that will be poped when out-of-scope)
*/