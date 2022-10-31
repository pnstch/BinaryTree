#pragma once
#include <iostream>
#include <queue>
#include <clocale>
#include "BinaryTree.h"



int main()
{
    setlocale(LC_CTYPE, "rus");
    binaryTree myTree;
    //choice - выбор для case
    int choice;
    while (1)
    {
        //Меню
        menu:
        cout << "Бинарное дерево" << endl
            << "Меню" << endl
            << "---------------" << endl;
        cout << "1. Вставить элемент" << endl
            << "2. Удалить дерево" << endl
            << "3. Вывести дерево" << endl
            << "4. Выход" << endl;
        cout << "Введите ваш выбор: ";
        cin >> choice;
        //проверка вводимых данных
        if (!cin)
        {
            cin.clear();
            cin.ignore();
            cout << "Введите число повторно" << endl
                << endl;
        }
        else
        {
            switch (choice)
            {
            case 1:
                int key;
                cout << "Введите число для вставки: ";
                cin >> key;
                myTree.insert(key);
                cout << endl;
                goto menu;
            case 2:
                myTree.deleteTree();
                cout << "Дерерво удалено" << endl;
                goto menu;
            case 3:
                myTree.printTree();
                goto menu;
            
            case 4:
                exit(0);
                break;
            default:
                cout << "Проверьте ввод" << endl
                    << endl;
                goto menu;
            }
        }
    }
    return 0;
}


/**
    * \brief Конструктор
    * \*param root Корень дерева
    */
binaryTree::binaryTree()
{
    root = nullptr;
}

/**
    * \brief Деструктор, вызывает рекурсивную функцию удаления дерева
    * \*param root Корень дерева
    */
binaryTree::~binaryTree()
{
    deleteTree(root);
}

/**
    * \brief публичная функция, позволяющая удалить все дерево, вызывает приватную рекурсивную функцию с доступом к корню
    * \*param root Корень дерева
    */
void binaryTree::deleteTree()
{
    deleteTree(root);
    root = nullptr;
}

/**
    * \brief Рекурсивная функция для удаления дерева
    * \*param leaf Лист дерева
     * \l - левый
    *\ r - правый
    */
void binaryTree::deleteTree(btnode* leaf)
{
    if (leaf)
    {
        deleteTree(leaf->l);
        deleteTree(leaf->r);
        delete leaf;
    }
}

/**
    * \публичная функция, позволяющая вставлять данные в дерево, вызывает приватную рекурсивную функцию с доступом к корневому узлу
    * \*param root Корень дерева
    * \*param key Ключ
    */
void binaryTree::insert(int key)
{
    insert(key, root);
}


/**
    * \приватная рекурсивная функция с доступом к корневому узлу
    * \*param root Корень дерева
     * \*param leaf Лист дерева
    * \*param key Ключ
    * \*param data Данные
    * \l - левый
    *\ r - правый
    */
void binaryTree::insert(int key, btnode* leaf)
{
    //создание корневой ноды
    if (!root)
    {
        root = new btnode;
        root->data = key;
        root->l = root->r = nullptr;
    }
    //создание ноды
    else
    {
        //проверка наличия информации слева
        if (key < leaf->data)
        {
            //проверка левого узла. если он есть-вызываем рекурсивную функцию
            if (leaf->l)
            {
                insert(key, leaf->l);
            }
            //если нет левой ноды-создаём её
            else
            {
                leaf->l = new btnode;
                leaf->l->data = key;
                leaf->l->l = leaf->l->r = nullptr;
            }
        }
        //проверка наличия информации справа
        else
        {
            //проверка правого узла. если он есть-вызываем рекурсивную функцию
            if (leaf->r)
            {
                insert(key, leaf->r);
            }
            //если нет правой ноды-создаём её
            else
            {
                leaf->r = new btnode;
                leaf->r->data = key;
                leaf->r->l = leaf->r->r = nullptr;
            }
        }
    }
}

/**
    * \публичная функция печати дерева
    * \*param root Корень дерева
    */
void binaryTree::printTree()
{
    printTree(root);
}

/**
    * \приватная функция печати дерева
    * \*param root Корень дерева
     * \*param leaf Лист дерева
    * \* Использует очередь, чтобы распознать ноды и распечатать их
    * \l - левый
    *\ r - правый
    */

//private member function that prints the tree with depth.
//uses a queue to recognize nodes and print them
void binaryTree::printTree(btnode* leaf)
{
    if (!root)
    {
        return;
    }
    queue<btnode*> q;
    q.push(root);
    //run until all nodes have been printed
    while (!q.empty())
    {
        int nodeCount = q.size();
        //run until all nodes are popped out of the queue
        while (nodeCount > 0)
        {
            btnode* leaf = q.front();
            cout << leaf->data << " ";
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
        cout << endl;
    }
}

/**
    * \brief Рекурсивная функция поиска по дереву
    * \*param root Корень дерева
     * \*param leaf Лист дерева
    * \*param key Ключ
    * \*param data Данные
    * \l - левый
    *\ r - правый
    * \ return nullptr или найденный элемент
    */
btnode* binaryTree::search(int key, btnode* leaf)
{
    //если нода существует
    if (leaf)
    {
        //если ключ равен ноде, вернуть ноду
        if (key == leaf->data)
        {
            return leaf;
        }
        //если ключ меньше, чем нода, проверяем левую ноду
        if (key < leaf->data)
        {
            return search(key, leaf->l);
        }
        //если ключ больше, чем нода, проверяем правую ноду
        else
        {
            return search(key, leaf->r);
        }
    }
    //если нет ноды-возвращает nullptr
    else
    {
        return nullptr;
    }
}
