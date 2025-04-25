#ifndef BASEFIELD_H
#define BASEFIELD_H

#include <string>
#include <vector>
#include "bst.h"
#include "hashtable.h"

using namespace std;

class Entry;

// The base class of any fields
class BaseField {
    private:
        virtual ostream& printValue(ostream& os) const = 0;
        
    protected:
        string name;    // Name of the field
    
    public:
        BaseField(string name) : name(name) {}

        virtual ~BaseField() {}

        virtual BaseField* clone() const = 0;

        virtual void handleAddEntryToIndexTree(BaseBST* index_tree, Entry* entry) const = 0;

        string getName() const {
            return name;
        }

        friend ostream& operator<<(ostream& os, const BaseField& field) {
            return field.printValue(os);
        }
};

template <typename T>
class PrimitiveField : public BaseField {
    private:
        T value;

        ostream& printValue(ostream& os) const override {
            os << value;
            return os;
        }

    public:
        PrimitiveField(string name, T val) : BaseField(name), value(val) {}

        void setValue(const T& val) {
            value = val;
        }

        T getValue() const {
            return value;
        }

        BaseField* clone() const override {
            return new PrimitiveField<T>(*this);
        }

        // TODO: Implement the function in basefield.tpp
        void handleAddEntryToIndexTree(BaseBST* index_tree, Entry* entry) const override;
};

// Template specialization for string output
template <>
ostream& PrimitiveField<string>::printValue(ostream& os) const {
    os << "\"" << value << "\"";
    return os;
}

template <typename T>
class ListField : public BaseField {
    private:
        vector<T> values;

        ostream& printValue(ostream& os) const override {
            os << "[";
            for (typename vector<T>::const_iterator it = values.begin(); it != values.end(); ++it) {
                os << *it;
                if (it + 1 != values.end()) {
                    os << ", ";
                }
            }
            os << "]";
            return os;
        }

    public:
        ListField(string name, const vector<T>& values) : BaseField(name), values(values) {}

        void addItem(const T& item) {
            values.push_back(item);
        }

        BaseField* clone() const override {
            return new ListField<T>(*this);
        }

        // TODO: Implement the function in basefield.tpp
        void handleAddEntryToIndexTree(BaseBST* index_tree, Entry* entry) const override;

};

// Template specialization for string output
template <>
ostream& ListField<string>::printValue(ostream& os) const {
    os << "[";
    for (typename vector<string>::const_iterator it = values.begin(); it != values.end(); ++it) {
        os << "\"" << *it << "\"";
        if (it + 1 != values.end()) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

#include "basefield.tpp"

#endif