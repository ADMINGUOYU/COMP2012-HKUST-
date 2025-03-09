class Clock             /* File: clock-w-global-fcn.cpp */
{
  public:
    Clock(int h = 0, int m = 0) : hour(h), minute(m) { }
    void tick();

  private:
    int hour, minute;
};

Clock make_clock_hhmm(int hhmm)
    { return Clock( hhmm/100, hhmm%100 ); }

Clock make_clock_minutes(int min)
    { return Clock( min/60, min%60 ); }
