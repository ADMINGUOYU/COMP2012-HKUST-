#include <iostream>     /* File: static-var-function.cpp */
using namespace std;

int fibonacci(int n, int& calls)
{
    static int num_calls = 0; // Initialized only once
    calls = ++num_calls;
    
    if (n <= 0) 
        return 0;
    else if (n == 1 || n == 2)
        return 1;
    else
        return fibonacci(n-2, calls) + fibonacci(n-1, calls);
}
int main() 
{
    int n; int n_calls;
    cout << "Enter n: "; cin >> n; 
    cout << "\nfibonacci(" << n << ") = " << fibonacci(n, n_calls);
    cout << "\nnumber of fibonacci calls = " << n_calls << endl;
    return 0;
}
