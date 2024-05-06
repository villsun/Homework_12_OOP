#include <iostream>
#include <string>

using namespace std;

class Exception
{
private:
	string message;
public:
	Exception(string message) : message(message){}

	const string& what() const
	{
		return message;
	}
};

template <typename T>
class Queue
{
private:
	T* elements;
	int capacity;
	int first_index;
	int last_index;
public:
	Queue()
	{
		capacity = 5;
		first_index = 0;
		last_index = -1;
		elements = new T[capacity];
	}

	bool is_Empty() const
	{
		return last_index == -1;
	}

	bool is_Full() const
	{
		return last_index == capacity - 1;
	}
	
	void Resize(int new_capacity)
	{
		capacity = new_capacity;
		T* new_elements = new T[new_capacity];
		for (int i = first_index, j = 0; i <= last_index; i++, j++)
		{
			new_elements[j] = elements[i];
		}
		delete[] elements;
		elements = new_elements;
		last_index -= first_index;
		first_index = 0;
	}

	void Enqueue(const T value)
	{
		if (is_Full())
		{
			Resize(capacity * 2);
		}
		elements[++last_index] = value;
	}

	T Dequeue()
	{
		if (is_Empty())
		{
			throw Exception("Queue is empty!");
		}
		return elements[first_index++];
	}

	void Show()
	{
		if (is_Empty())
		{
			throw Exception("Queue is empty!");
		}
		for (int i = first_index; i <= last_index; i++)
		{
			cout << elements[i] << ' ';
		}
		cout << endl;
	}

	~Queue()
	{
		delete[] elements;
	}
};

int main()
{
	Queue<int> obj_1;
	try
	{
		/*obj_1.Show();
		cout << obj_1.Dequeue() << endl;
		cout << obj_1.is_Empty() << endl;*/
		obj_1.Enqueue(10);
		obj_1.Enqueue(20);
		obj_1.Enqueue(30);
		obj_1.Enqueue(40);
		obj_1.Enqueue(50);
		obj_1.Enqueue(60);
		cout << obj_1.is_Full() << endl;
		obj_1.Show();
	}
	catch (const Exception& exception)
	{
		cout << exception.what() << endl;
	}


	return 0;
}