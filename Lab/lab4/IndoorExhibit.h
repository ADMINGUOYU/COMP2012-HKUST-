#ifndef INDOOR_EXHIBIT_H
#define INDOOR_EXHIBIT_H
#include "Exhibit.h"

class IndoorExhibit: public Exhibit {
    private:
        string climate_type;
    
    public:
        IndoorExhibit(const string& name, int area_code, const string& climate_type);
        string get_climate_type() const;
        void print_info() const;
};

#endif