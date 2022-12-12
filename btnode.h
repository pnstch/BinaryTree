#pragma once
#include <iostream>

struct btnode;
/**
* \brief Статический метод преобразования в строку.
* \param node Узел дерева.
* \return Данные в виде строки.
*/
std::wstring ToString(const btnode& node);

/**
* \brief Узел дерева.
*/
struct btnode
{
    /**
    * \brief Данные.
    */
    int data;

    /**
    * \brief Указатель на левый узел.
    */
    btnode* left;

    /**
    * \brief Указатель на правый узел.
    */
    btnode* right;

    /**
    * \brief Указатель на родительский узел.
    */
    btnode* parent;

    /**
    * \brief Инициализация нового экземпляра класса Узел дерева.
    * \brif Необходим для тестов.
    */
    btnode();

    /**
    * \brief Инициализация нового экземпляра класса Узел дерева.
    * \param data Данные.
    */
    btnode(const int data);

    /**
    * \brief Деструктор
    */
    ~btnode();

    /**
    * \brief Оператор вывода в стандартный поток данных.
    * \param out Стандартный поток данных.
    * \param node Узел дерева.
    */
    friend std::ostream& operator<<(std::ostream& out, const btnode& node);

    /**
    * \brief Оператор вывода в стандартный поток данных.
    * \param out Стандартный поток данных.
    * \param node Узел дерева.
    */
    friend std::wostream& operator<<(std::wostream& out, const btnode& node);

    /**
    * \brief Оператор ввода из стандартного потока данных.
    * \param out Стандартный поток данных.
    * \param node Узел дерева.
    */
    friend std::istream& operator>>(std::istream& in, btnode& node);

    /**
    * \brief Оператор равенства двух узлов.
    * \param lha Левый узел.
    * \parm rha Правый узел.
    * \return true, если равны.
    */
    friend bool operator==(const btnode& lha, const btnode& rha);

    /**
    * \brief Оператор неравенства двух узлов.
    * \param lha Левый узел.
    * \param rha Правый узел.
    * \return true, если не равны.
    */
    friend bool operator!=(const btnode& lha, const btnode& rha);

    /**
    * \brief Оператор больше.
    * \param lha Левый узел.
    * \param rha Правый узел.
    * \return true, если левый узел больше.
    */
    friend bool operator>(const btnode& lha, const btnode& rha);

    /**
    * \brief Оператор больше или равно.
    * \param lha Левый узел.
    * \param rha Правый узел.
    * \return true, если левый узел больше.
    */
    friend bool operator>=(const btnode& lha, const btnode& rha);

    /**
    * \brief Оператор меньше.
    * \param lha Левый узел.
    * \param rha Правый узел.
    * \return true, если левый узел меньше.
    */
    friend bool operator<(const btnode& lha, const btnode& rha);

    /**
    * \brief Оператор меньше.
    * \param lha Левый узел.
    * \parm rha Правый узел.
    * \return true, если левый узел меньше.
    */
    friend bool operator<=(const btnode& lha, const btnode& rha);
}; #pragma once
