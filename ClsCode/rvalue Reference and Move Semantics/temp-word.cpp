#include "word.h"       /* File: temp-word.cpp */
void print_word(const Word& w) { cout << "print const Word&: "; w.print(); }
void print_word(Word&& w) { cout << "print Word&&: "; w.print(); }

/*
Word const && w -> is allowed
But basically it does the same thing as -> Word const & w
-> both have the capability of taking temporary objects
-> and both do not have to capability to modify the object

* if Word const && w is used -> it WILL be a better match than Word const & w
*/

/*
temporary object match: (sequence)
&& -> const && -> const &
*/

int main()
{
    /* Use const Word& to hold a temporary Word object */
    Word song("imagine");
    const Word& w1 = song.to_upper_case(); cout << endl;
    song.print(); w1.print(); cout << "\n**********" << endl;

    /* Use Word&& to hold a temporary Word object */
    Word movie("batman", 2);
    Word&& w2 = movie.to_upper_case(); cout << endl;
    movie.print(); w2.print(); cout << endl;

    print_word(song); print_word(movie);
    print_word(w1); print_word(w2); 
    
    /* Directly pass a temporary Word object to a function */
    print_word(movie.to_upper_case()); cout << endl;
    print_word("Beatles"); cout << "\n**********" << endl; return 0;
} /* g++ -std=c++11 -fno-elide-constructors temp-word.cpp */
