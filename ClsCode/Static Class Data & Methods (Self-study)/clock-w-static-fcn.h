class Clock             /* File: clock-w-static-fcn.h */
{
    friend ostream& operator<<(ostream& os, const Clock& c)
      { return os << c.hour << " hr. " << c.minute << " min. "; }

  public:
    Clock() : hour(0), minute(0) { }

    static Clock HHMM(int hhmm)
        { return Clock(hhmm/100, hhmm%100); }

    static Clock minutes(int m) 
        { return Clock(m/60, m%60); }

  private:
    int hour, minute;
    Clock(int h, int m) : hour(h), minute(m) { }
};
