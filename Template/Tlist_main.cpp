#include <iostream>
#include "Tlist.cpp"
#include <string>

int main()
{
	int n = 20;
	std::string* string_massive = new std::string [n];
	for (int i = 0; i < n; i++)
		string_massive[i] = std::to_string(i);
	Tlist<std::string> list_1("- 1");
	list_1.AddTail(string_massive, n);
	std::cout << list_1;
	std::cout << "____________________________________\n";
	list_1.DeleteHead();
	list_1.DeleteTail();
	n = 16;
	std::string* del_str_massive = new std::string[n];
	for (int i = 10; i < n; i++)
		del_str_massive[i] = std::to_string(i);
	list_1.DeleteValue(del_str_massive, n);
	std::cout << list_1;
	std::cout << "____________________________________\n";
	n = 3;
	std::string* change = new std::string[n];
	std::string* new_string = new std::string[n];
	for (int i = 0; i < n; i++)
		change[i] = std::to_string(i + 16);
	for (int i = 0; i < n; i++)
		new_string[i] = std::to_string(i + 19);

	list_1.ChangeValue(change, new_string,  n);
	std::cout << list_1;
	std::cout << "____________________________________\n";

}
