class X { int a; };
class Y { int a; };
class W { int a; };
class W { int b; };  // Error, double definition

X x; 
Y y;

x = y;  // Error: type mismatch
/*
this declaration has no storage class or type specifierC/C++(77)
<error type> x
Error: type mismatch
*/

