#include "stack_header.h"


AStack::AStack(const int maxsize)
{
	stack = new int[maxsize];
	top = -1;
	size = maxsize;
}


AStack::~AStack()
{
	delete[]stack;
}


void AStack::push(int element)
{
	if (top + 1 == size)
	{
		std::cout << "stack overflow\n";
	}
	else
	{
		top += 1;
		stack[top] = element;
	}
}


void AStack::pop()
{
	if (!isEmpty())
		top -= 1;
}


void AStack::print()
{
	if (!isEmpty())
	{
		for (int i = 0; i <= top; i++)
			std::cout << stack[i] << " ";
		std::cout << "\n";
	}
}


bool AStack::isEmpty()
{
	return top == -1;
}
