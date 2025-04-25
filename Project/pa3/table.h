#ifndef TABLE_H
#define TABLE_H

#include "hashtable.h"
#include "entry.h"
#include "bst.h"

#include <iomanip>

class Table {

    private:
        // The HashTable stores all the entries in this Table
        HashTable<Entry*> entries;

        // A mapping of field names to their default values
        // This defines all the fields in this Table and their default values
        BST<string, BaseField*> default_fields;
        
        // A mapping of field names to the corresponding index tree
        // Each BaseBST* is actually BST<K, HashTable<Entry*>>*, where K is the type of the field of the field name
        BST<string, BaseBST*> index_trees;

        // Class for filtering the table
        template <typename T>
        struct Filter {
            const Table* table;
            string field_name;
            
            // TODO: Implementation the operator== of Table::Filter
            Table operator==(const T& value) const;
        };

    public:

        Table() = default;

        // TODO: Implement the copy constructor in table.tpp
        Table(const Table& other);

        // TODO: Implement the destructor in table.tpp
        ~Table();

        // TODO: Implement the operator= in table.tpp
        Table& operator=(const Table& other);

        // TODO: Implement the addPrimitiveColumn function in table.tpp
        template <typename T>
        void addPrimitiveColumn(string name, const T& default_value);

        // TODO: Implement the addListColumn function in table.tpp
        template <typename T>
        void addListColumn(string name, const vector<T>& default_vec);
        
        // TODO: Implement the addEntry function in table.tpp
        void addEntry(const Entry& entry);

        friend ostream& operator<<(ostream& os, const Table& table) {
            table.print(os);
            return os;
        }

        // Returns a Filter object for the given field name
        template <typename T>
        Filter<T> filter(string name) const {
            Filter<T> filter = {this, name};
            return filter;
        }

    private:

         // Print function for the Table
        void print(ostream& os) const {

            if (entries.size() == 0) {
                os << "Table is empty.";
                return;
            }

            vector<Entry*> vec = entries.to_vector();

            // Test if "pa3_id" exist, if yes then sort it to unify grading output
            BaseField** pa3_id_ptr = default_fields.get("pa3_id");
            if (pa3_id_ptr && dynamic_cast<PrimitiveField<int>*>(*pa3_id_ptr)) {
                [](vector<Entry*>& vec) {
                    for (size_t i = 0; i < vec.size(); ++i) {
                        for (size_t j = 0; j < vec.size() - i - 1; ++j) {
                            if (dynamic_cast<PrimitiveField<int>*>(*vec[j]->getFields().get("pa3_id"))->getValue()
                            > dynamic_cast<PrimitiveField<int>*>(*vec[j + 1]->getFields().get("pa3_id"))->getValue()) {
                                swap(vec[j], vec[j + 1]);
                            }
                        }
                    }
                }(vec);
            }
            
            for (vector<Entry*>::iterator it = vec.begin(); it != vec.end(); ++it) {
                os << "{";
                if (default_fields.size() > 0) {
                    os << endl;
                }
                BST<string, BaseField*> fields = (*it)->getFields();
                vector<BaseField*> vec2 = default_fields.getInorder();
                for (vector<BaseField*>::iterator it2 = vec2.begin(); it2 != vec2.end(); ++it2) {
                    string cur_name = (*it2)->getName();
                    BaseField** field_ptr = fields.get(cur_name);
                    if (field_ptr) {
                        os << "\t" << cur_name << ": " << **field_ptr << endl;
                    } else {
                        os << "\t" << cur_name << ": " << **it2 << endl;
                    }
                }
                os << "}";
                if (it + 1 != vec.end()) {
                    os << "," << endl;
                }
            }
        }

};

#include "table.tpp"

#endif