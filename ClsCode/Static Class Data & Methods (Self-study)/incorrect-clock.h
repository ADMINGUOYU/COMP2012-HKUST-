class Clock {           /* File: incorrect-clock.h */
  public:
    Clock() : hour(0), minute(0) { }
    Clock(int mins) : hour(mins/60), minute(mins%60) { }
    Clock(int hhmm) : hour(hhmm/100), minute(hhmm%100) { }
    void tick();
  private:
    int hour, minute;
};

Clock c1;        // 0:00
Clock c2(120);   // 1:20
Clock c3(180);   // 3:00
