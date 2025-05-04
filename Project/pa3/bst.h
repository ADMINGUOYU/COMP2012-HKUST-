#ifndef BST_H
#define BST_H

#include <vector>

using namespace std;

class BaseBST {
    public:
        virtual ~BaseBST() {}
        virtual void clear() = 0;
        virtual BaseBST* clone() = 0;
};

template <typename K, typename V>
class BST : public BaseBST {

    private:
        struct Node {
            K key;
            V value;
            Node* left;
            Node* right;
            Node(const K& k, const V& v) : key(k), value(v), left(nullptr), right(nullptr) {}
        };
        
        Node* root;   // The root of the tree
        int count;    // The number of elements in the tree

    private:
       
        // TODO: Implement the function in bst.tpp
        vector<V> getInorder(Node* node) const;

        // TODO: Implement the function in bst.tpp
        vector<V> getInorderWithUpperBound(Node* node, const K& upper_bound) const;

        // TODO: Implement the function in bst.tpp
        vector<V> getInorderWithLowerBound(Node* node, const K& lower_bound) const;

    public:
        // Default constructor
        BST() : root(nullptr), count(0) {}
        
        // Copy constructor
        BST(const BST& other) : root(nullptr), count(other.count) {
            copyTree(root, other.root);
        }

        // Destructor
        ~BST() {
            clear();
        }

        // Assignment operator
        BST& operator=(const BST& other) {
            if (this != &other) {
                clear();
                count = other.count;
                copyTree(root, other.root);
            }
            return *this;
        }

        // Creates a new dynamically allocated BST object that is a copy of this one
        BaseBST* clone() override {
            return new BST(*this);
        }

        // Clears the tree
        void clear() override {
            clear(root);
            count = 0;
        }

        // Returns the number of elements in the tree
        int size() const {
            return count;
        }
        
        // Inserts a key-value pair into the tree
        // If the key already exists, it updates the value
        void insert(const K& key, const V& value) {
            insert(root, key, value);
        }

        // Returns a pointer that points to the value associated with a key
        // If the key does not exist, it returns nullptr
        V* get(const K& key) const {
            return get(root, key);
        }
        
        // Removes a key-value pair from the tree
        bool remove(const K& key) {
            return remove(root, key);
        }

        // Returns the height of the tree
        int height() const {
            return height(root);
        }

        vector<V> getInorder() const {
            return getInorder(root);
        }

        vector<V> getInorderWithUpperBound(const K& upper_bound) const {
            return getInorderWithUpperBound(root, upper_bound);
        }

        vector<V> getInorderWithLowerBound(const K& lower_bound) const {
            return getInorderWithLowerBound(root, lower_bound);
        }

    private:

        int height(Node* node) const {
            if (node == nullptr) return 0;
            return 1 + max(height(node->left), height(node->right));
        }

        void insert(Node*& node, const K& key, const V& value) {
            if (node == nullptr) {
                count++;
                node = new Node(key, value);
            } else if (key < node->key) {
                insert(node->left, key, value);
            } else if (key > node->key) {
                insert(node->right, key, value);
            } else {
                node->value = value; // Update value if key already exists
            }
            this->balance();
        }

        V* get(Node* node, const K& key) const {
            if (node == nullptr) return nullptr;
            if (key < node->key) return get(node->left, key);
            if (key > node->key) return get(node->right, key);
            return &(node->value);
        }

        void remove(Node*& node, const K& key) {
            if (node == nullptr) return;
            if (key < node->key) {
                remove(node->left, key);
            } else if (key > node->key) {
                remove(node->right, key);
            } else {
                // Node with only one child or no child
                count--;
                Node* temp = nullptr;
                if (node->left == nullptr) {
                    temp = node->right;
                    delete node;
                    node = temp;
                } else if (node->right == nullptr) {
                    temp = node->left;
                    delete node;
                    node = temp;
                } else {
                    // Node with two children: Get the inorder successor
                    Node* succParent = node;
                    Node* succ = node->right;
                    while (succ->left != nullptr) {
                        succParent = succ;
                        succ = succ->left;
                    }
                    // Copy the inorder successor's content to this node
                    node->key = succ->key;
                    node->value = succ->value;
                    // Delete the inorder successor
                    if (succParent != node)
                        succParent->left = succ->right;
                    else
                        succParent->right = succ->right;
                    delete succ;
                }
            }
            this->balance();
        }

        void copyTree(Node*& thisNode, Node* otherNode) {
            if (otherNode != nullptr) {
                thisNode = new Node(otherNode->key, otherNode->value);
                copyTree(thisNode->left, otherNode->left);
                copyTree(thisNode->right, otherNode->right);
            }
        }

        void clear(Node*& node) {
            if (node != nullptr) {
                clear(node->left);
                clear(node->right);
                delete node;
                node = nullptr;
            }
        }

        // AVL balancing logic
        void balance() {
            Node*& node = root;
            if (node == nullptr) return;

            int balanceFactor = height(node->left) - height(node->right);
            if (balanceFactor > 1) {
                if (height(node->left->left) >= height(node->left->right)) {
                    rotateRight(node);
                } else {
                    rotateLeft(node->left);
                    rotateRight(node);
                }
            } else if (balanceFactor < -1) {
                if (height(node->right->right) >= height(node->right->left)) {
                    rotateLeft(node);
                } else {
                    rotateRight(node->right);
                    rotateLeft(node);
                }
            }
        }

        // AVL balancing logic
        void rotateLeft(Node*& node) {
            Node* temp = node->right;
            node->right = temp->left;
            temp->left = node;
            node = temp;
        }
        
        // AVL balancing logic
        void rotateRight(Node*& node) {
            Node* temp = node->left;
            node->left = temp->right;
            temp->right = node;
            node = temp;
        }

};

#include "bst.tpp"

#endif