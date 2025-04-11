#include "Item.h"
// ================== CLASS TEMPLATE DEFINITIONS ==================

template <typename T>
Item<T>::Item(const string& name, T value, T weight)
    : name(name), value(value), weight(weight)
{ }


// ================== SAME-TYPE OPERATORS ==================

// Task 1.1: Implement operator+ (Item<T> + Item<T>) => Item<T>
/*
Combine the value and weight of both objects into a new item.
Notice: Maintain the name from the left-hand side item 
(e.g., the name of the returned Item is Sword of Flames when doing Sword of Flames + Shield of Thunder).
*/
template <typename T>
Item<T> Item<T>::operator+(const Item<T>& other) const {
    // TODO: Task 1.1
    // Notice: For the returned Item<T>, Keep the same name as this->name.
    return Item<T> { this->name, this->value + other.value, this->weight + other.weight };
}

// Task 1.2: Implement operator* (Item<T> * T) => Item<T>
/*
Multiply the item’s value and weight by scalar.
*/
template <typename T>
Item<T> Item<T>::operator*(const T &scalar) const {
    // TODO: Task 1.2
    // Notice: For the returned Item<T>, Keep the same name as this->name.
    return Item<T> { this->name, this->value * scalar, this->weight * scalar };
}

// Task 2: Implement operator==
/*
Return true if items match in value, weight and name.
*/
template <typename T>
bool Item<T>::operator==(const Item<T>& other) const {
    // TODO: Task 2
    return (
        (this->name == other.name)
        &&
        (this->value == other.value)
        &&
        (this->weight == other.weight)
        );
}

// Task 3: Implement operator<
/*
Compare items based on value.
*/
template <typename T>
bool Item<T>::operator<(const Item<T>& other) const {
    // TODO: Task 3
    return (this->value < other.value);
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
    return Item<double> { lhs.name, lhs.value + rhs.value, lhs.weight + rhs.weight };
}
// Task 4.1: Implement operator* (Item<T1> * T2) => Item<double>
template <typename T1, typename T2>
Item<double> operator*(const Item<T1>& item, const T2& scalar) {
    // TODO: Task 4.2
    return Item<double> { item.name, item.value * scalar, item.weight * scalar };
}
