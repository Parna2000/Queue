// Transfer the elements of the queue to the stack so that the front element of the queue appears on the top of the stack.

#include <stdlib.h>
#include <stdio.h>
#define max 10
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
    return ((q->r + 1) % q->size==q->f);
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
            q->f=q->r=0;
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

int function(struct queue *q)
{
    if (queueIsEmpty(q))
    {
        printf("Queue is empty!!\n");
        return 0;
    }
    else
    {
        struct stack *s1 = createStack();
        struct stack *s2 = createStack();
        struct queue *q1 = createQueue();
        while (!queueIsEmpty(q))
        {
            push(s1, dequeue(q));
        }
        while (!stackIsEmpty(s1))
        {
            enqueue(q1, pop(s1));
        }
        while (!queueIsEmpty(q1))
        {
            push(s2, dequeue(q1));
        }
        return top(s2);
    }
}

int main()
{
    struct queue *q = createQueue();
    int n;
    printf("Enter the length of the queue (max length =10):\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the queue:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        enqueue(q, arr[i]);
    }
    printf("The given queue is:\n");
    printQueue(q);
    printf("The top element of the stack after transferring elements to the stack is: %d\n", function(q));
    return 0;
}