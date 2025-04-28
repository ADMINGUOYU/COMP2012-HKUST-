/* TODO: Implement the functions for the subclasses of BaseField */
/* Write your code below */

/*
This helper function adds the given entry to the given index_tree of the current field, based on the field value of that entry.
You are allowed to use dynamic_cast in this task and you are allowed to use dynamic_cast in this task ONLY.

The type of the index_trees is BST<string, BaseBST*> (this is the trees, many not one)
each underlying BaseBST is a BST<K, HashTable<Entry*>> object (BaseBST* from above)

The following demonstrates the procedure when we want to insert an Entry to the Table:

    - An Entry object is created inside the main function.
    - The Entry object is passed to the Table.
    - The Table will add the Entry to its collection of entries.
    - The Table will add the entry to the corresponding index tree of all the fields in the Entry.

One may notice that problem arises in Step 4. When the Table wants to add the entry to the corresponding index tree of the field, it has to call the BST<K, HashTable<Entry*>>::insert(K key, HashTable<Entry*> value) function to insert the entry. However, the type K of the field is not known to the Table class, so it can't call the insert function directly.
Therefore, we can dedicate the index tree insertion to the BaseField class, since the field class itself knows the type of the field. The following is the function you need to implement in the subclasses of the BaseField class
*/
template <typename T>
void PrimitiveField<T>::handleAddEntryToIndexTree(BaseBST *index_tree, Entry *entry) const
{
    /*
    index_tree
    -> value_1      : entry_1, entry_3
    -> value_2      : entry_2
    -> value_3      : entry_4
    */

    // note that: fields.insert(key, new PrimitiveField<T>(key, value));
    // so they have the same key, I mean the name is used twice

    // dynamic cast the tree pointer
    BST<T, HashTable<Entry *>> *indexTree = dynamic_cast<BST<T, HashTable<Entry *>> *>(index_tree);

    // first check if the value exists in the tree
    HashTable<Entry *> *hashTable = indexTree->get(this->value);
    if (!hashTable)
    {
        // this is the first time the value appears
        // create a new tree leaf and a new HashTable
        indexTree->insert(this->value, {});
        hashTable = indexTree->get(this->value);
    }

    // now add this entry to the hash table
    hashTable->insert(entry);

    // done and return
    return;
}

template <typename T>
void ListField<T>::handleAddEntryToIndexTree(BaseBST *index_tree, Entry *entry) const
{
    // the difference is: you have to go through every element in the list

    // dynamic cast the tree pointer
    BST<T, HashTable<Entry *>> *indexTree = dynamic_cast<BST<T, HashTable<Entry *>> *>(index_tree);

    // first check if the value exists in the tree
    for (typename std::vector<T>::const_iterator itr = values.begin(); itr != values.end(); ++itr)
    {
        HashTable<Entry *> *hashTable = indexTree->get(*itr);
        if (!hashTable)
        {
            // this is the first time the value appears
            // create a new tree leaf and a new HashTable
            indexTree->insert(*itr, {});
            hashTable = indexTree->get(*itr);
        }

        // now add this entry to the hash table
        hashTable->insert(entry);
    }

    // done and return
    return;
}