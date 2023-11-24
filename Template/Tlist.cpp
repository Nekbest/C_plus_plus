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
			for (int i = 0; i < n; i++)
				if (index_massive[i] <= tail->index)
					DeleteValue(index_massive[i]);
	}

	void DeleteValue(int index)
	{
		if (!IsEmpty())
		{
			Node* current = head;
			while (current != nullptr && current->index != index)
				current = current->next;
			if (current->index == 0)
				current = DeleteHead();
			else if (current->index == tail->index)
				DeleteTail();
			else
			{
				Node* ptr = current;
				current = current->next;
				current->previos = ptr->previos;
				current = current->previos;
				current->next = ptr->next;
				current = current->next;
				delete ptr;
				Node* index_update = tail;
				while (index_update->index != index - 1)
				{
					index_update->index -= 1;
					index_update = index_update->previos;
				}
				index_update = nullptr;
				delete index_update;
			}
			current = nullptr;
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
		{
			while (current != nullptr)
			{
				out << current->element << " " << current->index << "\n";
				current = current->next;
			}
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
				if(index_massive[i] <= tail->index)
					ChangeValue(index_massive[i], mas_new_val[i]);
	}

	void ChangeValue(int index, Tvalue newvalue)
	{
		if (!IsEmpty())
		{
			Node* current = head;
			while (current != nullptr && current->index != index)
				current = current->next;
			if (current->index == index)
				current->element = newvalue;
			current = nullptr;
			delete current;
			}
		}

	Tvalue* SearchValue(int* index_massive, int n)
	{
		Tvalue* search_value = new Tvalue[n];
		if (!IsEmpty())
			for (int i = 0; i < n; i++)
				if (index_massive[i] <= tail->index)
					search_value[i] = SearchValue(index_massive[i]);
		return search_value;
	}

	Tvalue SearchValue(int index)
	{
		if (!IsEmpty())
		{
			Node* current = head;
			while (current != nullptr && current->index != index)
				current = current->next;
			if (current != nullptr)
				return current->element;
			current = nullptr;
			delete current;
		}
		return 0;
	}

};
