#include <iostream>     /* File: const-object-date.cpp */
using namespace std;
#include "const-object-date.h"

int main()   // There are problems with this code; what are they?
{
    const Date WW2(1945, 9, 2); // World War II ending date
    Date today;
    WW2.print();
    // error: the object has type qualifiers that are not compatible with the member function "Date::print"C/C++(1086)
    // const-object-date.cpp(9, 5): object type is: const Date
    // const Date WW2
    // World War II ending date

    today.print();

    // How long has it been since World War II?
    cout << "Today is " << today.difference(WW2)
         << " days after WW2" << endl;
    
    // What about next month?
    WW2.add_month();    // Error; do you mean today.add_month()??
    // error: the object has type qualifiers that are not compatible with the member function "Date::add_month"C/C++(1086)
    // const-object-date.cpp(17, 5): object type is: const Date
    // const Date WW2
    // World War II ending date

    cout << today.difference(WW2) << " days by next month.\n";

    return 0;
}
