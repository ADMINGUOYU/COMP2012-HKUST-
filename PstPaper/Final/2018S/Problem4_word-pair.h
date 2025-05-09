/* File: word-pair.h */
#include <cstring>
#include <iostream>
using namespace std;

class Word
{
private:
    int length = 0;
    char *str = nullptr;

public:
    Word(const char *s) : length(strlen(s)), str(new char[length + 1])
    {
        strcpy(str, s);
        cout << "convert: ";
        print();
    }
    Word(const Word &w) : length(w.length), str(new char[length + 1])
    {
        strcpy(str, w.str);
        cout << "copy: ";
        print();
    }
    Word(Word &&w) : length(w.length), str(w.str)
    {
        w.length = 0;
        w.str = nullptr;
        cout << "move: ";
        print();
    }
    ~Word()
    {
        cout << "~Word: ";
        print();
        delete[] str;
    }
    void print() const
    {
        cout << (str ? str : "null") << " ; " << length << endl;
    }
};
class Word_Pair
{
private:
    Word w1;
    Word w2;

public:
    Word_Pair(const Word_Pair &) = default;
    Word_Pair(Word_Pair &&wp) : w1(std::move(wp.w1)), w2(std::move(wp.w2)) {}
    Word_Pair(const Word &a, const Word &b) : w1(a), w2(b)
    {
        cout << "Call WP1" << endl;
    }
    Word_Pair(Word &&a, Word &&b) : w1(a), w2(b)
    {
        cout << "Call WP2" << endl;
    }
};