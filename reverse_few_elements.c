// Reverse the first k elements of the queue and leave the rest elements as it is.

#include <stdlib.h>
#include <stdio.h>
#define max 20
struct queue
{
    int size;
    int f;
    int r;
    int *qarr;
};
struct stack
{
    int top;
    int capacity;
    int *sarr;
};

struct stack *createStack()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    if (!s)
    {
        return NULL;
    }
    s->capacity = max;
    s->top = -1;
    s->sarr = (int *)malloc(max * sizeof(int));
    if (!s->sarr)
    {
        return NULL;
    }
    return s;
}

int stackIsEmpty(struct stack *s)
{
    return (s->top == -1);
}

int stackIsFull(struct stack *s)
{
    return (s->top == s->capacity - 1);
}

void push(struct stack *s, int data)
{
    if (stackIsFull(s))
    {
        printf("Stack Overflow!!\n");
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
    if (stackIsEmpty(s))
    {
        printf("Stack underflow!!\n");
        return 0;
    }
    else
    {
        data = s->sarr[s->top];
        s->top--;
        return data;
    }
}

int peek(struct stack *s, int id)
{
    return s->sarr[id];
}

void printStack(struct stack *s)
{
    if (stackIsEmpty(s))
    {
        printf("Stack is Empty!!\n");
        return;
    }
    else
    {
        for (int i = 0; i <= s->top; i++)
        {
            printf("%d ", peek(s, i));
        }
        printf("\n");
    }
}

int top(struct stack *s)
{
    return s->sarr[s->top];
}

struct queue *createQueue()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    if (!q)
    {
        return NULL;
    }
    q->size = max;
    q->f = -1;
    q->r = -1;
    q->qarr = (int *)malloc(max * sizeof(int));
    if (!q->qarr)
    {
        return NULL;
    }
    return q;
}

int queueIsEmpty(struct queue *q)
{
    return (q->f == -1);
}

int queueIsFull(struct queue *q)
{
    return ((q->r + 1) % q->size == q->f);
}

void enqueue(struct queue *q, int data)
{
    if (queueIsFull(q))
    {
        printf("Queue overflow!!\n");
    }
    else
    {
        if (q->f == -1)
        {
            q->f = q->r = 0;
            // q->r++;
            q->qarr[q->f] = data;
        }
        else
        {
            q->r = (q->r + 1) % q->size;
            q->qarr[q->r] = data;
        }
    }
}

int dequeue(struct queue *q)
{
    int data = 0;
    if (queueIsEmpty(q))
    {
        printf("Queue underflow!!\n");
        return 0;
    }
    else
    {
        if (q->f == q->r)
        {
            data = q->qarr[q->f];
            q->f = q->r = -1;
        }
        else
        {
            data = q->qarr[q->f];
            q->f = (q->f + 1) % q->size;
        }
        return data;
    }
}

void printQueue(struct queue *q)
{
    if (queueIsEmpty(q))
    {
        printf("Queue is Empty!!\n");
    }
    else
    {
        for (int i = q->f; i <= q->r; i++)
        {
            printf("%d ", q->qarr[i]);
        }
        printf("\n");
    }
}

int sizeOfQueue(struct queue *q)
{
    if (q->f == -1)
    {
        return 0;
    }
    else if (q->f == q->r)
    {
        return 1;
    }
    else
    {
        return (q->size - q->f + q->r + 1) % q->size;
    }
}

void function(struct queue *q, int k)
{
    if (queueIsEmpty(q))
    {
        return;
    }
    else
    {
        struct stack *s1 = createStack();
        struct stack *s2 = createStack();
        struct stack *s3 = createStack();
        int t = 0;
        while (t < k)
        {
            push(s1, dequeue(q));
            t++;
        }
        while (!queueIsEmpty(q))
        {
            push(s2, dequeue(q));
        }
        while (!stackIsEmpty(s2))
        {
            push(s3, pop(s2));
        }
        while (!stackIsEmpty(s1))
        {
            enqueue(q, pop(s1));
        }
        while (!stackIsEmpty(s3))
        {
            enqueue(q, pop(s3));
        }
        printQueue(q);
    }
}

int main()
{
    struct queue *q = createQueue();
    int n, k;
    printf("Enter the length of the queue (max length <20):\n");
    scanf("%d", &n);
    printf("Enter the value of k:\n");
    scanf("%d", &k);
    int arr[n];
    printf("Enter the elements of the queue:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        enqueue(q, arr[i]);
    }
    printf("The given queue is:\n");
    printQueue(q);
    printf("After reversing the first %d elements, the queue becomes:\n", k);
    function(q, k);
    return 0;
}