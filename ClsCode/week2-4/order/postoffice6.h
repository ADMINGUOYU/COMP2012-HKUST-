class Clock             /* File: postoffice6.h */
{
  private:
    int HHMM;
  public:
    Clock() : HHMM(0) { cout << "Clock Constructor\n"; }
    Clock(int hhmm) : HHMM(hhmm)
        { cout << "Clock Constructor at " << HHMM << endl; }
    ~Clock() { cout << "Clock Destructor at "  << HHMM << endl; }
};

class Postoffice
{
  private:
    Clock clock;
  public:
    Postoffice()
        { cout << "Postoffice Constructor\n"; clock = Clock(800); }
    ~Postoffice() { cout << "Postoffice Destructor\n"; }
};

/*
RESULTS: (copied from lecture notes)

Beginning of main
Clock Constructor
Postoffice Constructor
Clock Constructor at 800  |
Clock Destructor at 800   |-> this is a temp object created by 'Clock(800)'
End of main
Postoffice Destructor
Clock Destructor at 800
*/