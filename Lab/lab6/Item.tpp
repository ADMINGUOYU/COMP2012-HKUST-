#include "Item.h"
// ================== CLASS TEMPLATE DEFINITIONS ==================

template <typename T>
Item<T>::Item(const string& name, T value, T weight)
    : name(name), value(value), weight(weight)
{
}


// ================== SAME-TYPE OPERATORS ==================

// Task 1.1: Implement operator+ (Item<T> + Item<T>) => Item<T>
template <typename T>
Item<T> Item<T>::operator+(const Item<T>& other) const {
    // TODO: Task 1.1
    // Notice: For the returned Item<T>, Keep the same name as this->name.
}

// Task 1.2: Implement operator* (Item<T> * T) => Item<T>
template <typename T>
Item<T> Item<T>::operator*(const T &scalar) const {
    // TODO: Task 1.2
    // Notice: For the returned Item<T>, Keep the same name as this->name.
}

// Task 2: Implement operator==
template <typename T>
bool Item<T>::operator==(const Item<T>& other) const {
    // TODO: Task 2
}

// Task 3: Implement operator<
template <typename T>
bool Item<T>::operator<(const Item<T>& other) const {
    // TODO: Task 3
}

template <typename U>
ostream& operator<<(ostream& os, const Item<U>& i) {
    os << i.name << " (Value: " << i.value 
       << ", Weight: " << i.weight << ")";
    return os;
}

// --------------------------------------------------------------------
// CROSS-TYPE FREE FUNCTIONS (Always returning Item<double>)
// --------------------------------------------------------------------
// Task 4.1: Implement operator+ (Item<T1> + Item<T2>) => Item<double>
template <typename T1, typename T2>
Item<double> operator+(const Item<T1>& lhs, const Item<T2>& rhs) {
    // TODO: Task 4.1
    // Notice: For the returned Item<T>, Keep the same name as lhs->name.
}
// Task 4.1: Implement operator* (Item<T1> * T2) => Item<double>
template <typename T1, typename T2>
Item<double> operator*(const Item<T1>& item, const T2& scalar) {
    // TODO: Task 4.2
}
