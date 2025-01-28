#include <iostream>

using namespace std;

#define MAX 1000

class Queue
{
    int front, rear;

public:
    int a[MAX];

    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool enqueue(int x)
    {
        if (rear >= MAX - 1)
        {
            cout << "Queue Overflow" << endl;
            return false;
        }
        else
        {
            a[++rear] = x;
            cout << x << " enqueued into queue" << endl;
            return true;
        }
    }

    int dequeue()
    {
        if (front == rear)
        {
            cout << "Queue Underflow" << endl;
            return 0;
        }
        else
        {
            int x = a[++front];
            return x;
        }
    }

    int peek()
    {
        if (front == rear)
        {
            cout << "Queue is Empty" << endl;
            return 0;
        }
        else
        {
            int x = a[front + 1];
            return x;
        }
    }

    bool isEmpty()
    {
        return front == rear;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << q.dequeue() << " dequeued from queue\n";
    cout << q.dequeue() << " dequeued from queue\n";
    cout << q.dequeue() << " dequeued from queue\n";

    cout << "Front item is " << q.peek() << endl;

    cout << "Queue is empty: " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}