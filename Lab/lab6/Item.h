#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;

// A class template for a game item, parameterized by numeric type T.
template <typename T>
class Item {
private:
    std::string name;
    T value;
    T weight;

public:
    // Constructor
    Item(const std::string& name = "Unknown", T value = T(0), T weight = T(0));

    // SAME-TYPE operator+ (Item<T> + Item<T>) => Item<T>
    Item<T> operator+(const Item<T>& other) const;

    // SAME-TYPE operator* (Item<T> * T) => Item<T>
    Item<T> operator*(const T& scalar) const;

    // Comparison operators
    bool operator==(const Item<T>& other) const;
    bool operator<(const Item<T>& other) const;

    // Output operator
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Item<U>& i);

    template <typename T1, typename T2>
    friend Item<double> operator+(const Item<T1>& lhs, const Item<T2>& rhs);

    template <typename T1, typename T2>
    friend Item<double> operator*(const Item<T1>& item, const T2& scalar);
};

// --------------------------------------------------------------------
// CROSS-TYPE FREE FUNCTIONS (Always returning Item<double>)
// --------------------------------------------------------------------

template <typename T1, typename T2>
Item<double> operator+(const Item<T1>& lhs, const Item<T2>& rhs);

template <typename T1, typename T2>
Item<double> operator*(const Item<T1>& item, const T2& scalar);

#include "Item.tpp"

#endif