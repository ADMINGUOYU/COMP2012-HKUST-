#include "word-move.h"     /* File: "word-move.cpp" */

void print_word(const Word& w) { cout << "print const Word&: "; w.print(); }
void print_word(Word&& w) { cout << "print Word&&: "; w.print(); }

int main()
{
    cout << "*** Copy Semantics ***" << endl;
    Word book {"batman"};
    Word movie(book);
    Word song("imagine");
    movie = song;
    print_word(book); cout << endl;

    cout << "*** Move Semantics ***" << endl;
    Word novel {"outliers"}; cout << endl;
    Word novel2 = novel.to_upper_case();    // move constructions
    cout << endl; novel.print(); novel2.print(); cout << endl;

    Word band = "Beatles"; cout << endl;    // move construction
    band = "Eagles"; cout << endl;          // move assignment

    cout << "*** It's all destructions now ***" << endl;
    return 0;
} /* g++ -std=c++11 -fno-elide-constructors word-move.cpp */

/*
Output: (without the 'no-elide-constructors' flag)
*** Copy Semantics ***
conversion: batman ; 1
copy: batman ; 2
conversion: imagine ; 1
copy assignment: imagine ; 2
print const Word&: batman ; 1

*** Move Semantics ***
conversion: outliers ; 1

copy: outliers ; 2
move: OUTLIERS ; 2
destructor: null ; 0

outliers ; 1
OUTLIERS ; 2

conversion: Beatles ; 1

conversion: Eagles ; 1
move assignment: Eagles ; 1
destructor: null ; 0

*** It's all destructions now ***
destructor: Eagles ; 1
destructor: OUTLIERS ; 2
destructor: outliers ; 1
destructor: imagine ; 1
destructor: imagine ; 2
destructor: batman ; 1
*/

/*
Output: (with the 'no-elide-constructors' flag)
*** Copy Semantics ***
conversion: batman ; 1
copy: batman ; 2
conversion: imagine ; 1
copy assignment: imagine ; 2
print const Word&: batman ; 1

*** Move Semantics ***
conversion: outliers ; 1

copy: outliers ; 2
move: OUTLIERS ; 2
destructor: null ; 0
move: OUTLIERS ; 2
destructor: null ; 0

outliers ; 1
OUTLIERS ; 2

conversion: Beatles ; 1
move: Beatles ; 1
destructor: null ; 0

conversion: Eagles ; 1
move assignment: Eagles ; 1
destructor: null ; 0

*** It's all destructions now ***
destructor: Eagles ; 1
destructor: OUTLIERS ; 2
destructor: outliers ; 1
destructor: imagine ; 1
destructor: imagine ; 2
destructor: batman ; 1
*/
