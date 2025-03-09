class Complex           /* File: complex.h */
{
  private:
    // private data members
    float real; float imag;

  public:
    // this constructor is automatically inlined
    inline Complex(float r, float i) { this->real = r; this->imag = i; }
    // this print function is automatically inlined
    void print() const { cout << "(" << real << " , " << imag << ")" << endl; }

    Complex add1(const Complex& x)  // Return by value
    {
        real += x.real; imag += x.imag;
        // return the value -> object of THIS
        return (*this);
    }
    Complex* add2(const Complex& x) // Return by value using pointer
    {
        real += x.real; imag += x.imag;
        return this;
    }
    Complex& add3(const Complex& x) // Return by reference
    {
        real += x.real; imag += x.imag;
        // return THIS object itself
        return (*this);
    }
};
