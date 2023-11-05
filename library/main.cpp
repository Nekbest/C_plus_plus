#include <iostream>
#include "doubly_linked_list.h"
#include <string>


int main()
{
    setlocale(LC_ALL, "RU");
    library libr[8] = {};
    libr[0].author = "Дэниел Киз";
    libr[0].name = "Таинственная история Билли Миллигана";
    libr[0].year_publication = 1981;
    libr[0].number_page = 500;
    libr[0].specialization = "Зарубежная классика";
    libr[1].author = "Михаил Шолохов";
    libr[1].name = "Судьба человека";
    libr[1].year_publication = 1956;
    libr[1].number_page = 160;
    libr[1].specialization = "Русская классика";
    libr[2].author = "Рик Риордан";
    libr[2].name = "Перси Джексон и Олимпийцы";
    libr[2].year_publication = 2005;
    libr[2].number_page = 300;
    libr[2].specialization = "Зарубежное";
    libr[3].author = "Рик Риордан";
    libr[3].name = "Перси Джексон и проклятие титана";
    libr[3].year_publication = 2007;
    libr[3].number_page = 300;
    libr[3].specialization = "Зарубежное";
    libr[4].author = "Рик Риордан";
    libr[4].name = "Перси Джексон и лабиринт смерти";
    libr[4].year_publication = 2020;
    libr[4].number_page = 300;
    libr[4].specialization = "Зарубежное";
    libr[5].author = "Рик Риордан";
    libr[5].name = "Перси Джексон и Похититель молний";
    libr[5].year_publication = 2005;
    libr[5].number_page = 300;
    libr[5].specialization = "Зарубежное";
    libr[6].author = "Рик Риордан";
    libr[6].name = "Перси Джексон и Море чудовищ";
    libr[6].year_publication = 2006;
    libr[6].number_page = 300;
    libr[6].specialization = "Зарубежное";
    libr[7].author = "Рик Риордан";
    libr[7].name = "Перси Джексон и Последнее пророчество";
    libr[7].year_publication = 2009;
    libr[7].number_page = 300;
    libr[7].specialization = "Зарубежное";

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
    std::cout << "______________________________________________________________________________" << "\n";
    delete_search_value(list, tail, 2009); // void
    print_with_begin(list);


}
