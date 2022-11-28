#pragma once
#include <queue>
#include <queue>
#include <clocale>
#include <sstream>
#include <iostream>

#include "BinaryTree.h"


/**
    * \brief Конструктор
    * \param root Корень дерева
*/
BinaryTree::BinaryTree() : root(nullptr)
{
    root = nullptr;
}


/**
    * \brief Деструктор, вызывает рекурсивную функцию удаления дерева
    * \param root Корень дерева
*/
BinaryTree::~BinaryTree()
{
    deleteTree(root);
}


/**
    * \brief публичная функция, позволяющая удалить все дерево, вызывает приватную рекурсивную функцию с доступом к корню
    * \param root Корень дерева
*/
void BinaryTree::deleteTree()
{
    deleteTree(root);
    root = nullptr;
}


/**
    * \brief Рекурсивная функция для удаления дерева
    * \param leaf Лист дерева
    * \l - левый
    * \r - правый
*/
void BinaryTree::deleteTree(btnode* leaf)
{
    if (leaf != nullptr)
    {
        deleteTree(leaf->l);
        deleteTree(leaf->r);
        delete leaf;
    }
}


/**
    * \brief Функция возвращает заполненность дерева
    * \return bool - заполненность дерева
*/
bool BinaryTree::IsEmpty()   {
    return this->root == nullptr;
}


/**
    * \brief публичная функция, позволяющая вставлять данные в дерево, вызывает приватную рекурсивную функцию с доступом к корневому узлу
    * \param root Корень дерева
    * \param key Ключ
*/
void BinaryTree::insert(int key)
{
    insert(key, root);
}


/**
    * \brief приватная рекурсивная функция с доступом к корневому узлу
    * \param root Корень дерева
    * \param leaf Лист дерева
    * \param key Ключ
    * \param data Данные
    * \l - левый
    * \r - правый
*/
void BinaryTree::insert(int key, btnode* leaf)
{
    // Cоздание корневой ноды
    if (root == nullptr)
    {
        root = new btnode;
        root->data = key;
        root->l = root->r = nullptr;
    }
    // Cоздание ноды
    else
    {
        // Проверка наличия информации слева
        if (key < leaf->data)
        {
            // Проверка левого узла. если он есть-вызываем рекурсивную функцию
            if (leaf->l)
            {
                insert(key, leaf->l);
            }
            // Если нет левой ноды-создаём её
            else
            {
                leaf->l = new btnode;
                leaf->l->data = key;
                leaf->l->l = leaf->l->r = nullptr;
            }
        }
        // Проверка наличия информации справа
        else
        {
            // Проверка правого узла. если он есть-вызываем рекурсивную функцию
            if (leaf->r)
            {
                insert(key, leaf->r);
            }
            // Если нет правой ноды-создаём её
            else
            {
                leaf->r = new btnode;
                leaf->r->data = key;
                leaf->r->l = leaf->r->r = nullptr;
            }
        }
    }
}


std::ostream& operator<<(std::ostream& out, BinaryTree& tree)
{
    if (tree.IsEmpty())
    {
        return out << "{}";
    }
    queue<btnode*> q;

    q.push(tree.root);
    //run until all nodes have been printed
    out << "{";
    while (!q.empty())
    {
        int nodeCount = q.size();
        //run until all nodes are popped out of the queue
        while (nodeCount > 0)
        {
            btnode* leaf = q.front();
            out << leaf->data << ", ";
            q.pop();
            //add to the queue if a left node exists
            if (leaf->l)
            {
                q.push(leaf->l);
            }
            //add to the queue if a right node exists
            if (leaf->r)
            {
                q.push(leaf->r);
            }
            //remove count on the node popped
            nodeCount--;
        }
    }
    return out << "\b\b}\n";
}