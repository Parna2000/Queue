// implement stacks using queue

#include <stdio.h>
#include <stdlib.h>
#define max 5
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

struct stack
{
    struct queue *q1;
    struct queue *q2;
};

struct queue *createQueue()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    if (!q)
    {
        return NULL;
    }
    q->size = max;
    q->f = q->r = -1;
    q->arr = (int *)malloc(max * sizeof(int));
    if (!q->arr)
    {
        return NULL;
    }
    return q;
}

struct stack *createStack()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    if (!s)
    {
        return NULL;
    }
    s->q1 = createQueue();
    if (!s->q1)
    {
        return NULL;
    }
    s->q2 = createQueue();
    if (!s->q2)
    {
        return NULL;
    }
    return s;
}

int queueIsEmpty(struct queue *q)
{
    return (q->f == -1);
}

int queueIsFull(struct queue *q)
{
    return ((q->r + 1) % q->size == q->f);
}

int stackIsEmpty(struct stack *s)
{
    return (queueIsEmpty(s->q2) && queueIsEmpty(s->q1));
}

int stackIsFull(struct stack *s)
{
    return (queueIsFull(s->q1) || queueIsFull(s->q2));
}

void enqueue(struct queue *q, int data)
{
    if (queueIsFull(q))
    {
        // printf("Queue overflow\n");
        return;
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = data;
        if (q->f == -1)
        {
            q->f = q->r;
        }
    }
}

int dequeue(struct queue *q)
{
    if (queueIsEmpty(q))
    {
        // printf("Queue underflow\n");
        return 0;
    }
    else
    {
        int data;
        data = q->arr[q->f];
        if (q->f == q->r)
        {
            q->f = q->r = -1;
        }
        else
        {
            q->f = (q->f + 1) % q->size;
        }
        return data;
    }
}

void push(struct stack *s, int data)
{
    if (stackIsFull(s))
    {
        printf("Stack overflow\n");
    }
    else
    {
        if (queueIsEmpty(s->q1))
        {
            enqueue(s->q2, data);
        }
        else
        {
            enqueue(s->q1, data);
        }
    }
}

int pop(struct stack *s)
{
    if (stackIsEmpty(s))
    {
        printf("Stack underflow");
        return 0;
    }
    else
    {
        if (queueIsEmpty(s->q2))
        {
            for (int i = s->q1->f; i < s->q1->r; i++)
            {
                int data = dequeue(s->q1);
                enqueue(s->q2, data);
            }
            return dequeue(s->q1);
        }
        if (queueIsEmpty(s->q1))
        {
            for (int i = s->q2->f; i < s->q2->r; i++)
            {
                int data = dequeue(s->q2);
                enqueue(s->q1, data);
            }
            return dequeue(s->q2);
        }
    }
}

int main()
{
    struct stack *s = createStack();
    return 0;
}