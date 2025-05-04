class Personal_Asset    /* File: personal-asset.h */
{
  public:
    Personal_Asset(const string& date) : purchase_date(date) { }
    void set_purchase_date(const string& d);
    virtual double compute_net_worth() const; // Current net worth
    virtual bool is_insurable() const;        // Can this asset be insured?
    // -> IntelliSense: Function definition for 'is_insurable' not found.C/C++

  private:
    string purchase_date;
};
