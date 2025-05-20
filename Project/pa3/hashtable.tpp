/* TODO: Implement the functions for the class HashTable */
/* Write your code below */

/*
The constructor of the HashTable class.
Make sure you initialize all the data members properly.
To calculate 2^base_exponent, instead of using pow (since it's not included in the given library), you can type 1 << base_exponent directly (this means left shift `1` by base_exponent bits, which is just basically 2^base_exponent).
You may assume that base_exponent and max_load_factor must both be positive.
*/
template <typename T>
HashTable<T>::HashTable(int base_exponent, double max_load_factor)
    :
    head_node{new TableNode{0, base_exponent, new std::vector<T>[1 << base_exponent] { }, nullptr}},
    total_size{0},
    cur_node{head_node},
    max_load_factor{max_load_factor}
{
    return;
}

/*
The destructor of the HashTable class.
Make sure you deallocate all the dynamically allocated memory.
*/
template <typename T>
HashTable<T>::~HashTable()
{
    // start off from the head
    while (this->head_node)
    {
        // delete the vactor array in the table first
        delete [] (this->head_node->table);
        // save this table address
        TableNode* toDelete = this->head_node;
        // go to next table
        this->head_node = this->head_node->next;
        // delete the table
        delete toDelete;
    }

    return;
}

/*
The assignment operator and the copy constructor of the HashTable class.
You should perform deep copy in the assignment operator and the copy constructor.
*/
template <typename T>
HashTable<T>& HashTable<T>::operator=(const HashTable<T>& other)
{
    // check self assignment
    if (this == &other) return (*this);

    // assign member variables
    this->total_size = other.total_size;
    this->max_load_factor = other.max_load_factor;

    // delete everything !!!
    // start off from the head
    while (this->head_node)
    {
        // delete the vactor array in the table first
        delete [] (this->head_node->table);
        // save this table address
        TableNode* toDelete = this->head_node;
        // go to next table
        this->head_node = this->head_node->next;
        // delete the table
        delete toDelete;
    }
    
    // create table one by one
    TableNode const * workingPtr_other = other.head_node;
    // create the first node
    this->head_node = this->cur_node = new TableNode{ };
    while (true)
    {
        // assign table(node) parameters
        this->cur_node->table_size = workingPtr_other->table_size;
        this->cur_node->exponent_size = workingPtr_other->exponent_size;
        // create new array of vectors
        this->cur_node->table = new std::vector<T>[1 << this->cur_node->exponent_size] { };
        // copy every sub-vector
        for (int i = 0; i < (1 << this->cur_node->exponent_size); i++) this->cur_node->table[i] = workingPtr_other->table[i];
        // go to next table (node)
        if (workingPtr_other->next)
        {
            this->cur_node = (this->cur_node->next = new TableNode{ });
            workingPtr_other = workingPtr_other->next;
            continue;
        }
        else
        {
            this->cur_node->next = nullptr;
            break;
        }
    }
    // 'cur_node' has already been set

    // done and return
    return (*this);
}

/*
The assignment operator and the copy constructor of the HashTable class.
You should perform deep copy in the assignment operator and the copy constructor.
*/
template <typename T>
HashTable<T>::HashTable(const HashTable &other) 
    :
    head_node{},
    total_size{},
    cur_node{},
    max_load_factor{}
{
    // note that the default constructor does not exist
    // so we init all member variables using the default constructor

    // we call the operator= just defined
    (*this) = other;

    // done and return
    return;
}

/*
Returns whether the given element is in the HashTable.
You can calculate the index of the bucket of value in a TableNode 
by doing pa3_hash(value) % (number of buckets in that TableNode). The pa3_hash function is already implemented for you in the file hash.h.
*/
template <typename T>
bool HashTable<T>::exists(const T &value) const
{
    // search through all tables
    TableNode const * workingPtr = this->head_node;
    while (workingPtr)
    {
        // calculate the hashed index
        unsigned int index = ::pa3_hash(value) % (1 << workingPtr->exponent_size);

        // search down the list
        std::vector<T> const & vec_to_search = workingPtr->table[index];
        for (typename std::vector<T>::const_iterator itr = vec_to_search.begin(); itr != vec_to_search.end(); ++itr)
            { if (*itr == value) return true; }

        // check next table
        workingPtr = workingPtr->next;
    }
    // not found
    return false;
}

