#include "Header1.h"

Queue::Queue()
{
    head = tail = NULL;
}

Queue::Queue(const Queue& other)
{
    if (other.head == NULL)
    {
        head = tail = NULL;
        return;
    }
    Element* temp = other.head;
    while (temp != other.tail)
    {
        this->push(temp->number);
        temp = temp->prev;
    }
    this->push(temp->number);
}

Queue::Queue(Queue&& other)noexcept
{
    if (other.head == NULL)
    {
        head = tail = NULL;
        return;
    }
    head = other.head;
    tail = other.tail;
    other.head = other.tail = NULL;
}

Queue::~Queue()
{
    if (head == NULL) return;
    while (this->get_size() > 0)
    {
        this->pop();
    }
    head = tail = NULL;
}

void Queue::push(int element)
{
    Element* temp = new Element;
    temp->number = element;
    if (head != NULL)
    {
        temp->next = tail;
        temp->prev = head;
        tail->prev = temp;
        head->next = temp;
        tail = temp;
    }
    else temp->next = temp->prev = head = tail = temp;
}

int Queue::pop()
{
    if (head == tail)
    {
        if (head == NULL) return 0;
        int res = head->number;
        delete head;
        head = tail = NULL;
        return res;
    }
    int res = head->number;
    head = head->prev;
    delete head->next;
    head->next = tail;
    tail->prev = head;
    return res;
}

int Queue::peek()
{
    if (head == NULL) return 0;
    return head->number;
}

int Queue::get_size()
{
    int i = 0;
    Element* temp = tail;
    if (head == NULL) return 0;
    while (temp != head)
    {
        i++;
        temp = temp->next;
    }
    return i + 1;
}

Queue& Queue::operator=(const Queue& other)
{
    if (this == &other || other.head == NULL) return *this;
    Element* temp = other.head;
    while (temp != other.tail)
    {
        this->push(temp->number);
        temp = temp->prev;
    }
    this->push(temp->number);
    return *this;
}

Queue& Queue::operator=(Queue&& other)noexcept
{
    if (this == &other || other.head == NULL) return *this;
    head = other.head;
    tail = other.tail;
    other.head = other.tail = NULL;
    return *this;
}

int main()
{
    setlocale(LC_ALL, "ru");

    cout << "Выберите действие с очередью:" << endl;
    cout << "0. Выйти из программы" << endl;
    cout << "1. Вставить элемент в конец" << endl;
    cout << "2. Удалить и вывести головной элемент" << endl;
    cout << "3. Вывести головной элемент" << endl;
    cout << "4. Вывести длину очереди" << endl;
    cout << "5. Вывести все элементы очереди" << endl;
    cout << "6. Создать новую очередь с копированием и вывести ее элементы" << endl;
    cout << "7. Создать новую очередь с перемещением и вывести ее элементы" << endl;
    cout << "8. Копировать 1 очередь во 2 и вывести ее элементы" << endl;
    cout << "9. Копировать 1 очередь во 2 с перемещением и вывести ее элементы" << endl;

    Queue queue;
    int opt;
    cin >> opt;

    while (opt != 0)
    {
        switch (opt)
        {
        case 1:
        {
            int a;
            cout << "Введите число для вставки: ";
            cin >> a;
            queue.push(a);
            break;
        }   
        case 2:
        {
            cout << "Значение удаленного головного элемента: " << queue.pop() << endl;
            break;
        } 
        case 3:
        {
            cout << "Значение головного элемента: " << queue.peek() << endl;
            break;
        }
            
        case 4:
            cout << "Длина очереди: " << queue.get_size() << endl;
            break;
        case 5:
            cout << queue << endl;
            break;
        case 6:
        {
            Queue queue2 = queue;
            cout << queue2 << endl;
            break;
        }
        case 7:
        {
            Queue queue3 = move(queue);
            cout << queue3 << endl;
            break;
        }
        case 8:
        {
            Queue queue2;
            queue2 = queue;
            cout << queue2 << endl;
            break;
        }
        case 9:
        {
            Queue queue3;
            queue3 = move(queue);
            cout << queue3 << endl;
            break;
        }
        default:
            cout << "Введено недопустимое значение" << endl;
        }
        cin >> opt;
    }
    return 0;
}
