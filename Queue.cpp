#include <iostream>
using namespace std;

#define SIZE 1000

class Queue
{
private:
    int *array;
    int front;
    int rear;
    int count;
    int capasity;

public:
    Queue(int size = SIZE);
    ~Queue();

    void enqueue(int number);
    void dequeue();
    void peek();
    int size();
    bool isEmpty();
    bool isFull();
    void viewQueue();
};

Queue::Queue(int size)
{
    array = new int[size];
    front = 0;
    rear = -1;
    count = 0;
    capasity = size;
}

Queue::~Queue()
{
    delete[] array;
}

void Queue::enqueue(int element)
{
    if (isFull())
    {
        cout << "Overflow";
        exit(EXIT_FAILURE);
    }

    rear = (rear + 1) % capasity;
    array[rear] = element;
    count++;
    viewQueue();
}
void Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Underflow";
        exit(EXIT_FAILURE);
    }
    cout << "popped elemet " << array[front];
    front = (front + 1) % capasity;
    count--;
    viewQueue();
}
void Queue::peek()
{
    if (isEmpty())
    {
        cout << "Under Flow";
        exit(EXIT_FAILURE);
    }

    cout << "Top Element " << array[front];
}
int Queue::size()
{
    return count;
}
bool Queue::isEmpty()
{
    return size() == 0;
}
bool Queue::isFull()
{
    return size() == capasity;
}

void Queue::viewQueue()
{
    cout << "\nCurrent Queue: ";
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        cout << array[i] << " ";
    }
}

int main()
{
    Queue q(5);
    int choosenOpration, number, exit;

    do
    {
        cout << "\n 1) Enqueue ";
        cout << "\n 2) Dequeue ";
        cout << "\n 3) Peek element ";
        cout << "\n 4) View Queue ";
        cout << "\n 5) Exit ";
        cout << "\n Which opration do you like to perform: ";

        cin >> choosenOpration;

        switch (choosenOpration)
        {
        case 1:
            cout << "Enter Element:";
            cin >> number;
            q.enqueue(number);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.peek();
            break;

        case 4:
            q.viewQueue();
            break;

        case 5:
            exit = 1;
            break;

        default:
            break;
        }
    } while (exit != 1);
}
