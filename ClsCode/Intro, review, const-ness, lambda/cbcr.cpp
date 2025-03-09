void cbr(int& x) { x += 10; }        // Fine

void cbcr(const int& x) { x += 10; } // Error!
// error: expression must be a modifiable lvalueC/C++(137)
// with const qualifer -> referenced variable cannot be modified
