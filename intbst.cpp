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
    if (!n) return;
    if (n->left) {
        clear(n->left);
    }
    if (n->right) {
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
        if(root->info==value){
            return false;
        }
        if(root->info>value){
            if(root->left==nullptr){
                root->left=new Node(value);
                root->left->parent=root;
                return true;
            }
            else{
                return insert(value,root->left);
            }
        }else{
            if(root->right==nullptr){
                root->right=new Node(value);
                root->right->parent=root;
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
    
    if(n->info==value){
        return false;
    }
    if(n->info>value){
        if(n->left==nullptr){
            n->left=new Node(value);
            n->left->parent = n;
            return true;
        }
        else{
            return insert(value,n->left);
        }
    }else{
        if(n->right==nullptr){
            n->right=new Node(value);
            n->right->parent = n;
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
        cout<< root->info<<" ";
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
        cout<< n->info<<" ";
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
        cout<< root->info<<" ";
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
        cout<< n->info<<" ";
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
        cout<< root->info<<" ";
    }
}

void IntBST::printPostOrder(Node *n) const {
    if(n==nullptr){
        cout << "";
    }else{
       
        if(n->left){
            printPostOrder(n->left);
        }
        
        if(n->right){
            printPostOrder(n->right);
        }
        cout<< n->info<<" ";
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
       
    }
    return total+root->info;
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
    return total+n->info;
    
}

// return count of values
int IntBST::count() const {
    int total = 0;
    if(root==nullptr){
        return total;
    }else{
        
        if(root->left){
            total+=count(root->left);
        }
        
        if(root->right){
            total+=count(root->right);
        }
        
    }
    return total+1;
}

// recursive helper for count
int IntBST::count(Node *n) const {
    int total = 0;
    
    
    if(n->left){
        total+=count(n->left);
    }
    
    if(n->right){
        total+=count(n->right);
    }
    return total+1;
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    if (n == nullptr) {
        return nullptr;
    }
    if(n->info==value){
        return n;
    }
    if(n->info>value){
        
        return getNodeFor(value, n->left);
        
    }else{
        
        return getNodeFor(value, n->right);
        
    }
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
return getNodeFor(value, root) != nullptr;

}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
    Node * curr = getNodeFor(value, root);
    if(!curr){
        return NULL;
    }
    if(curr&&curr->left){
            curr=curr->left;
            while(curr->right){
                curr=curr->right;
            }
            return curr;
    }
    Node * currtwo = getNodeFor(value, root)->parent;
    while(currtwo&&currtwo->left==curr){
        curr = currtwo;
        currtwo = curr->parent;
    }
    return currtwo;

}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    Node * curr = getPredecessorNode(value);
    if(curr){
        return curr->info;
    }else{
        return 0;
    }
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
    Node * curr = getNodeFor(value, root);
    if(!curr){
        return NULL;
    }
    if(curr&&curr->right){
            curr=curr->right;
            while(curr->left){
                curr=curr->left;
            }
            return curr;
    }
    Node * currtwo = getNodeFor(value, root)->parent;
    while(currtwo&&currtwo->right==curr){
        curr = currtwo;
        currtwo = curr->parent;
    }
    return currtwo;
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    Node * curr = getSuccessorNode(value);
    if(curr){
        return curr->info;
    }else{
        return 0;
    }
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
    return false; // REPLACE THIS NON-SOLUTION
}
