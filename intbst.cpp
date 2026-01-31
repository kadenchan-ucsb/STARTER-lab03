// intbst.cpp
// Implements class IntBST
// YOUR NAME(S), DATE

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() { 
    root = nullptr;
}

// destructor deletes all nodes
IntBST::~IntBST() {
    clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
    if(left){
        clear(n->left);
    }
    if(right){
        clear(n->right);
    }
    delete n;
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
    if(root==nullptr){
        root=new Node(value);
        return true;
    }
    else{
        if(root->value==value){
            return false;
        }
        if(root->value>value){
            if(root->left==nullptr){
                root->left=new Node(value);
                return true;
            }
            else{
                return insert(value,root->left);
            }
        }else{
            if(root->right==nullptr){
                root->right=new Node(value);
                return true;
            }
            else{
                return insert(value,root->right);
            }
        }
        
    }
    return true;
    
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
    
    if(n->value==value){
        return false;
    }
    if(n->value>value){
        if(n->left==nullptr){
            n->left=new Node(value);
            return true;
        }
        else{
            return insert(value,n->left);
        }
    }else{
        if(n->right==nullptr){
            n->right=new Node(value);
            return true;
        }
            else{
            return insert(value,n->right);
           }
       }
    return true;
        
    
}

// print tree data pre-order
void IntBST::printPreOrder() const {
    if(root==nullptr){
        cout << "";
    }else{
        cout<< root->value;
        if(root->left){
            printPreOrder(root->left);
        }
        if(root->right){
            printPreOrder(root->right);
        }
    }
    
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    if(n==nullptr){
        cout << "";
    }else{
        cout<< n->value;
        if(n->left){
            printPreOrder(n->left);
        }
        if(n->right){
            printPreOrder(n->right);
        }
    }
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
    if(root==nullptr){
        cout << "";
    }else{
        
        if(root->left){
            printInOrder(root->left);
        }
        cout<< root->value;
        if(root->right){
            printInOrder(root->right);
        }
    }
}
void IntBST::printInOrder(Node *n) const {
    if(n==nullptr){
        cout << "";
    }else{
       
        if(n->left){
            printInOrder(n->left);
        }
        cout<< n->value;
        if(n->right){
            printInOrder(n->right);
        }
    }
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
   if(root==nullptr){
        cout << "";
    }else{
        
        if(root->left){
            printPostOrder(root->left);
        }
        
        if(root->right){
            printPostOrder(root->right);
        }
        cout<< root->value;
    }
}

void IntBST::printPostOrder(Node *n) const {
    if(n==nullptr){
        cout << "";
    }else{
       
        if(n->left){
            printInOrder(n->left);
        }
        
        if(n->right){
            printInOrder(n->right);
        }
        cout<< n->value;
    }
}

// return sum of values in tree
int IntBST::sum() const {
    int total = 0;
    if(root==nullptr){
        return total;
    }else{
        
        if(root->left){
            total+=sum(root->left);
        }
        
        if(root->right){
            total+=sum(root->right);
        }
        return total+root->value;
    }
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    int total = 0;
    
    
    if(n->left){
        total+=sum(n->left);
    }
    
    if(n->right){
        total+=sum(n->right);
    }
    return total+root->value;
    
}

// return count of values
int IntBST::count() const {
    int total = 0;
    if(root==nullptr){
        return total;
    }else{
        
        if(root->left){
            total+=sum(root->left);
        }
        
        if(root->right){
            total+=sum(root->right);
        }
        return total+1;
    }
}

// recursive helper for count
int IntBST::count(Node *n) const {
    int total = 0;
    
    
    if(n->left){
        total+=sum(n->left);
    }
    
    if(n->right){
        total+=sum(n->right);
    
    return total+1;
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    return NULL; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    return false; // REPLACE THIS NON-SOLUTION
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
    return NULL; // REPLACE THIS NON-SOLUTION
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    return -1; // REPLACE THIS NON-SOLUTION
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
    return NULL; // REPLACE THIS NON-SOLUTION
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    return -1; // REPLACE THIS NON-SOLUTION
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
    return false; // REPLACE THIS NON-SOLUTION
}
