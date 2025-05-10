/* TODO: Implement the functions for the class Table and Table::Filter */
/* Write your code below */

/*
This adds a primitive column of type T to the Table.
If there are already entries exist in the Table, you should add the default value as the field to all the existing entries in the table.
Remember to set and update the data members correctly.
*/
template <typename T>
void Table::addPrimitiveColumn(string name, const T& default_value)
{
    /* legacy code - no longer need to do such thing
    // first we get every entry ('s address)
    std::vector<Entry*> const & all_entries = this->entries.to_vector();

    // iterate through all the entries and all that field (column)
    // note that, if there is no entry, this for loop criterion is not met
    // also update the index tree
    BST<T, HashTable<Entry*>> * index_tree = new BST<T, HashTable<Entry*>> { };
    for (typename std::vector<Entry*>::const_iterator itr = all_entries.begin(); itr != all_entries.end(); ++itr)
    {
        // set the field
        (*itr).setPrimitiveField(name, default_value);
        // get the field and handle adding to the index tree
        (*itr).getFields().get(name)->handleAddEntryToIndexTree(index_tree, itr);
    }

    // add a new index_tree to index_trees
    this->index_trees.insert(name, index_tree)

    */ // <- forget about that for now

    // add a new index_tree to index_trees
    this->index_trees.insert(name, new BST<T, HashTable<Entry*>> { });

    // save the default field to the data member
    this->default_fields.insert(name, new PrimitiveField<T> {name, default_value});

    // all done and a new column is added
    // return
    return;
}

/*
This adds a list column of type T to the Table.
If there are already entries exist in the Table, you should add the default value as the field to all the existing entries in the table.
Remember to set and update the data members correctly.
*/
template <typename T>
void Table::addListColumn(string name, const vector<T>& default_value)
{
    /* legacy code - no longer need to do such thing
    // first we get every entry ('s address)
    std::vector<Entry*> const & all_entries = this->entries.to_vector();

    // iterate through all the entries and all that field (column)
    // note that, if there is no entry, this for loop criterion is not met
    // also update the index tree
    BST<T, HashTable<Entry*>> index_tree = new BST<T, HashTable<Entry*>> { };
    for (typename std::vector<T>::const_iterator itr = all_entries.begin(); itr != all_entries.end(); ++itr)
    {
        // we have to add the items one-by-one
        for (T const & value : default_value)
            (*itr).addItemToListField(name, value);

        // get the field and handle adding to the index tree
        (*itr).getFields().get(name)->handleAddEntryToIndexTree(index_tree, itr);
    }

    // add a new index_tree to index_trees
    this->index_trees.insert(name, index_tree)
    */

    // add a new index_tree to index_trees
    this->index_trees.insert(name, new BST<T, HashTable<Entry*>> { });

    // save the default field to the data member
    this->default_fields.insert(name, new ListField<T> {name, default_value});

    // all done and a new column is added
    // return
    return;
}

/*
This adds an entry to the Table.
Think of how you should add the Entry to the Table. For example, can you get the Entry* by doing &entry directly?
You may assume that every field that exists in the entry must be valid in the current Table (i.e. the column exists in the Table).
It's possible that a field (the column) defined in the current Table doesn't exist in the given entry. In that case, use the corresponding default value as the value of that field for the entry.
Remember to set and update the data members correctly.
*/
void Table::addEntry(const Entry& entry)
{
    // copy the entry to entires (actually create a new one)
    Entry* new_entry = new Entry {entry};
    // don't need to duplicate the fields as Entry has already done for us
    this->entries.insert(new_entry);

    // maybe we need to re-hash
    // get every field (note that this is a copy)
    // parse every field
    for (BaseField* const & field : this->default_fields.getInorder())
    {
        // fetch the index tree
        BaseBST** ptr_to_index_tree = this->index_trees.get(field->getName());
        // retrieve name first (use constant reference to preserve temporary objects, or BaseField** will no longer be valid)
        BST<string, BaseField*> const & fieldsInEntry = new_entry->getFields();
        BaseField** const inEntry = fieldsInEntry.get(field->getName());
        // check if the column exists
        if (inEntry)
        {
            // found
            (*inEntry)->handleAddEntryToIndexTree((*ptr_to_index_tree), new_entry);
        }
        else
        {
            // not found -> use the default
            field->handleAddEntryToIndexTree((*ptr_to_index_tree), new_entry);
        }
    }

    /* This code will not add entry to index_tree if the field does not exist
    for (BaseField* const & field : new_entry->getFields().getInorder())
    {
        BaseBST** ptr_to_index_tree = this->index_trees.get(field->getName());
        // note that this uses dynamic binding
        field->handleAddEntryToIndexTree((*ptr_to_index_tree), new_entry);
    }
    */

    // done and return
    return;

    /* Just leave this part out -> you can always print the default value by printing the default tree
    // modify the entry to satisfy all fields
    std::vector<BaseField*> all_columns = this->default_fields.getInorder();
    std::vector<BaseField *> columns_in_entry = new_entry->getFields().getInorder();
    for (typename std::vector<BaseField*>::const_iterator itr_all = all_columns.begin(); itr_all != all_columns.end(); ++itr_all)
    {
        bool flag { false };
        for (typename std::vector<BaseField*>::const_iterator itr_ent = columns_in_entry.begin(); itr_ent != columns_in_entry.end(); ++itr_ent)
            if ((*itr_ent)->getName() == (*itr_all)->getName()) { flag = true; break; }

        // if found, great! do nothing
        // if not, add that field with default value
        if (!flag)
        {
            // but what is the type??? List or primitive
            // that does not matter, just copy the default field to the corresponding entry
            new_entry->setPrimitiveField ????
            You cannot continue as you do not know the type.
        }
    }
    */
}