/*
Inserts the given element into the HashTable.
You can calculate the index of the bucket of value in a TableNode by doing pa3_hash(value) % (number of buckets in that TableNode). The pa3_hash function is already implemented for you in the file hash.h.
You should check whether the value is already in the HashTable first. If yes, it should return false without doing anything.
The value should be inserted into the cur_node (i.e. the last node of the TableNode linked list).
However, if the load factor of the cur_node before the insertion is greater or equal to the max_load_factor, you should:
Create a new TableNode that has doubled the number of buckets of the cur_node.
Insert the value to be inserted into the new TableNode.
Link the new TableNode to the end of the linked list.
Remember to set and update all the data members properly.

load factor: the ratio of the number of elements in the TableNode to the number of buckets in that TableNode. 
For example, if we have 3 elements in a TableNode with 4 buckets, then the load factor is 0.75. 
If we have 8 elements in a TableNode with 4 buckets, the load factor is 2. 
When the load factor of the TableNode to be inserted an element exceeds a certain threshold, 
we can create a new TableNode and link it to the end of the linked list of TableNode.
*/
template <typename T>
bool HashTable<T>::insert(const T& value)
{
    // check is already in list (if so return immediately)
    if (this->exists(value)) return false;

    // now we are sure for certain that a insertion will happen
    // first check 'load factor of the cur_node'
    if 
    (
        (double)(this->cur_node->table_size) / 
        (double)(1 << this->cur_node->exponent_size)
        >=
        this->max_load_factor
    )
    {
        // we have to create a new table
        this->cur_node = 
        (this->cur_node->next = new TableNode { 0, this->cur_node->exponent_size + 1, new std::vector<T>[1 << (this->cur_node->exponent_size + 1)] { }, nullptr });
    }
    // get current table
    TableNode & table_to_insert = *(this->cur_node);
    // next, we calculate the hash and find the index
    unsigned int index = ::pa3_hash(value) % (1 << table_to_insert.exponent_size);
    // now we insert
    table_to_insert.table[index].push_back(value);

    // update variables
    table_to_insert.table_size++;
    this->total_size++;

    // done and return
    return true;
}

/*
Removes the given element from the HashTable.
You can calculate the index of the bucket of value in a TableNode by doing pa3_hash(value) % (number of buckets in that TableNode). The pa3_hash function is already implemented for you in the file hash.h.
If the value is not found in the HashTable, and can't be removed, it should return false without doing anything.
If the number of elements in a TableNode becomes 0 after the removal, and that TableNode is not the head_node, you should remove the TableNode from the linked list too.
Remember to set and update all the data members properly.
*/
template <typename T>
bool HashTable<T>::remove(const T& value)
{
    // check if it is in list
    // search through all tables
    TableNode* workingPtr = this->head_node;
    TableNode* prevPtr { };
    while (workingPtr)
    {
        // calculate the hashed index
        unsigned int index = ::pa3_hash(value) % (1 << workingPtr->exponent_size);

        // search down the list
        std::vector<T> & vec_to_search = workingPtr->table[index];
        for (typename std::vector<T>::iterator itr = vec_to_search.begin(); itr != vec_to_search.end(); ++itr)
        {
            if (*itr == value)
            {
                // FOUND the value
                vec_to_search.erase(itr);
                // update member variables
                workingPtr->table_size--;
                this->total_size--;
                // check if the current size of the table is 0
                if ((workingPtr != this->head_node) && (workingPtr->table_size == 0))
                {
                    // we have to detach the table
                    if (!(prevPtr->next = workingPtr->next))
                    {
                        // if the last, update 'cur_node'
                        this->cur_node = prevPtr;
                    }
                    // delete the table
                    delete [] (workingPtr->table);
                    delete workingPtr;
                }

                // done and return
                return true;
            }
        }

        // check next table
        prevPtr = workingPtr;
        workingPtr = workingPtr->next;
    }
    // not found
    return false;


}

/*
Returns all the elements in the HashTable in a vector.
You can return the elements in any order you like. Since we consider the HashTable as a set, which has no internal ordering.
*/
template <typename T>
std::vector<T> HashTable<T>::to_vector() const
{
    std::vector<T> to_return;
    // go through all tables
    TableNode const * workingPtr = this->head_node;
    while (workingPtr)
    {
        for (int i = 0; i < (1 << workingPtr->exponent_size); ++i)
        {
            // get the current vector
            std::vector<T> const & current_vec = workingPtr->table[i];
            // append the return vector
            to_return.insert(to_return.end(), current_vec.begin(), current_vec.end());
        }
        // go to next table
        workingPtr = workingPtr->next;
    }

    // done and return
    return to_return;
}