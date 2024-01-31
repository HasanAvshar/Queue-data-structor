#include <iostream>
#include <cassert>
using namespace std;


template<typename T>
class SimpleQueue
{
	T* _arr;
	int _front;
	int _rear;
	int _max;
public:
	SimpleQueue(int max)
	{
		if (max <= 0 || max >= 1001)
			assert(!"Minimum1 maksimum 1000  ola biler");

		_max = max;
		_front = -1;
		_rear = -1;
		_arr = new T[_max];
	}

	bool IsFull()
	{
		return _rear == _max - 1;
	}

	bool IsEmpty()
	{
		return _front == -1;
	}


	void EnQueue(T item)
	{
		if (IsFull())
			assert(!"Qeueu is Full");

		if (_front == -1)
			_front = 0;

		_rear++;
		_arr[_rear] = item;
	}


	void DeQueue()
	{
		if (IsEmpty())
			assert(!"Qeueu is Empty");

		if (_front == _rear)
		{
			_front = -1;
			_rear = -1;
			return;
		}
		_front++;
	}


	T Peek()
	{
		if (IsEmpty())
			assert(!"Qeueu is Empty");

		return _arr[_front];
	}

	T Size()
	{
		if (IsEmpty()) return 0;

		return _rear - _front + 1;
	}


	void Print()
	{
		if (IsEmpty())
		{
			cout << "[]" << endl;
			return;
		}

		cout << "[";
		for (size_t i = _front; i <= _rear; i++)
		{
			cout << _arr[i];
			if (i != _rear)
				cout << ", ";
		}
		cout << "]" << endl;
	}

	template <typename T>
	friend ostream& operator<<(ostream& print, const SimpleQueue<T>& other);

	~SimpleQueue() {
		if (_arr != nullptr) delete[] _arr;
	}
};

template <typename T>
ostream& operator<<(ostream& print, const SimpleQueue<T>& other)
{
	print << "[";
	for (size_t i = other._front; i <= other._rear; i++)
	{
		print << other._arr[i];
		if (i != other._rear)
			print << ", ";
	}
	print << "]" << endl;
	return print;
}
void main()
{

	SimpleQueue<int> queue(5);

	queue.Print();

	queue.EnQueue(1);
	queue.EnQueue(2);
	queue.EnQueue(3);
	queue.EnQueue(4);
	queue.EnQueue(5);
	//queue.EnQueue(5);

	queue.Print();

	queue.DeQueue();
	queue.DeQueue();
	queue.DeQueue();

	cout << queue;

}