/*
The assignment operator and the copy constructor of Table.
Make sure that you do full deep copying on the Table object.
For any HashTable object associated with the Table (i.e. the HashTable in the data members entries and index_trees), the internal ordering need not be the same. It's fine as long as the content of the copied HashTable is the same, since we consider the HashTable as a set overall.
You may want to look at the clone function in the BaseBST and BaseField classes to help you with this task.
*/
Table & Table::operator=(const Table &other)
{
    // check if it is self assignment
    if (this == &other) return (*this);

    /*
    HashTable<Entry*> entries; 
        -> the entries has to be copied (BUT delete the entries of this first)
    BST<string, BaseField*> default_fields;
        -> Copy from BST tree only copies the value
        -> Consider clear it first and insert manually
        -> get all pointers from the old BST as a vector
    BST<string, BaseBST*> index_trees;
    */

    // clear & de-allocate everything first
    // remove all entries from this
    // get all entries from the hash table
    for (Entry* & entry : this->entries.to_vector())
    {
        delete entry;
        this->entries.remove(entry);
    }

    // clear the two trees
    // but first, their datas are pointers
    // have to delete them first (just in mind -> the entries are no longer valid as we have already deleted them)
    // and when you delete the entry the fields are also gone
    // but we still need to take care of the default_fields

    // delete the default tree
    for (BaseField* & field : this->default_fields.getInorder())
        delete field;
    this->default_fields.clear();
    // as said, no need to worry about the fields, just delete BaseBST* in the index_trees
    for (BaseBST* & tree : this->index_trees.getInorder())
        delete tree;
    this->index_trees.clear();
    
    // now lets copy
    // first the default fields
    // and set up index_trees
    for (BaseField* const & field : other.default_fields.getInorder())
    {
        string name = field->getName();
        this->default_fields.insert(name, field->clone());
        // use the copy constructor
        // stay away from this error: ‘T’ was not declared in this scope
        BaseBST* new_tree = (*other.index_trees.get(name))->clone();
        // remember to clear the old data
        new_tree->clear();
        this->index_trees.insert(name, new_tree);
    }

    // then the entries
    // this will automatically re-hash everything
    // but we have to create the index_trees before hand
    for (Entry* const & entry : other.entries.to_vector())
        this->addEntry(*entry);

    // done and return
    return (*this);
}

Table::Table(const Table &other)
{
    // use the operator= we just defined
    (*this) = other;

    // done and return
    return;
}

/*
The destructor of Table.
Make sure that you delete any allocated memory.
*/
Table::~Table()
{
    // remove all entries from this
    // get all entries from the hash table
    for (Entry* & entry : this->entries.to_vector())
    {
        delete entry;
        this->entries.remove(entry);
    }

    // clear the two trees
    // but first, their datas are pointers
    // have to delete them first (just in mind -> the entries are no longer valid as we have already deleted them)
    // and when you delete the entry the fields are also gone
    // but we still need to take care of the default_fields

    // delete the default tree
    for (BaseField* & field : this->default_fields.getInorder())
        delete field;
    this->default_fields.clear();
    // as said, no need to worry about the fields, just delete BaseBST* in the index_trees
    for (BaseBST* & tree : this->index_trees.getInorder())
        delete tree;
    this->index_trees.clear();

    // finally we've tidied up the mess
    return;
}

/*
This function returns a new Table that only contains all the entries in table that their value in the field field_name equals to value, if the field is a primitive field. In case the field is a list field, it returns a new Table that only contains all the entries in table that the field field_name contains the value value.
You may assume the field_name must be valid in the table.
By returning a new Table it means a full deep copied Table, including the entries.
You should make use of the index trees to speed up the search if possible.
*/
template <typename T>
Table Table::Filter<T>::operator==(const T& value) const
{
    // from Filter<T> filter(string name) const
    // we know:
    // Filter<T> filter = {this -> this Table, name -> tab to look for};
    // for this structure:
    //     -> const Table* table;
    //     -> string field_name;

    // create the Table to return
    ::Table to_return { };

    // copy the general structure first
    // first the default fields
    // and set up index_trees
    for (BaseField* const & field : this->table->default_fields.getInorder())
    {
        string name = field->getName();
        to_return.default_fields.insert(name, field->clone());
        // use the copy constructor
        // stay away from this error: ‘T’ was not declared in this scope
        BaseBST* new_tree = (*this->table->index_trees.get(name))->clone();
        // remember to clear the old data
        new_tree->clear();
        to_return.index_trees.insert(name, new_tree);
    }

    // get the right index tree first
    BST<T, HashTable<Entry*>>* ptr_to_index_tree = 
    dynamic_cast<BST<T, HashTable<Entry*>>*>(
    *this->table->index_trees.get(this->field_name)
    );

    // get all entries
    HashTable<Entry*> const* table = (ptr_to_index_tree)->get(value);
    if (table)
    for (Entry* const & entry : table->to_vector())
        to_return.addEntry(*entry); // will copy

    // return the filtered table
    return to_return;
}