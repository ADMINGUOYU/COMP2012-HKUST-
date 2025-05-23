#include <iostream>
using namespace std;

template <typename T>
void f(T x, T y)
{
    cout << "Template" << endl;
}
void f(int x, int y)
{
    cout << "Non-template" << endl;
}
int main()
{
    f(1, 2);
    f('a', 'b');
    f(1, 'b');
    /*
    if void f(int x, int y) doesn't exist, there will be an error
    -> template will not perform automatic type conversion

    !!!
    template <>
    void f(int x, int y) { ... }
    Will NOT work
    !!!
    */
}

/*
.LC0:
        .string "Non-template"
f(int, int):
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     DWORD PTR [rbp-4], edi
        mov     DWORD PTR [rbp-8], esi
        mov     esi, OFFSET FLAT:.LC0
        mov     edi, OFFSET FLAT:std::cout
        call    std::basic_ostream<char, std::char_traits<char>>& std::operator<<<std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&, char const*)
        mov     esi, OFFSET FLAT:std::basic_ostream<char, std::char_traits<char>>& std::endl<char, std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&)
        mov     rdi, rax
        call    std::ostream::operator<<(std::ostream& (*)(std::ostream&))
        nop
        leave
        ret
main:
        push    rbp
        mov     rbp, rsp
        mov     esi, 2
        mov     edi, 1
        call    f(int, int)
        mov     esi, 98
        mov     edi, 97
        call    void f<char>(char, char)
        mov     esi, 98
        mov     edi, 1
        call    f(int, int)
        mov     eax, 0
        pop     rbp
        ret
.LC1:
        .string "Template"
void f<char>(char, char):
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     edx, edi
        mov     eax, esi
        mov     BYTE PTR [rbp-4], dl
        mov     BYTE PTR [rbp-8], al
        mov     esi, OFFSET FLAT:.LC1
        mov     edi, OFFSET FLAT:std::cout
        call    std::basic_ostream<char, std::char_traits<char>>& std::operator<<<std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&, char const*)
        mov     esi, OFFSET FLAT:std::basic_ostream<char, std::char_traits<char>>& std::endl<char, std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&)
        mov     rdi, rax
        call    std::ostream::operator<<(std::ostream& (*)(std::ostream&))
        nop
        leave
        ret
*/