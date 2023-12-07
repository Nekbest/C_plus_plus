#include <iostream>

template<typename Tvalue>
class Tlist
{
private:
	struct Node
	{
		Tvalue element;
		Node* next = nullptr;
		Node* previos = nullptr;
		int index;
	};
	Node* head;
	Node* tail;
public:

	Tlist()
	{
		head = nullptr;
		tail = nullptr;
	}

	Tlist(Tvalue value)
	{
		AddHead(value);
	}

	~Tlist()
	{
		clear();
	}

	void AddHead(Tvalue value)
	{
		Node* newhead = new Node;
		newhead->element = value;
		newhead->previos = nullptr;
		newhead->next = head;
		newhead->index = 0;
		if (IsEmpty())
			head = tail = newhead;
		else
		{
			head->previos = newhead;
			head = newhead;
			Node* current = head->next;
			while (current != nullptr)
			{
				current->index = current->index + 1;
				current = current->next;
			}
		}
		newhead = nullptr;
		delete newhead;
	}

	Node* DeleteHead()
	{
		if (!IsEmpty())
		{
			Node* ptr = head;
			head = head->next;
			head->previos = nullptr;
			delete ptr;
		}
		Node* current = tail;
		while (current != nullptr)
		{
			current->index -= 1;
			current = current->previos;
		}
		return head;
	}


	void DeleteTail()
	{
		if (!IsEmpty())
		{
			Node* ptr = tail;
			tail = tail->previos;
			tail->next = nullptr;
			delete ptr;
		}
	}

	void DeleteValue(int* index_massive, int n)
	{
		if (!IsEmpty())
		{
			int index_now;
			for (int i = 0; i < n; i++)
			{
				index_now = index_massive[i];
				Node* current = head;
				while (index_now > -1 && index_now <= tail->index && current->index != index_now)
					current = current->next;
				if (index_now > -1 && index_now <= tail->index)
				{
					if (current == head)
					{
						Node* ptr = head;
						head = head->next;
						head->previos = nullptr;
						delete ptr;
					}
					else if (current == tail)
					{
						Node* ptr = tail;
						tail = tail->previos;
						tail->next = nullptr;
						delete ptr;
					}
					else
					{
						Node* ptr = current;
						current = current->next;
						current->previos = ptr->previos;
						current = current->previos;
						current->next = ptr->next;
						delete ptr;
						current = nullptr;
						delete current;
					}
				}
			}
		}

		if (!IsEmpty())
		{
			Node* current = head;
			int counter = 0;
			while (current != nullptr)
			{

				current->index = counter;
				counter += 1;
				current = current->next;
			}
			delete current;
		}
	}

	void AddHead(Tvalue* mas_value, int n)
	{
		for (int i = 0; i < n; i++)
			AddHead(mas_value[i]);
	}

	void AddTail(Tvalue* mas_value, int n)
	{
		if (!IsEmpty())
			for (int i = 0; i < n; i++)
				AddTail(mas_value[i]);
	}

	void AddTail(Tvalue value)
	{
		if (!IsEmpty())
		{
			Node* newtail = new Node;
			newtail->element = value;
			newtail->previos = tail;
			tail->next = newtail;
			tail = tail->next;
			tail->index = tail->previos->index + 1;
			newtail = nullptr;
			delete newtail;
		}
	}


	bool IsEmpty()
	{
		return (head == nullptr);
	}

	Node* GetHead()
	{
		return head;
	}

	friend std::ostream& operator <<(std::ostream& out, Tlist& list)
	{
		Node* current = list.GetHead();
		if (!(list.IsEmpty()))
			while (current != nullptr)
			{
				out << current->element << " " << current->index << "\n";
				current = current->next;
			}
		else
			out << "nullptr";
		current = nullptr;
		delete current;
		return out;
	}

	void clear()
	{
		if (!IsEmpty())
		{
			Node* current = tail;
			while (current != nullptr)
			{
				tail = tail->previos;
				delete current;
				current = tail;
			}
			head = nullptr;
			delete current;
			delete head;
			delete tail;
		}
	}

	void ChangeValue(int* index_massive, Tvalue* mas_new_val, int n)
	{
		if (!IsEmpty())
			for (int i = 0; i < n; i++)
				if (index_massive[i] <= tail->index)
				{
					Node* current = head;
					while (current != nullptr && current->index != index_massive[i])
						current = current->next;
					if (current->index == index_massive[i])
						current->element = mas_new_val[i];
					current = nullptr;
					delete current;
				}
	}

	Tvalue* SearchValue(int* index_massive, int n)
	{
		Tvalue* search_value = new Tvalue[n];
		if (!IsEmpty())
		{
			if (!IsEmpty())
				for (int i = 0; i < n; i++)
					if (index_massive[i] <= tail->index && index_massive[i] > -1)
					{
						Node* current = head;
						while (current != nullptr && current->index != index_massive[i])
							current = current->next;
						if (current != nullptr)
							search_value[i] = current->element;
						current = nullptr;
						delete current;
					}
		}
		return search_value;
	}

};
