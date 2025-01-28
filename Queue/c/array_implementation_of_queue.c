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

int enqueue(struct Queue *q, int x)
{
    if (q->rear >= MAX - 1)
    {
        printf("Queue Overflow\n");
        return 0;
    }
    else
    {
        q->a[++q->rear] = x;
        printf("%d enqueued into queue\n", x);
        return 1;
    }
}

int dequeue(struct Queue *q)
{
    if (q->front == q->rear)
    {
        printf("Queue Underflow\n");
        return 0;
    }
    else
    {
        int x = q->a[++q->front];
        return x;
    }
}

int peek(struct Queue *q)
{
    if (q->front == q->rear)
    {
        printf("Queue is Empty\n");
        return 0;
    }
    else
    {
        int x = q->a[q->front + 1];
        return x;
    }
}

int isEmpty(struct Queue *q)
{
    return q->front == q->rear;
}

int main()
{
    struct Queue q;
    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("%d dequeued from queue\n", dequeue(&q));
    printf("%d dequeued from queue\n", dequeue(&q));
    printf("%d dequeued from queue\n", dequeue(&q));
    printf("%d dequeued from queue\n", dequeue(&q));
    return 0;
}