#include <iostream>
using namespace std;
template <typename T1, typename T2>
class Pair
{
    friend ostream &operator<<(ostream &os, const Pair<T1, T2> &p);

public:
    Pair(T1 v1, T2 v2) : value1(v1), value2(v2) {};

private:
    T1 value1;
    T2 value2;
};
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const Pair<T1, T2> &p)
{
    os << p.value1 << ": " << p.value2;
    return os;
}
int main()
{
    Pair<int, char> p(10, 'c');
    return 0;
}

/*
https://isocpp.org/wiki/faq/templates#template-friends

Compiler warning:
test.cpp:6:66: warning: friend declaration ‘std::ostream& operator<<(std::ostream&, const Pair<T1, T2>&)’ declares a non-template function [-Wnon-template-friend]
    6 |     friend ostream &operator<<(ostream &os, const Pair<T1, T2> &p);
      |                                                                  ^
test.cpp:6:66: note: (if this is not what you intended, make sure the function template has already been declared and add <> after the function name here)

Doing this gets rid of the warning:
class Pair
{
    template <typename T3, typename T4>
    friend ostream &operator<<(ostream &os, const Pair<T3, T4> &p);

public:
......
}
*/

/*
This is WRONG
class Pair
{
    template <typename T1, typename T2>
    friend ostream &operator<<(ostream &os, const Pair<T1, T2> &p);

public:
......
}

ERROR:
test.cpp:6:15: error: declaration of template parameter ‘T1’ shadows template parameter
    6 |     template <typename T1, typename T2>
      |               ^~~~~~~~
test.cpp:3:11: note: template parameter ‘T1’ declared here
    3 | template <typename T1, typename T2>
      |           ^~~~~~~~
test.cpp:6:28: error: declaration of template parameter ‘T2’ shadows template parameter
    6 |     template <typename T1, typename T2>
      |                            ^~~~~~~~
test.cpp:3:24: note: template parameter ‘T2’ declared here
    3 | template <typename T1, typename T2>
      |  
*/