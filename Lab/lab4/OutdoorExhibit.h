#ifndef OUTDOOR_EXHIBIT_H
#define OUTDOOR_EXHIBIT_H
#include "Exhibit.h"

class OutdoorExhibit: public Exhibit {
    private:
        double area;
    
    public:
        OutdoorExhibit(const string& name, int area_code, double area);
        double get_area() const;
        void print_info() const;
};

#endif