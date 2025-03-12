#ifndef EXHIBIT_H
#define EXHIBIT_H
#include <string>


using namespace std;

class Exhibit {
    private:
        string name;
        int area_code;   
        string type;
    
        
    protected:
        void set_type(const string& t) { type = t; } 

    public:
        Exhibit(const string& name, int area_code); 
        
        string get_name() const;
        int get_area_code() const;   
        string get_type() const { return type; }  
     
};

#endif