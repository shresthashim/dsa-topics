#include <stdio.h>

#define MAX 1000

struct Stack
{
    int top;
    int a[MAX];
};

void init(struct Stack *s)
{
    s->top = -1;
}

int push(struct Stack *s, int x)
{
    if (s->top >= MAX - 1)
    {
        printf("Stack Overflow\n");
        return 0;
    }
    else
    {
        s->a[++s->top] = x;
        printf("%d pushed into stack\n", x);
        return 1;
    }
}

int pop(struct Stack *s)
{
    if (s->top < 0)
    {
        printf("Stack Underflow\n");
        return 0;
    }
    else
    {
        int x = s->a[s->top--];
        return x;
    }
}

int peek(struct Stack *s)
{
    if (s->top < 0)
    {
        printf("Stack is Empty\n");
        return 0;
    }
    else
    {
        int x = s->a[s->top];
        return x;
    }
}

int isEmpty(struct Stack *s)
{
    return s->top < 0;
}

void print(struct Stack *s)
{
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->a[i]);
    }
    printf("\n");
}

int main()
{
    struct Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    print(&s);

    printf("%d popped from stack\n", pop(&s));

    print(&s);

    printf("%d at the top of stack\n", peek(&s));

    printf("Stack is empty: %s\n", isEmpty(&s) ? "true" : "false");

    return 0;
}