#include <iostream>
#include "Menu.h"


void menu()
{
    setlocale(LC_ALL, "RU");
    std::cout << "1. Создание корня - введите 1\n";
    std::cout << "2. Присоединение ветви - введите 2\n";
    std::cout << "3. Отсоединение ветви - введите 3\n";
    std::cout << "4. Постфиксный обход - введите 4\n";
    std::cout << "5. Инфиксный обход - введите 5\n";
    std::cout << "6. Префиксный обход - введите 6\n";
    std::cout << "7. Вывод - введите 7\n";
    std::cout << "8. Поиск максимального элемента - введите 8\n";
    std::cout << "9. Количество максимальных элементов - введите 9\n";
    int number;
    TreeNode* root;
    Init(root);
    while (true)
    {
        std::cout << "Введите номер команды:\n";
        std::cin >> number;
        if (number == 0)
            break;
        switch (number)
        {
        case 1:
        {
            std::cout << "1. Создание пустого корня - введите 1\n";
            std::cout << "2. Создание корня со значением - введите 2\n";
            std::cout << "3. Создание корня с значениeм, правой и левой ветвью - введите 3\n";
            std::cout << "Введите номер команды:\n";
            std::cin >> number;
            switch (number)
            {
                int root_value;
            case 1:
                Init(root);
                break;
            case 2:
                std::cout << "Введите значение корня:\n";
                std::cin >> root_value;
                Init(root, root_value);
                break;
            case 3:
                int left_subtree_value, right_subtree_value;
                TreeNode* left_subtree;
                TreeNode* right_subtree;
                std::cout << "Введите значение корня:\n";
                std::cin >> root_value;
                std::cout << "Введите значение левого поддерева:\n";
                std::cin >> left_subtree_value;
                std::cout << "Введите значение правого поддерева:\n";
                std::cin >> right_subtree_value;
                Init(left_subtree, left_subtree_value);
                Init(right_subtree, right_subtree_value);
                Init(root, root_value, left_subtree, right_subtree);
                break;
            default:
                std::cout << "Неверное значение\n";
                break;
            }
            break;
        }
        case 2:
        {
            TreeNode* current = root;
            std::string direction;
            while (current != nullptr)
            {
                std::cout << "Куда хотите продвинуться? (Right или Left или No)\n";
                std::cin >> direction;
                if ((direction == "right" || direction == "Right") && !IsEmpty(current->right))
                    current = current->right;
                else if ((direction == "right" || direction == "Right") && IsEmpty(current->right))
                {
                    std::cout << "Переход вправо ведёт в пустоту! Добавить значение (Yes|No)\n";
                    std::string answer;
                    std::cin >> answer;
                    if (answer == "Yes" || answer == "yes")
                    {
                        int right_subtree_value;
                        TreeNode* right_subtree;
                        std::cout << "Введите значение поддерева:\n";
                        std::cin >> right_subtree_value;
                        Init(right_subtree, right_subtree_value);
                        AttachRightSubTree(current, right_subtree);
                    }
                    else
                        current->right;
                }
                else if ((direction == "left" || direction == "Left") && !IsEmpty(current->left))
                    current = current->left;
                else if ((direction == "left" || direction == "Left") && IsEmpty(current->left))
                {
                    std::cout << "Переход влево ведёт в пустоту! Добавить значение (Yes|No)\n";
                    std::string answer;
                    std::cin >> answer;
                    if (answer == "Yes" || answer == "yes")
                    {
                        int left_subtree_value;
                        TreeNode* left_subtree;
                        std::cout << "Введите значение поддерева:\n";
                        std::cin >> left_subtree_value;
                        Init(left_subtree, left_subtree_value);
                        AttachLeftSubTree(current, left_subtree);
                    }
                    else
                        current->right;
                }
                else if (direction == "No" || direction == "no")
                    current = nullptr;
                else
                    std::cout << "Некорректное значение\n";
                Print(current);

            }
            delete current;
            break;
        }
        case 3:
        {
            TreeNode* current = root;
            std::string direction;
            while (current != nullptr)
            {
                std::cout << "Хотите продвинуться или отсоединить поддерево? (direction или disconnect или No)\n";
                std::cin >> direction;
                if (direction == "direction")
                {
                    std::cout << "Куда хотите продвинуться? (Right или Left)\n";
                    std::cin >> direction;
                    if ((direction == "right" || direction == "Right") && !IsEmpty(current->right))
                        current = current->right;
                    else if ((direction == "right" || direction == "Right") && IsEmpty(current->right))
                        std::cout << "Переход вправо ведёт в пустоту!\n";
                    else if ((direction == "left" || direction == "Left") && !IsEmpty(current->left))
                        current = current->left;
                    else if ((direction == "left" || direction == "Left") && IsEmpty(current->left))
                        std::cout << "Переход влево ведёт в пустоту\n";
                    else
                        std::cout << "Некорректное значение\n";
                }
                else if (direction == "disconnect")
                {
                    std::cout << "Какую ветвь хотите отсоединить? (left или right)\n";
                    std::cin >> direction;
                    if ((direction == "right" || direction == "Right") && !IsEmpty(current->right))
                        DetacheRightSubtree(current);
                    else if ((direction == "right" || direction == "Right") && IsEmpty(current->right))
                        std::cout << "Правая ветвь уже пуста!\n";
                    else if ((direction == "left" || direction == "Left") && !IsEmpty(current->left))
                        DetacheLeftSubtree(current);
                    else if ((direction == "left" || direction == "Left") && IsEmpty(current->left))
                        std::cout << "Левая ветвь уже пуста!\n";
                    else
                        std::cout << "Некорректное значение\n";
                }
                else if (direction == "No" || direction == "no")
                    current = nullptr;
                else
                    std::cout << "Некорректное значение\n";
                Print(current);

            }
            delete current;
            break;
        }
        case 4:
            PostOrder(root);
            break;
        case 5:
            InOrder(root);
            break;
        case 6:
            PrefOrder(root);
            break;
        case 7:
            Print(root);
            break;
        case 8:
            std::cout << "Максимальный элемент равен: " << MaxElement(root) << "\n";
            break;
        case 9:
            std::cout << "Количество максимальных элементов: " << CounterMaxElement(root) << "\n";
            break;

        }

    }

}
