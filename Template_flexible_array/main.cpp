#include <iostream>
#include "Tarray.cpp"
int main()
{
	setlocale(LC_ALL, "RU");
	const int n = 5;
	int massive[n] = { 0, 1, 2, 3, 4 };
	int* pmassive = new int[n];
	for (int i = 0; i < n; i++)
		pmassive[i] = massive[i];
	Tarray <int> tarray(pmassive, n);
	std::cout << "Изначальный гибкий массив: " << tarray;
	int new_element[n] = { 5, 6, 7, 8, 9 };
	for (int i = 0; i < n; i++)
		pmassive[i] = new_element[i];
	tarray.PushBegin(pmassive, n);
	std::cout << "Результат PushBegin: " << tarray;
	tarray.PushEnd(pmassive, n);
	std::cout << "Результат PushEnd: " << tarray;
	for (int i = 0; i < n; i++)
		pmassive[i] = (i + 1) * 10;
	tarray.Push(5, 9, pmassive, n);
	std::cout << "Результат Push: " << tarray;
	tarray.DeleteElement(5, 9);
	std::cout << "Результат DeleteElement: " << tarray;
	int* search_value = tarray.SearchValue(5, 9);
	std::cout << "Результат SearchValue: ";
	for (int i = 0; i < 5; i++)
		std::cout << search_value[i] << " ";
	std::cout << "\n";
	tarray.ReplacmentValue(0, 4, search_value);
	std::cout << "Результат ReplacmentValue: " << tarray;
}

