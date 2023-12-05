#include <iostream>
#include <string>
#include "doubly_linked_list.h"
#include <fstream>

int main()
{
    setlocale(LC_ALL, "RU");
    Airport tickets[7] = {};
    std::ifstream file("Airtickets.txt");
    std::string day, month, year;
    for (int i = 0; i < 7; i++)
    {
        std::getline(file, tickets[i].destination, '\n');
        std::getline(file, tickets[i].flight_number, '\n');
        std::getline(file, tickets[i].aircraft_model, '\n');
        std::getline(file, tickets[i].full_name, '\n');
        std::getline(file, day, '\n');
        std::getline(file, month, '\n');
        std::getline(file, year, '\n');
        tickets[i].date.day = std::stoi(day);
        tickets[i].date.month = std::stoi(month);
        tickets[i].date.year = std::stoi(year);
    }
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 6; j++) {
            if (tickets[j].date.year > tickets[j + 1].date.year)
            {
                Airport b = tickets[j]; // создали дополнительную переменную
                tickets[j] = tickets[j + 1]; // меняем местами
                tickets[j + 1] = b; // значения элементов
            }
            else if (tickets[j].date.year == tickets[j + 1].date.year &&
                tickets[j].date.month > tickets[j + 1].date.month)
            {
                Airport b = tickets[j]; // создали дополнительную переменную
                tickets[j] = tickets[j + 1]; // меняем местами
                tickets[j + 1] = b; // значения элементов
            }
            else if (tickets[j].date.year == tickets[j + 1].date.year &&
                tickets[j].date.month == tickets[j + 1].date.month &&
                tickets[j].date.day > tickets[j + 1].date.day)
            {
                Airport b = tickets[j]; // создали дополнительную переменную
                tickets[j] = tickets[j + 1]; // меняем местами
                tickets[j + 1] = b; // значения элементов
            }

        }
    }
    file.close();
    Node* list = nullptr;
    Node* tail = nullptr;
    add_to_head(list, tail, tickets[0]);

    for (int i = 1; i < 7; i++)
        add_to_end(list, tail, tickets[i]);
    print_with_begin(list);
    Date date_delete;
    date_delete.year = 2023;
    date_delete.month = 12;
    date_delete.day = 6;
    delete_search_value(list, tail, date_delete);
    std::cout << "_______________________________\n";
    print_with_begin(list);
}
