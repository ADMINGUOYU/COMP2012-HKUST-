#include "table.h"
#include "bst.h"
#include "hashtable.h"
#include "basefield.h"

#include <iostream>

using namespace std;

const string IDX = "Test Case ";
const string NAME = ": ";
const string LINE = "--------------------------------------------------";

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    os << "[";
    for (typename vector<T>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        os << *it;
        if (it + 1 != vec.end()) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

int main() {

    int caseID;
    cin >> caseID;

    if (caseID == 1) {
        string name = "Part I - Testing getInorder of BST";
        cout << IDX << caseID << NAME << name << endl
             << LINE << endl;
        
        BST<int, string> bst;
        bst.insert(5, "Five Guys");
        bst.insert(3, "Three Mobile");
        bst.insert(7, "Seven Eleven");
        bst.insert(2, "Two!!!");
    
        cout << "Inorder of BST: " << bst.getInorder() << endl;
    
    } else if (caseID == 2) {
        string name = "Part I - Testing getInorderWithUpperBound of BST";
        cout << IDX << caseID << NAME << name << endl
             << LINE << endl;
        
        BST<int, string> bst;
        bst.insert(5, "Five Guys");
        bst.insert(3, "Three Mobile");
        bst.insert(7, "Seven Eleven");
        bst.insert(2, "Two!!!");
    
        cout << "Inorder of BST: " << bst.getInorderWithUpperBound(6) << endl;
    
    } else if (caseID == 3) {
        string name = "Part I - Testing getInorderWithLowerBound of BST";
        cout << IDX << caseID << NAME << name << endl
             << LINE << endl;
        
        BST<int, string> bst;
        bst.insert(5, "Five Guys");
        bst.insert(3, "Three Mobile");
        bst.insert(7, "Seven Eleven");
        bst.insert(2, "Two!!!");
    
        cout << "Inorder of BST: " << bst.getInorderWithLowerBound(-1) << endl;
    
    } else if (caseID == 4) {
        string name = "Part I - Testing getInorderWithLowerBound of BST";
        cout << IDX << caseID << NAME << name << endl
             << LINE << endl;
        
        BST<int, string> bst;
        bst.insert(5, "MyGo!!!!!");
        bst.insert(3, "Three Mobile");
        bst.insert(7, "Seven Eleven");
        bst.insert(2, "Sumimi");
    
        cout << "Inorder of BST: " << bst.getInorderWithLowerBound(-1) << endl;
    
    } else if (caseID == 5) {
        string name = "Part II - Testing constructor of HashTable";
        cout << IDX << caseID << NAME << name << endl
             << LINE << endl;
        
        HashTable<string> ht(1, 0.5);
    
        cout << "Size of HashTable: " << ht.size() << endl;
    
    } else if (caseID == 6) {
        string name = "Part II - Testing insert of BST";
        cout << IDX << caseID << NAME << name << endl
             << LINE << endl;
        
        HashTable<string> ht(1, 0.5);
        ht.insert("Sumimi");
        ht.insert("Three Mobile");
        ht.insert("Seven Eleven");
        ht.insert("MyGo!!!!!");
    
        cout << "Can insert the same element: " << boolalpha << ht.insert("MyGo!!!!!") << endl;
    
    } else if (caseID == 7) {
        string name = "Part II - Testing exists of BST";
        cout << IDX << caseID << NAME << name << endl
             << LINE << endl;
        
        HashTable<string> ht(1, 0.5);
        ht.insert("Sumimi");
        ht.insert("Three Mobile");
        ht.insert("Seven Eleven");
        ht.insert("MyGo!!!!!");
    
        cout << "\"MyGo!!!!!\" exists in the HashTable: " << boolalpha << ht.exists("MyGo!!!!!") << endl;
    
    } else if (caseID == 8) {
        string name = "Part II - Testing remove of BST";
        cout << IDX << caseID << NAME << name << endl
             << LINE << endl;
        
        HashTable<string> ht(1, 0.5);
        ht.insert("Sumimi");
        ht.insert("Three Mobile");
        ht.insert("Seven Eleven");
        ht.insert("MyGo!!!!!");

        ht.remove("Sumimi");
    
        cout << "\"Sumimi\" exists in the HashTable after removal: " << boolalpha << ht.exists("Sumimi") << endl;
    
    } else if (caseID == 9) {
        string name = "Part II - Testing to_vector of BST";
        cout << IDX << caseID << NAME << name << endl
             << LINE << endl;
        
        HashTable<string> ht(1, 0.5);
        ht.insert("Sumimi");
        ht.insert("Three Mobile");
        ht.insert("Seven Eleven");
        ht.insert("MyGo!!!!!");

        vector<string> vec = ht.to_vector();

        // Sort the vector in lambda
        [](vector<string>& vec) {
            for (size_t i = 0; i < vec.size(); ++i) {
                for (size_t j = 0; j < vec.size() - i - 1; ++j) {
                    if (vec[j] > vec[j + 1]) {
                        swap(vec[j], vec[j + 1]);
                    }
                }
            }
        }(vec);
    
        cout << "Contents of the HashTable: " << vec << endl;
    
    } else if (caseID == 10) {

        string name = "Part III - Testing handleAddEntryToIndexTree of PrimitiveField";
        cout << IDX << caseID << NAME << name << endl
             << LINE << endl;
            
        Entry entry;
        entry.setPrimitiveField<string>("name", "COMP2012");
        BaseField* nameField = *entry.getFields().get("name");

        HashTable<Entry*> ht;
        ht.insert(&entry);

        BST<string, HashTable<Entry*>> index_tree;
        nameField->handleAddEntryToIndexTree(&index_tree, &entry);
        
        cout << "Size of index tree: " << index_tree.size() << endl;
        cout << endl;

        HashTable<Entry*>* hashTableinIndex = index_tree.get("COMP2012");
        cout << "COMP2012 gets added to index tree: " << boolalpha << (hashTableinIndex != nullptr) << endl;
        if (hashTableinIndex != nullptr) {
            cout << "Size of the HashTable under the key COMP2012: " << hashTableinIndex->size() << endl;
        }

    } else if (caseID == 11) {

        string name = "Part III - Testing handleAddEntryToIndexTree of ListField";
        cout << IDX << caseID << NAME << name << endl
             << LINE << endl;
            
        Entry entry;
        entry.addItemToListField<string>("tags", "Saki").addItemToListField<string>("tags", "Haruhikage");
        BaseField* nameField = *entry.getFields().get("tags");

        HashTable<Entry*> ht;
        ht.insert(&entry);

        BST<string, HashTable<Entry*>> index_tree;
        nameField->handleAddEntryToIndexTree(&index_tree, &entry);
        
        cout << "Size of index tree: " << index_tree.size() << endl;
        cout << endl;

        HashTable<Entry*>* hashTableinIndex = index_tree.get("Saki");
        cout << "Saki gets added to index tree: " << boolalpha << (hashTableinIndex != nullptr) << endl;
        if (hashTableinIndex != nullptr) {
            cout << "Size of the HashTable under the key Saki: " << hashTableinIndex->size() << endl;
        }

        cout << endl;

        hashTableinIndex = index_tree.get("Haruhikage");
        cout << "Haruhikage gets added to index tree: " << boolalpha << (hashTableinIndex != nullptr) << endl;
        if (hashTableinIndex != nullptr) {
            cout << "Size of the HashTable under the key Haruhikage: " << hashTableinIndex->size() << endl;
        }

    } else if (caseID == 12) {

        string name = "Part III - Testing constructor of Table";
        cout << IDX << caseID << NAME << name << endl
             << LINE << endl;
        
        Table table;
        cout << table << endl;

    } else if (caseID == 13) {

        string name = "Part III - Testing addPrimitiveColumn of Table";
        cout << IDX << caseID << NAME << name << endl
             << LINE << endl;
        
        Table table;
        table.addPrimitiveColumn<string>("name", "No Name");
        table.addEntry(Entry());

        cout << table << endl;

    } else if (caseID == 14) {

        string name = "Part III - Testing addListColumn of Table";
        cout << IDX << caseID << NAME << name << endl
             << LINE << endl;
        
        Table table;
        table.addListColumn<string>("tags", {"UwU", "=w="});
        table.addEntry(Entry());

        cout << table << endl;

    } else if (caseID == 15) {

        string name = "Part III - Testing addEntry of Table";
        cout << IDX << caseID << NAME << name << endl
             << LINE << endl;
        
        Table table;
        table.addListColumn<string>("tags", {});
        table.addPrimitiveColumn<string>("time", "No time");
        table.addPrimitiveColumn<int>("pa3_id", -1);
        table.addEntry(Entry().addItemToListField<string>("tags", "UwU").setPrimitiveField<string>("time", "2023-10-01").setPrimitiveField<int>("pa3_id", 1));
        table.addEntry(Entry().addItemToListField<string>("tags", "=w=").addItemToListField<string>("tags", "UwU").setPrimitiveField<int>("pa3_id", 2));

        cout << table << endl;

    } else if (caseID == 16) {

        string name = "Part III - Testing copy constructor of Table";
        cout << IDX << caseID << NAME << name << endl
             << LINE << endl;
        
        Table table;
        table.addListColumn<string>("tags", {});
        table.addPrimitiveColumn<string>("time", "No time");
        table.addPrimitiveColumn<int>("pa3_id", -1);
        table.addEntry(Entry().addItemToListField<string>("tags", "UwU").setPrimitiveField<string>("time", "2023-10-01").setPrimitiveField<int>("pa3_id", 1));
        table.addEntry(Entry().addItemToListField<string>("tags", "=w=").addItemToListField<string>("tags", "UwU").setPrimitiveField<int>("pa3_id", 2));

        Table newTable(table);

        cout << newTable << endl;

    } else if (caseID == 17) {

        string name = "Part III - Testing operator= of Table";
        cout << IDX << caseID << NAME << name << endl
             << LINE << endl;
        
        Table table;
        table.addListColumn<string>("tags", {});
        table.addPrimitiveColumn<string>("time", "No time");
        table.addPrimitiveColumn<int>("pa3_id", -1);
        table.addEntry(Entry().addItemToListField<string>("tags", "UwU").setPrimitiveField<string>("time", "2023-10-01").setPrimitiveField<int>("pa3_id", 1));
        table.addEntry(Entry().addItemToListField<string>("tags", "=w=").addItemToListField<string>("tags", "UwU").setPrimitiveField<int>("pa3_id", 2));

        Table newTable;
        newTable = table;

        cout << newTable << endl;

    } else if (caseID == 18) {

        string name = "Part III - Testing operator== of Table::Filter";
        cout << IDX << caseID << NAME << name << endl
             << LINE << endl;
        
        Table table;
        table.addListColumn<string>("tags", {});
        table.addPrimitiveColumn<string>("time", "No time");
        table.addPrimitiveColumn<int>("pa3_id", -1);
        table.addEntry(Entry().addItemToListField<string>("tags", "UwU").setPrimitiveField<string>("time", "2023-10-01").setPrimitiveField<int>("pa3_id", 1));
        table.addEntry(Entry().addItemToListField<string>("tags", "=w=").addItemToListField<string>("tags", "UwU").setPrimitiveField<int>("pa3_id", 2));

        cout << (table.filter<string>("tags") == "=w=") << endl;

    } else {

        cout << "Invalid test case ID." << endl;

    }

    
}