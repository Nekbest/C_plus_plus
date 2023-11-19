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
		if (IsEmpty())
			head = tail = newhead;
		else
		{
			head->previos = newhead;
			head = newhead;
		}
		newhead = nullptr;
		delete newhead;
	}

	void DeleteHead()
	{
		if (!IsEmpty())
		{
			Node* ptr = head;
			head = head->next;
			head->previos = nullptr;
			delete ptr;
		}
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

	void DeleteValue(Tvalue value)
	{

		if (!IsEmpty())
		{
			Node* current = head;
			while (current != nullptr && value != current->element)
				current = current->next;
			if (current != nullptr && current->element == value)
			{
				if (current == head)
				{
					DeleteHead();
				}
				else if (current == tail)
					DeleteTail();
				else
				{
					Node* ptr = current;
					current = current->next;
					current->previos = ptr->previos;
					current = current->previos;
					current->next = ptr->next;
					delete ptr;
				}
			}
			current = nullptr;
			delete current;
		}
	}

	void DeleteValue(Tvalue* mas_value, int n)
	{
		if (!IsEmpty())
			for (int i = 0; i < n; i++)
				DeleteValue(mas_value[i]);
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
				out << current->element << "\n";
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
	void ChangeValue(Tvalue* mas_val, Tvalue* mas_new_val, int n)
	{
		if (!IsEmpty())
			for (int i = 0; i < n; i++)
				ChangeValue(mas_val[i], mas_new_val[i]);
	}
	void ChangeValue(Tvalue value, Tvalue newvalue)
	{
		if (!IsEmpty())
		{
			Node* current = head;
			while (current != nullptr && current->element != value)
				current = current->next;
			if (current->element == value)
				current->element = newvalue;
			current = nullptr;
			delete current;
			}
		}

};
