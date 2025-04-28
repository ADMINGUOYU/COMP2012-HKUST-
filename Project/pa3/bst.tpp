/* TODO: Implement the functions for the class BST */
/* Write your code below */

/*
A private member function for the BST class. 
This returns a list of all the associated values in the tree rooted at the given node, 
based on the inorder traversal of the keys in that tree.
*/
template <typename K, typename V>
std::vector<V> BST<K, V>::getInorder(Node *node) const
{
    // base case
    if (nullptr == node) return vector<V> { };

    // create a vector to return
    std::vector<V> vec { };
    // push back left
    const vector<V> & left_vec = getInorder(node->left);
    if (!left_vec.empty()) vec.insert(vec.end(), left_vec.begin(), left_vec.end());
    // push back self
    vec.push_back(node->value);
    // push back right
    const vector<V> & right_vec = getInorder(node->right);
    if (!right_vec.empty()) vec.insert(vec.end(), right_vec.begin(), right_vec.end());

    // return
    return vec;    
}

/*
A private function for the BST class. 
This returns a list of all the associated values in the tree rooted at the given node, 
based on the inorder traversal of the keys in that tree, with the keys that are strictly less than a given value.
*/
template <typename K, typename V>
std::vector<V> BST<K, V>::getInorderWithUpperBound(Node *node, const K &upper_bound) const
{
    // base case
    if (nullptr == node) return vector<V> { };

    // create a vector to return
    std::vector<V> vec { };
    // push back left
    const vector<V> & left_vec = getInorderWithUpperBound(node->left, upper_bound);
    if (!left_vec.empty()) vec.insert(vec.end(), left_vec.begin(), left_vec.end());
    // push back self (and key check)
    if (node->key < upper_bound)
    {
        vec.push_back(node->value);
        // push back right (if this value already exceeds upper_bound -> no need to add right branch)
        const vector<V> & right_vec = getInorderWithUpperBound(node->right, upper_bound);
        if (!right_vec.empty()) vec.insert(vec.end(), right_vec.begin(), right_vec.end());
    }

    // return
    return vec;
}

/*
A private function for the BST class. 
This returns a list of all the associated values in the tree rooted at the given node, 
based on the inorder traversal of the keys in that tree, with the keys that are strictly greater than a given value.
*/
template <typename K, typename V>
std::vector<V> BST<K, V>::getInorderWithLowerBound(Node *node, const K &lower_bound) const
{
    // base case
    if (nullptr == node) return vector<V> { };

    // create a vector to return
    std::vector<V> vec { };
    // push back left (and key check)
    if (node->key > lower_bound)
    {
        const vector<V> & left_vec = getInorderWithLowerBound(node->left, lower_bound);
        if (!left_vec.empty()) vec.insert(vec.end(), left_vec.begin(), left_vec.end());
        // push back self
        vec.push_back(node->value);
    }
    // push back right
    const vector<V> & right_vec = getInorderWithLowerBound(node->right, lower_bound);
    if (!right_vec.empty()) vec.insert(vec.end(), right_vec.begin(), right_vec.end());

    // return
    return vec;
}