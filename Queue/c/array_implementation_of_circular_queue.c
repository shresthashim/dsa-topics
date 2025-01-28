#include <stdio.h>

#define MAX 1000

struct Queue
{
    int front, rear;
    int a[MAX];
};

void init(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

// Circular Queue

int enqueue(struct Queue *q, int x)
{
    if ((q->rear + 1) % MAX == q->front)
    {
        printf("Queue Overflow\n");
        return 0;
    }
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear = (q->rear + 1) % MAX;
        q->a[q->rear] = x;
        printf("%d enqueued into queue\n", x);
        return 1;
    }
}

int dequeue(struct Queue *q)
{
    if (q->front == -1)
    {
        printf("Queue Underflow\n");
        return 0;
    }
    else
    {
        int x = q->a[q->front];
        if (q->front == q->rear)
        {
            q->front = q->rear = -1;
        }
        else
        {
            q->front = (q->front + 1) % MAX;
        }
        return x;
    }
}

int peek(struct Queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is Empty\n");
        return 0;
    }
    else
    {
        int x = q->a[q->front];
        return x;
    }
}

int isEmpty(struct Queue *q)
{
    return q->front == -1;
}

int main()
{
    struct Queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("%d dequeued from queue\n", dequeue(&q));
    printf("Front item is %d\n", peek(&q));

    if (isEmpty(&q))
        printf("Queue is empty.\n");
    else
        printf("Queue is not empty.\n");

    return 0;
}
