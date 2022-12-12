#pragma once
#include <iostream>
#include "btnode.h"
using namespace std;



class BinaryTree
{
public:
    BinaryTree();
    btnode* root;
    ~BinaryTree();
    bool IsEmpty();
    void deleteTree();
    void insert(int key);
    // bool search(const int key);
    // string ToString();
    // void printTree();
    // void InOrder();
    // void empty();

private:
    void printTree(btnode* leaf);
    void deleteTree(btnode* leaf);
    void insert(int key, btnode* leaf);
    // btnode* search(int key, btnode* leaf);
};
