// Reverse the queue

#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

struct stack
{
    int ssize;
    int top;
    int *sarr;
};

struct stack *
createStack(int data)
{
    struct stack *s = malloc(sizeof(struct stack));
    if (!s)
    {
        return NULL;
    }
    else
    {
        s->ssize = data;
        s->top = -1;
        s->sarr = (int *)malloc(s->ssize * sizeof(int));
        if (!s->sarr)
        {
            return NULL;
        }
    }
    return s;
}
int isEmptys(struct stack *s)
{
    return (s->top == -1);
}
int isFulls(struct stack *s)
{
    return (s->top == s->ssize - 1);
}
void push(struct stack *s, int data)
{
    if (isFulls(s))
    {
        printf("Stack overflow\n");
    }
    else
    {
        s->top++;
        s->sarr[s->top] = data;
    }
}

int pop(struct stack *s)
{
    int data = 0;
    if (isEmptys(s))
    {
        printf("Stack underflow\n");
    }
    else
    {
        data = s->sarr[s->top];
        s->top--;
    }
    return data;
}

struct queue *createQueue(int data)
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    if (!q)
    {
        return NULL;
    }
    else
    {
        q->size = data;
        q->r = q->f = -1;
        q->arr = (int *)malloc(q->size * sizeof(struct queue));
        if (!q->arr)
        {
            return NULL;
        }
    }
    return q;
}

int isEmptyq(struct queue *q)
{
    return (q->f == -1);
}

int isFullq(struct queue *q)
{
    return ((q->r + 1) % (q->size) == q->size);
}

void enqueue(struct queue *q, int data)
{
    if (isFullq(q))
    {
        printf("Queue overflow\n");
    }
    else
    {
        q->r = q->r + 1;
        q->arr[q->r] = data;
        if (q->f == -1)
        {
            q->f = q->r;
        }
    }
}

int dequeue(struct queue *q)
{
    int data = 0;
    if (isEmptyq(q))
    {
        printf("Queue underflow\n");
    }
    else
    {
        data = q->arr[q->f];
        if (q->f == q->r)
        {
            q->f = q->r = -1;
        }
        else
        {
            q->f = q->f + 1;
        }
    }
    return data;
}

int QueueSize(struct queue *q)
{
    return (q->size - q->f + q->r + 1) % q->size;
}

void reverseQueue(struct queue *q)
{
    struct stack *s = createStack(q->size);
    while (!isEmptyq(q))
    {
        push(s, dequeue(q));
    }
    while (!isEmptys(s))
    {
        enqueue(q, pop(s));
    }
}

int main()
{
    struct queue *q = createQueue(5);
    enqueue(q,23);
    enqueue(q,24);
    enqueue(q,25);
    enqueue(q,26);
    enqueue(q,27);
    reverseQueue(q);
    printf("The dequeued element is: %d\n",dequeue(q));
    return 0;
}