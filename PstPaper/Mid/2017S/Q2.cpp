#include <iostream>
using namespace std;

class A
{
public:
    A() { cout << "A's constructor" << endl; }
    ~A() { cout << "A's destructor" << endl; }
};

class B
{
public:
    B() { cout << "B's constructor" << endl; }
    ~B() { cout << "B's destructor" << endl; }
private:
    A a;
};

class C
{
public:
    C() { cout << "C's constructor" << endl; }
    ~C() { cout << "C's destructor" << endl; }
};

class D : public C
{
public:
    D() { cout << "D's constructor" << endl;}
    ~D() { cout << "D's destructor" << endl;}
private:
    B* b[2];
};

class E : public D
{
public:
    E() { cout << "E's constructor" << endl;}
    ~E() { cout << "E's destructor" << endl;}
private:
    B b;
};

int main()
{
    E e;
    return 0;
}

/*
(1) -> OUTPUT:
C's constructor
D's constructor
A's constructor
B's constructor
E's constructor
E's destructor
B's destructor
A's destructor
D's destructor
C's destructor

E -> D -> C: init C -> init D -> B (in E) -> init A -> init B -> init E
destruction in a reversed order
!!! note that the pointer array (in D) is NOT actual OBJECT B, so the initialization is related to the pointer not object B.
*/

/*
(2) -> OUTPUT:
C's constructor
D's constructor
A's constructor
B's constructor
E's constructor
E's destructor
B's destructor
A's destructor
D's destructor
C's destructor
*/

