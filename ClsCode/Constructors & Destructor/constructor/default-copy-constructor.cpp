class Word  /* File: default-copy-constructor.cpp */
{
  private: /*...*/
  public: Word(const char* s, int k = 0) { /*...*/ }; 
};
int main()
{
    Word movie {"Titanic"};  // which constructor? -> conversion in line 4
    Word song {movie};       // which constructor? -> copy (given by default)
    Word song = movie;       // which constructor? -> copy (given by default)
    movie = song;            // NO constructor -> memberwise assignment -> operator=
}

// Default copy constructor -> perform shallow copy -> memberwise assignment