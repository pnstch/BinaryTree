#include "btnode.h"
#include <string>
#include <sstream>

btnode::btnode()
    : btnode(0)
{
}

btnode::btnode(const int data)
    : data(data), left(nullptr), right(nullptr), parent(nullptr)
{
}

btnode::~btnode()
{

    if (this->parent != nullptr)
    {
        if (this->parent->left == this)
        {
            this->parent->left = nullptr;
        }
        else
        {
            this->parent->right->right = nullptr;
        }
    }

    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}



std::wstring ToString(const btnode& btnode)
{
    std::wstringstream out;
    out << btnode;
    return out.str();
}

std::ostream& operator<<(std::ostream& out, const btnode& btnode)
{
    return out << btnode.data;
}

std::wostream& operator<<(std::wostream& out, const btnode& btnode)
{
    return out << btnode.data;
}

std::istream& operator>>(std::istream& in, btnode& btnode)
{
    if (in.peek() == '\n' || in.eof())
    {
        return in;
    }

    in >> btnode.data;
    return in;
}

bool operator==(const btnode& lha, const btnode& rha)
{
    return lha.data == rha.data;
}

bool operator!=(const btnode& lha, const btnode& rha)
{
    return !(lha == rha);
}

bool operator>(const btnode& lha, const btnode& rha)
{
    return lha.data > rha.data;
}

bool operator>=(const btnode& lha, const btnode& rha)
{
    return lha.data >= rha.data;
}

bool operator<(const btnode& lha, const btnode& rha)
{
    return lha.data < rha.data;
}

bool operator<=(const btnode& lha, const btnode& rha)
{
    return lha.data <= rha.data;
}