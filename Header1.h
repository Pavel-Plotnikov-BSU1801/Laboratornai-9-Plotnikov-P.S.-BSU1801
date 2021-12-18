#include <iostream>
using namespace std;

struct Element
{
	int number;
	Element* next;
	Element* prev;
};

class Queue
{
	Element* head;
	Element* tail;
public:
	Queue();
	Queue(const Queue& other);
	Queue(Queue&& other)noexcept;
	~Queue();
	
	void push(int element);
	int pop();
	int peek();
	int get_size();

	Queue& operator=(const Queue& other);
	Queue& operator=(Queue&& other)noexcept;

	friend ostream &operator<<(ostream& stream, const Queue& that)
	{
		if (that.head == NULL) return stream << "Очередь пуста";
		Element* temp = that.head;
		while (temp != that.tail)
		{
			stream << temp->number << " ";
			temp = temp->prev;
		} 
		return stream << temp->number;
	}
};
