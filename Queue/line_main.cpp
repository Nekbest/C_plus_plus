#include <iostream>
#include "line.h"

int main()
{
	setlocale(LC_ALL, "RU");
	Queue line_x, line_y;

	line_x.enqueue(10);
	line_x.enqueue(2);
	line_x.enqueue(7);
	line_x.enqueue(9);
	line_x.enqueue(15);
	line_y.enqueue(20);
	line_y.enqueue(1);
	line_y.enqueue(1);
	line_y.enqueue(9);
	line_y.enqueue(21);
	int x, y, counter = 0;
	while ((!line_x.is_empty()) && (!line_y.is_empty()))
	{
		x = line_x.peek();
		y = line_y.peek();
		line_x.dequeue();
		line_y.dequeue();
		if (x < y)
			line_x.enqueue(x + y);
		else
			line_y.enqueue(x - y);
		++counter;
		line_x.print();
		line_y.print();
		std::cout << "____________________________________________\n";
	}
	std::cout << "Шагов: " << counter << "\n";
	line_y.clear();
	line_y.print();
	return 0;
}
