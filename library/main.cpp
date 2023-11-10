#include <iostream>
#include <string>
#include <fstream>
#include "doubly_linked_list.h"


int main()
{
    setlocale(LC_ALL, "RU");
    library libr[8] = {};
    std::ifstream file("test.txt");
    std::string year, number_page;
    for (int i = 0; i < 8; i++)
    {
        std::getline(file, libr[i].author, '\n');
        std::getline(file, libr[i].name, '\n');
        std::getline(file, number_page, '\n');
        std::getline(file, year, '\n');
        libr[i].year_publication = std::stoi(year);
        libr[i].number_page = std::stoi(number_page);
        std::getline(file, libr[i].specialization, '\n');
    }
    file.close();
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 7; j++) {
            if (libr[j].year_publication > libr[j + 1].year_publication) 
{
                library b = libr[j]; // создали дополнительную переменную
                libr[j] = libr[j + 1]; // меняем местами
                libr[j + 1] = b; // значения элементов
            }
            }
        }

    Node* list = nullptr;
    Node* tail = nullptr;
    add_to_head(list, tail, libr[0]);
    add_to_end(list, tail, libr[1]);
    add_to_end(list, tail, libr[2]);
    add_to_end(list, tail, libr[3]);
    add_to_end(list, tail, libr[4]);
    add_to_end(list, tail, libr[5]);
    add_to_end(list, tail, libr[6]);
    add_to_end(list, tail, libr[7]);
    print_with_begin(list);
    std::cout << "__________________" << "\n";
    delete_search_value(list, tail, 2009); // void
    print_with_begin(list);


}