/*
Assembly (x86-64 gcc trunk):
.LC0:
        .string "A's constructor"
A::A() [base object constructor]:
        pushq   %rbp
        movq    %rsp, %rbp
        subq    $16, %rsp
        movq    %rdi, -8(%rbp)
        movl    $.LC0, %esi
        movl    $_ZSt4cout, %edi
        call    std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)
        movl    $_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
        movq    %rax, %rdi
        call    std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))
        nop
        leave
        ret
.LC1:
        .string "A's destructor"
A::~A() [base object destructor]:
        pushq   %rbp
        movq    %rsp, %rbp
        subq    $16, %rsp
        movq    %rdi, -8(%rbp)
        movl    $.LC1, %esi
        movl    $_ZSt4cout, %edi
        call    std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)
        movl    $_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
        movq    %rax, %rdi
        call    std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))
        nop
        leave
        ret
.LC2:
        .string "B's constructor"
B::B() [base object constructor]:
        pushq   %rbp
        movq    %rsp, %rbp
        pushq   %rbx
        subq    $24, %rsp
        movq    %rdi, -24(%rbp)
        movq    -24(%rbp), %rax
        movq    %rax, %rdi
        call    A::A() [complete object constructor]
        movl    $.LC2, %esi
        movl    $_ZSt4cout, %edi
        call    std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)
        movl    $_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
        movq    %rax, %rdi
        call    std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))
        jmp     .L6
        movq    %rax, %rbx
        movq    -24(%rbp), %rax
        movq    %rax, %rdi
        call    A::~A() [complete object destructor]
        movq    %rbx, %rax
        movq    %rax, %rdi
        call    _Unwind_Resume
.L6:
        movq    -8(%rbp), %rbx
        leave
        ret
.LC3:
        .string "B's destructor"
B::~B() [base object destructor]:
        pushq   %rbp
        movq    %rsp, %rbp
        subq    $16, %rsp
        movq    %rdi, -8(%rbp)
        movl    $.LC3, %esi
        movl    $_ZSt4cout, %edi
        call    std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)
        movl    $_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
        movq    %rax, %rdi
        call    std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))
        movq    -8(%rbp), %rax
        movq    %rax, %rdi
        call    A::~A() [complete object destructor]
        nop
        leave
        ret
.LC4:
        .string "C's constructor"
C::C() [base object constructor]:
        pushq   %rbp
        movq    %rsp, %rbp
        subq    $16, %rsp
        movq    %rdi, -8(%rbp)
        movl    $.LC4, %esi
        movl    $_ZSt4cout, %edi
        call    std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)
        movl    $_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
        movq    %rax, %rdi
        call    std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))
        nop
        leave
        ret
.LC5:
        .string "C's destructor"
C::~C() [base object destructor]:
        pushq   %rbp
        movq    %rsp, %rbp
        subq    $16, %rsp
        movq    %rdi, -8(%rbp)
        movl    $.LC5, %esi
        movl    $_ZSt4cout, %edi
        call    std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)
        movl    $_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
        movq    %rax, %rdi
        call    std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))
        nop
        leave
        ret
.LC6:
        .string "D's constructor"
D::D() [base object constructor]:
        pushq   %rbp
        movq    %rsp, %rbp
        pushq   %rbx
        subq    $24, %rsp
        movq    %rdi, -24(%rbp)
        movq    -24(%rbp), %rax
        movq    %rax, %rdi
        call    C::C() [base object constructor]
        movl    $.LC6, %esi
        movl    $_ZSt4cout, %edi
        call    std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)
        movl    $_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
        movq    %rax, %rdi
        call    std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))
        jmp     .L13
        movq    %rax, %rbx
        movq    -24(%rbp), %rax
        movq    %rax, %rdi
        call    C::~C() [base object destructor]
        movq    %rbx, %rax
        movq    %rax, %rdi
        call    _Unwind_Resume
.L13:
        movq    -8(%rbp), %rbx
        leave
        ret
.LC7:
        .string "D's destructor"
D::~D() [base object destructor]:
        pushq   %rbp
        movq    %rsp, %rbp
        subq    $16, %rsp
        movq    %rdi, -8(%rbp)
        movl    $.LC7, %esi
        movl    $_ZSt4cout, %edi
        call    std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)
        movl    $_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
        movq    %rax, %rdi
        call    std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))
        movq    -8(%rbp), %rax
        movq    %rax, %rdi
        call    C::~C() [base object destructor]
        nop
        leave
        ret
.LC8:
        .string "E's constructor"
E::E() [base object constructor]:
        pushq   %rbp
        movq    %rsp, %rbp
        pushq   %rbx
        subq    $24, %rsp
        movq    %rdi, -24(%rbp)
        movq    -24(%rbp), %rax
        movq    %rax, %rdi
        call    D::D() [base object constructor]
        movq    -24(%rbp), %rax
        addq    $16, %rax
        movq    %rax, %rdi
        call    B::B() [complete object constructor]
        movl    $.LC8, %esi
        movl    $_ZSt4cout, %edi
        call    std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)
        movl    $_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
        movq    %rax, %rdi
        call    std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))
        jmp     .L20
        movq    %rax, %rbx
        movq    -24(%rbp), %rax
        addq    $16, %rax
        movq    %rax, %rdi
        call    B::~B() [complete object destructor]
        jmp     .L17
        movq    %rax, %rbx
.L17:
        movq    -24(%rbp), %rax
        movq    %rax, %rdi
        call    D::~D() [base object destructor]
        movq    %rbx, %rax
        movq    %rax, %rdi
        call    _Unwind_Resume
.L20:
        movq    -8(%rbp), %rbx
        leave
        ret
.LC9:
        .string "E's destructor"
E::~E() [base object destructor]:
        pushq   %rbp
        movq    %rsp, %rbp
        subq    $16, %rsp
        movq    %rdi, -8(%rbp)
        movl    $.LC9, %esi
        movl    $_ZSt4cout, %edi
        call    std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)
        movl    $_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
        movq    %rax, %rdi
        call    std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))
        movq    -8(%rbp), %rax
        addq    $16, %rax
        movq    %rax, %rdi
        call    B::~B() [complete object destructor]
        movq    -8(%rbp), %rax
        movq    %rax, %rdi
        call    D::~D() [base object destructor]
        nop
        leave
        ret
main:
        pushq   %rbp
        movq    %rsp, %rbp
        pushq   %rbx
        subq    $40, %rsp
        leaq    -48(%rbp), %rax
        movq    %rax, %rdi
        call    E::E() [complete object constructor]
        movl    $0, %ebx
        leaq    -48(%rbp), %rax
        movq    %rax, %rdi
        call    E::~E() [complete object destructor]
        movl    %ebx, %eax
        movq    -8(%rbp), %rbx
        leave
        ret
*/