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
        if ((rear + 1) % MAX == front)
        {
            cout << "Queue Overflow" << endl;
            return false;
        }
        else
        {
            if (front == -1)
                front = 0;
            rear = (rear + 1) % MAX;
            a[rear] = x;
            cout << x << " enqueued into queue" << endl;
            return true;
        }
    }

    int dequeue()
    {
        if (front == -1)
        {
            cout << "Queue Underflow" << endl;
            return 0;
        }
        else
        {
            int x = a[front];
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % MAX;
            }
            return x;
        }
    }

    int peek()
    {
        if (front == -1)
        {
            cout << "Queue is Empty" << endl;
            return 0;
        }
        else
        {
            return a[front];
        }
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
    cout << "Front item is " << q.peek() << endl;
    return 0;
}
