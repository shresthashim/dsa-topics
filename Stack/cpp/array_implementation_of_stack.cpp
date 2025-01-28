#include <iostream>

using namespace std;

#define MAX 1000

class Stack
{
    int top;

public:
    int a[MAX];
    Stack() { top = -1; }

    bool push(int x)
    {
        if (top >= MAX - 1)
        {
            cout << "Stack Overflow" << endl;
            return false;
        }
        else
        {
            a[++top] = x;
            cout << x << " pushed into stack" << endl;
            return true;
        }
    }

    int pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        else
        {
            int x = a[top--];
            return x;
        }
    }

    int peek()
    {
        if (top < 0)
        {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        else
        {
            int x = a[top];
            return x;
        }
    }

    bool isEmpty()
    {
        return top < 0;
    }

    void print()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.print();
    cout << s.pop() << " Popped from stack" << endl;
    cout << s.peek() << " is the top element" << endl;
    cout << s.isEmpty() << endl;
    s.print();
    return 0;
}
