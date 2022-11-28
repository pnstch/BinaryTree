#pragma once
#include <iostream>

using namespace std;


struct btnode
{
    int data;
    btnode* l;
    btnode* r;
    btnode* leaf;

    /**
        * \brief �������� ������ � ����������� ����� ������.
        * \param out ����������� ����� ������.
        * \param node ���� ������.
    */
    friend std::ostream& operator<<(std::ostream& out, btnode* leaf);
    /**
        * \brief �������� ����� �� ������������ ������ ������.
        * \param out ����������� ����� ������.
        * \param node ���� ������.
    */
    friend std::istream& operator>>(std::istream& in, btnode* leaf);
};

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
