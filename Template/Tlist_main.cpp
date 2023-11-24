#include <iostream>
#include "Tlist.cpp"
#include <string>

int main()
{
	int* int_massive = new int [10];
	for (int i = 0; i < 10; i++)
		int_massive[i] = i;
	Tlist<int> list_1(-1);
	list_1.AddTail(int_massive, 10);
	list_1.DeleteHead();
	list_1.DeleteTail();
	std::cout << list_1;
	std::cout << "____________________________________\n";
	int* delete_value = new int[3];
	for (int i = 0; i < 3; i++)
	{
		delete_value[i] = i + 2;
	}
	list_1.DeleteValue(delete_value, 3);
	std::cout << list_1;
	std::cout << "____________________________________\n";;
	int* new_value = new int[4];
	int* index = new int[4];
	for (int i = 0; i < 4; i++)
	{
		new_value[i] = i + 2;
		index[i] = i + 2;
	}
	list_1.ChangeValue(index, new_value, 4);
	std::cout << list_1;
	std::cout << "____________________________________\n";
	int* index_1 = new int[2];
	for (int i = 0; i < 2; i++)
		index_1[i] = i + 2;
	int* search_value = list_1.SearchValue(index, 2);
	for (int i = 0; i < 2; i++)
		std::cout << search_value[i] << " ";
	std::cout << "\n";

}
