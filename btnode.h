#pragma once
#include <iostream>

struct btnode;
/**
* \brief ����������� ����� �������������� � ������.
* \param node ���� ������.
* \return ������ � ���� ������.
*/
std::wstring ToString(const btnode& node);

/**
* \brief ���� ������.
*/
struct btnode
{
    /**
    * \brief ������.
    */
    int data;

    /**
    * \brief ��������� �� ����� ����.
    */
    btnode* left;

    /**
    * \brief ��������� �� ������ ����.
    */
    btnode* right;

    /**
    * \brief ��������� �� ������������ ����.
    */
    btnode* parent;

    /**
    * \brief ������������� ������ ���������� ������ ���� ������.
    * \brif ��������� ��� ������.
    */
    btnode();

    /**
    * \brief ������������� ������ ���������� ������ ���� ������.
    * \param data ������.
    */
    btnode(const int data);

    /**
    * \brief ����������
    */
    ~btnode();

    /**
    * \brief �������� ������ � ����������� ����� ������.
    * \param out ����������� ����� ������.
    * \param node ���� ������.
    */
    friend std::ostream& operator<<(std::ostream& out, const btnode& node);

    /**
    * \brief �������� ������ � ����������� ����� ������.
    * \param out ����������� ����� ������.
    * \param node ���� ������.
    */
    friend std::wostream& operator<<(std::wostream& out, const btnode& node);

    /**
    * \brief �������� ����� �� ������������ ������ ������.
    * \param out ����������� ����� ������.
    * \param node ���� ������.
    */
    friend std::istream& operator>>(std::istream& in, btnode& node);

    /**
    * \brief �������� ��������� ���� �����.
    * \param lha ����� ����.
    * \parm rha ������ ����.
    * \return true, ���� �����.
    */
    friend bool operator==(const btnode& lha, const btnode& rha);

    /**
    * \brief �������� ����������� ���� �����.
    * \param lha ����� ����.
    * \param rha ������ ����.
    * \return true, ���� �� �����.
    */
    friend bool operator!=(const btnode& lha, const btnode& rha);

    /**
    * \brief �������� ������.
    * \param lha ����� ����.
    * \param rha ������ ����.
    * \return true, ���� ����� ���� ������.
    */
    friend bool operator>(const btnode& lha, const btnode& rha);

    /**
    * \brief �������� ������ ��� �����.
    * \param lha ����� ����.
    * \param rha ������ ����.
    * \return true, ���� ����� ���� ������.
    */
    friend bool operator>=(const btnode& lha, const btnode& rha);

    /**
    * \brief �������� ������.
    * \param lha ����� ����.
    * \param rha ������ ����.
    * \return true, ���� ����� ���� ������.
    */
    friend bool operator<(const btnode& lha, const btnode& rha);

    /**
    * \brief �������� ������.
    * \param lha ����� ����.
    * \parm rha ������ ����.
    * \return true, ���� ����� ���� ������.
    */
    friend bool operator<=(const btnode& lha, const btnode& rha);
}; #pragma once
