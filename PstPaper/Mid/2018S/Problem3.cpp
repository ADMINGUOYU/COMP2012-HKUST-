#include <iostream>
using namespace std;
int main()
{
    // A pointer to a pointer to a const int
    const int **ptr1 = new int *;
    /*
    g++ error:
    error: invalid conversion from ‘int**’ to ‘const int**’ [-fpermissive]
    9 |     const int **ptr1 = new int *;
      |                                ^
      |                                |
      |                                int**
    */

    // A const pointer to a pointer to an int
    int **const ptr2 = new int *;
    // A pointer to a pointer to a const int
    const int **ptr3 = new const int *;
    // A pointer to a pointer to a const int
    const int **ptr4 = new int const *;

    // A pointer to a pointer to a const int
    const int** ptr5 = new int* const;
    /*
    ERROR: const object requires an initializer
    g++ error:
    test.cpp:17:33: error: uninitialized const in ‘new’ of ‘int* const’
   27 |     const int **ptr5 = new int *const;
      |   
      
    if we change the code to:
    const int **ptr5 = new int *const {0};
    still ERROR: 
    a value of type "int *const *" cannot be used to initialize an entity of type "const int **"
    g++ error:
    test.cpp:27:41: error: invalid conversion from ‘int* const*’ to ‘const int**’ [-fpermissive]
   27 |     const int **ptr5 = new int *const {0};
      |                                         ^
      |                                         |
      |                                         int* const*
    */
    
    // To evaluate the correctness of the following statements, you may
    // assume that the incorrect statements (if any) are fixed so that all
    // pointer variables declared above are correctly allocated.
    *ptr1 = new int;
    **ptr1 = 1;
    *ptr2 = new int;
    **ptr2 = 2;
    *ptr3 = new int;
    **ptr3 = 3;
    *ptr4 = new int;
    **ptr4 = 4;
    *ptr5 = new int;
    **ptr5 = 5;

    // Assume memory de-allocations are purposely not done here.
    return 0;
}