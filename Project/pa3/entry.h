#ifndef ENTRY_H
#define ENTRY_H

#include "basefield.h"
#include "bst.h"
#include <vector>
#include <iomanip>

using namespace std;

class Entry {

    private:
        // A mapping of the field name to the field
        BST<string, BaseField*> fields;
    
    public:
        // Default constructor
        Entry() = default;

        // Copy constructor
        Entry(const Entry& other) {
            vector<BaseField*> vec = other.fields.getInorder();
            for (vector<BaseField*>::iterator it = vec.begin(); it != vec.end(); ++it) {
                fields.insert((*it)->getName(), (*it)->clone());
            }
        }

        // Destructor
        ~Entry() {
            vector<BaseField*> vec = fields.getInorder();
            for (vector<BaseField*>::iterator it = vec.begin(); it != vec.end(); ++it) {
                delete *it;
            }
        }

        // Accessor of `fields`
        BST<string, BaseField*> getFields() const {
            return fields;
        }

        // Set the primative field of this entry to a value
        // Returns the current entry for further manipulation
        template <typename T>
        Entry& setPrimitiveField(string key, const T& value) {
            BaseField** field_ptr = fields.get(key);
            if (field_ptr) {
                BaseField* field = *field_ptr;
                PrimitiveField<T>* primitiveField = dynamic_cast<PrimitiveField<T>*>(field);
                if (primitiveField) {
                    primitiveField->setValue(value);
                }
            } else {
                fields.insert(key, new PrimitiveField<T>(key, value));
            }
            return *this;
        }
        
        // Add a given value to the list field of this entry
        // Returns the current entry for further manipulation
        template <typename T>
        Entry& addItemToListField(string key, const T& value) {
            BaseField** field_ptr = fields.get(key);
            if (field_ptr) {
                BaseField* field = *field_ptr;
                ListField<T>* listField = dynamic_cast<ListField<T>*>(field);
                if (listField) {
                    listField->addItem(value);
                }
            } else {
                ListField<T>* listField = new ListField<T>(key, {value});
                fields.insert(key, listField);
            }
            return *this;
        }

};

#endif