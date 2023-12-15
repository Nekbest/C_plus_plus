#include <iostream>

template <typename Tvalue>
class Tarray
{
private:
	Tvalue* flexible_array;
	int size;
public:

	Tarray(int s)
	{
		size = s;
		flexible_array = new Tvalue[s];
		for (int i = 0; i < size; i++)
			flexible_array[i] = 0;
	}

	Tarray(Tvalue* massive, int s)
	{
		size = s;
		flexible_array = new Tvalue[s];
		for (int i = 0; i < size; i++)
			flexible_array[i] = massive[i];
	}

	Tarray(const Tarray<Tvalue>& other)
	{

		size = other.size;
		flexible_array = new Tvalue[size];
		for (int i = 0; i < size; ++i)
		{
			flexible_array[i] = other.flexible_array[i];
		}
	}

	~Tarray()
	{
		delete[] flexible_array;
		flexible_array = nullptr;
	}

	Tarray<Tvalue>& operator =(const Tarray<Tvalue>& other)
	{
		delete[] flexible_array;
		size = other.size;
		flexible_array = new Tvalue[size];
		for (int i = 0; i < size; ++i)
		{
			flexible_array[i] = other.flexible_array[i];
		}
	}

	void PushBegin(Tvalue* massive, int s)
	{
		if (!IsEmpty())
		{
			Tvalue* copy_array = new Tvalue[size];
			for (int i = 0; i < size; i++)
				copy_array[i] = flexible_array[i];
			delete[] flexible_array;
			size += s;
			flexible_array = new Tvalue[size];
			for (int i = 0; i < s; i++)
				flexible_array[i] = massive[i];
			for (int i = s; i < size; i++)
				flexible_array[i] = copy_array[i - s];
			delete[] copy_array;
		}
	}

	void PushEnd(Tvalue* massive, int s)
	{
		if (!IsEmpty())
		{
			Tvalue* copy_array = new Tvalue[size];
			for (int i = 0; i < size; i++)
				copy_array[i] = flexible_array[i];
			delete[] flexible_array;
			size += s;
			flexible_array = new Tvalue[size];
			for (int i = 0; i < size - s; i++)
				flexible_array[i] = copy_array[i];
			delete[] copy_array;
			for (int i = size - s; i < size; i++)
				flexible_array[i] = massive[i - (size - s)];
		}
	}

	void Push(int index_begin, int index_end, Tvalue* massive_element, int s)
	{
		if (!IsEmpty())
		{
			size = size + s;
			Tvalue* new_array = new Tvalue[size];
			int i = 0;
			int counter_1 = 0;
			int counter_2 = 0;
			while (i < size)
			{
				if (i < index_begin || i > index_end)
				{
					new_array[i] = flexible_array[counter_1];
					counter_1 += 1;
				}
				else
				{
					new_array[i] = massive_element[counter_2];
					counter_2 += 1;
				}
				i += 1;
			}
			delete[] flexible_array;
			flexible_array = new_array;
			new_array = nullptr;
			delete new_array; 
		}
	}

	void DeleteElement(int index_begin, int index_end)
	{
		if (!IsEmpty() && index_begin >= 0 && index_end < size)
		{
			int counter = 0;
			for (int i = 0; i < size; i++)
				if (i < index_begin || i > index_end)
					counter += 1;
			Tvalue* new_array = new Tvalue[counter];
			counter = 0;
			for (int i = 0; i < size; i++)
			{
				if (i < index_begin || i > index_end)
				{
					new_array[counter] = flexible_array[i];
					counter += 1;
				}
			}
			delete[] flexible_array;
			flexible_array = new_array;
			new_array = nullptr;
			delete[] new_array;
			size = counter;
		}
	}

	Tvalue* SearchValue(int index_begin, int index_end)
	{
		if (!IsEmpty() && index_begin >= 0 && index_end < size)
		{
			Tvalue* search_value = new Tvalue[index_end - index_begin];
			int counter = 0;
			for (int i = 0; i < size; i++)
				if (i >= index_begin && i <= index_end)
				{
					search_value[counter] = flexible_array[i];
					counter += 1;
				}
			return search_value;
		}
		return flexible_array;
	}

	void ReplacmentValue(int index_begin, int index_end, Tvalue* massive_element)
	{
		if (!IsEmpty() && index_begin >= 0 && index_end < size)
		{
			int counter = 0;
			for (int i = 0; i < size; i++)
				if (i >= index_begin && i <= index_end)
				{
					flexible_array[i] = massive_element[counter];
					counter += 1;
				}
		}
	}

	bool IsEmpty()
	{
		return (flexible_array == nullptr);
	}

	Tvalue* GetArray()
	{
		return flexible_array;
	}

	int GetSize()
	{
		return size;
	}

	friend std::ostream& operator <<(std::ostream& out, Tarray& tarray)
	{
		Tvalue* tray = tarray.GetArray();
		int size = tarray.GetSize();
		for (int i = 0; i < size; i++)
			out << tray[i] << " ";
		out << "\n";
		return out;
	}
	
	Tvalue operator[](const unsigned int& i)
	{
		return flexible_array[i];
	}
};
