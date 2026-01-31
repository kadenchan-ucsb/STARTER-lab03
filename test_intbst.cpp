#include "intbst.h"

#include <iostream>
using std::cout;

int main(){
    IntBST test;
    test.insert(3);
    test.insert(1);
    test.insert(2);
    test.insert(3);
    test.insert(8);
    test.insert(7);
    test.insert(4);
    test.insert(5);
    test.printInOrder();
    test.printPostOrder();
    test.printPreOrder();
    int total = test.sum();
    int amount = test.count();
    bool isin = test.contains(6);
    test.getPredecessor(5);
    test.getSuccessor(5);
    test.remove(8);


    
}