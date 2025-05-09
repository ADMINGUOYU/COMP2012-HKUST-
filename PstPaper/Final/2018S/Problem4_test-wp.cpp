/* File: "test-wp.cpp" */
#include <iostream>
using namespace std;
#include "Problem4_word-pair.h"

int main()
{
    cout << "(a) *** Print the const names' info ***" << endl;
    const Word first_name{"Isaac"};
    const Word last_name{"Newton"};
    Word_Pair name{first_name, last_name};
    cout << "\n(b) *** Print the opposites' info ***" << endl;
    Word_Pair synonym{Word("happy"), Word("sad")};
    cout << "\n(c) *** Print the book's info ***" << endl;
    Word author{"Orwell"};
    Word title{"1984"};
    Word_Pair book{Word_Pair(author, title)};
    cout << "\n(d) *** It's all destructions now ***" << endl;
    return 0;
}

/*
The following program consists of 2 files: word-pair.h and test-wp.cpp which are modified
from those similar files from our lecture notes. The program runs with no errors after it is
compiled with the following command:
    g++-std=c++11-fno-elide-constructors test-wp.cpp
Write down its output in the space provided. Some lines of outputs are already given.

OUTPUT:
(a) *** Print the const names' info ***
convert: Isaac ; 5
convert: Newton ; 6
copy: Isaac ; 5
copy: Newton ; 6
Call WP1

(b) *** Print the opposites' info ***
convert: happy ; 5
convert: sad ; 3
copy: happy ; 5
copy: sad ; 3
Call WP2
~Word: sad ; 3
~Word: happy ; 5

(c) *** Print the book's info ***
convert: Orwell ; 6
convert: 1984 ; 4
copy: Orwell ; 6
copy: 1984 ; 4
Call WP1
move: Orwell ; 6
move: 1984 ; 4
~Word: null ; 0
~Word: null ; 0

(d) *** It's all destructions now ***
~Word: 1984 ; 4             <- from (moved) word pair book
~Word: Orwell ; 6
~Word: 1984 ; 4             <- from title
~Word: Orwell ; 6           <- form author
~Word: sad ; 3              <- from word pair synonym
~Word: happy ; 5
~Word: Newton ; 6           <- from word pair name
~Word: Isaac ; 5
~Word: Newton ; 6           <- from last_name
~Word: Isaac ; 5            <- from first_name
*/

/*
Actual output:
(a) *** Print the const names' info ***
convert: Isaac ; 5
convert: Newton ; 6
copy: Isaac ; 5
copy: Newton ; 6
Call WP1

(b) *** Print the opposites' info ***
convert: happy ; 5
convert: sad ; 3
copy: happy ; 5
copy: sad ; 3
Call WP2
~Word: sad ; 3
~Word: happy ; 5

(c) *** Print the book's info ***
convert: Orwell ; 6
convert: 1984 ; 4
copy: Orwell ; 6
copy: 1984 ; 4
Call WP1
move: Orwell ; 6
move: 1984 ; 4
~Word: null ; 0
~Word: null ; 0

(d) *** It's all destructions now ***
~Word: 1984 ; 4
~Word: Orwell ; 6
~Word: 1984 ; 4
~Word: Orwell ; 6
~Word: sad ; 3
~Word: happy ; 5
~Word: Newton ; 6
~Word: Isaac ; 5
~Word: Newton ; 6
~Word: Isaac ; 5
*/