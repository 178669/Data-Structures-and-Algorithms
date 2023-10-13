#include "binary_search_tree.hpp"

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree()
{
    root = 0;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(
    const BinarySearchTree<KeyType, ItemType>& rhs)
{
    root = 0;
    Node<KeyType, ItemType>** lhs = &root;

    std::stack<stackvar<KeyType, ItemType>> s;

    stackvar<KeyType, ItemType> rootvar;
    rootvar.rhs = rhs.root;
    rootvar.lhs = lhs;
    s.push(rootvar);

    while (!s.empty()) {
        stackvar<KeyType, ItemType> currentvar = s.top();
        s.pop();

        Node<KeyType, ItemType>* curr_rhs = currentvar.rhs;
        Node<KeyType, ItemType>** curr_lhs = currentvar.lhs;

        if (curr_rhs == 0)
            continue;

        // allocate new node and copy contents
        Node<KeyType, ItemType>* temp = new Node<KeyType, ItemType>;
        temp->key = curr_rhs->key;
        temp->data = curr_rhs->data;
        temp->left = 0;
        temp->right = 0;
        *curr_lhs = temp;

        // push left subtree
        currentvar.rhs = curr_rhs->left;
        currentvar.lhs = &((*curr_lhs)->left);
        s.push(currentvar);

        // push right subtree
        currentvar.rhs = curr_rhs->right;
        currentvar.lhs = &((*curr_lhs)->right);
        s.push(currentvar);
    }
}


template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>& BinarySearchTree<KeyType, ItemType>::
operator=(BinarySearchTree<KeyType, ItemType> rhs)
{
    swap(rhs);
    return *this;
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::swap(BinarySearchTree<KeyType, ItemType>& rhs)
{
    std::swap(root, rhs.root);
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::~BinarySearchTree()
{
    destroy();
}


template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::destroy()
{
    std::stack<Node<KeyType, ItemType>*> s;
    s.push(root);

    while (!s.empty()) {
        Node<KeyType, ItemType>* curr = s.top();
        s.pop();

        if (curr != 0) {
            s.push(curr->left);
            s.push(curr->right);
            delete curr;
        }
    }
    root = 0;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::insert(
    const KeyType& key, const ItemType& item)
{
    Node<KeyType, ItemType>* node = new Node<KeyType, ItemType>; // Create a new node
    node->key = key; //current node's key to input key
    node->data = item; //current node to input item
    node->left = 0; //left null
    node->right = 0; //right null
    if(root==0)
        { //if null root
            root = node; //this node becomes the root
            return true; //if empty, then node just gets inserted normally
        }
    else
        {
            Node<KeyType, ItemType>* current; //node pointer for current node
            Node<KeyType, ItemType>* parent; //parent node pointer
            search(key, current, parent); //searching for key using search function
            if(key<current->key)//if input key is less than current's key
                {
                current->left = node; //left of current node to input node
                return true;
                }
            if(key>current->key)//if input's key is greater than current's key
                {
                current->right = node; //right of current node to input node
                return true;
                }
        }
    return false;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::isEmpty()
{
    return (root == 0);
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::retrieve(
    const KeyType& key, ItemType& item)
{
    Node<KeyType, ItemType>* curr;
    Node<KeyType, ItemType>* curr_parent;
    search(key, curr, curr_parent);

    if (curr == 0)
        return false;

    if (curr->key == key) {
        item = curr->data;
        return true;
    }

    return false;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::remove(KeyType key)
{
    if (isEmpty())
        return false; // empty tree

    Node<KeyType, ItemType>* current; // Create current pointer
    Node<KeyType, ItemType>* parent; // Create parent pointer
    search(key, current, parent); //search for key

    if(key!=current->key)
        { // If the key is not found
            return false; // Return false
        }

    // case one thing in the tree
    if(root->left==0&&root->right==0)
        { // If only one node present
            delete root;
            root = 0;
            return true;
        }

    // case, found deleted item at leaf
    else if(root!=current&&current->left==0&&current->right==0)
        { 
            if(parent->left==current)
                { // If the curr node is at the left of parent
                    parent->left = 0; //setting left to 0
                    delete current; 
                    return true; 
                }
            else if(parent->right==current)
                { //if current node is right of parent node
                    parent->right = 0; //right of curr to 0
                    delete current;
                    return true; 
                }
        }

    // case, item to delete has only a right child
    else if(current->right!=0&&current->left==0)
        {
            Node<KeyType, ItemType>* node = current; //temp node 
            if(current == root)
                { // If curr is equal to root
                    root = current->right; //root to current's right tree
                }
            current = current->right; //current to right tree
            delete node; 
            return true; 
        }

    // case, item to delete has only a left child
    else if(current->left!=0&&current->right==0)
    {
        Node<KeyType, ItemType>* node = current; //temp node creation
        if(current == root)
            { // If curr is equal to root
                root = current->right; //setting root to right tree
            }    
        current = current->left;//setting current to left tree
        delete node;
        return true; 
    }

    // case, item to delete has two children
    else if(current->left!=0&&current->right!=0)
    {
        Node<KeyType, ItemType>* node; 
        parent = current;
        current = current->right; 
        inorder(current, node, parent);
        current = node; 
        delete node;
        return true;
    }

    return false; // default should never get here
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorder(Node<KeyType, ItemType>* curr,
    Node<KeyType, ItemType>*& in, Node<KeyType, ItemType>*& parent)
{
    // TODO: find inorder successor of "curr" and assign to "in"
    while(1)//arbritary loop
    {
        if(curr->left==0)//if left is 0, no child node
        {
            in = curr; //seting in (input) to current
            curr = parent->left;//reset current to original
            break;//base case, breaks out of loop once reached
        }
        else{
            curr = curr->left;//set current to left branch
        }
    }
    
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::search(KeyType key,
    Node<KeyType, ItemType>*& curr, Node<KeyType, ItemType>*& parent)
{
    curr = root;
    parent = 0;

    if (isEmpty())
        return;

    while (true) {
        if (key == curr->key) {
            break;
        } else if (key < curr->key) {
            if (curr->left != 0) {
                parent = curr;
                curr = curr->left;
            } else
                break;
        } else {
            if (curr->right != 0) {
                parent = curr;
                curr = curr->right;
            } else
                break;
        }
    }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::treeSort(KeyType arr[], int size) {
    // TODO: check for duplicate items in the input array

    // TODO: use the tree to sort the array items

    // TODO: overwrite input array values with sorted values
}
