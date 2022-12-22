#include <iostream>

#include "BinaryTree.cpp"


int main()
{
    setlocale(LC_CTYPE, "rus");

    BinaryTree myTree;
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
                cout << myTree << endl;
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
