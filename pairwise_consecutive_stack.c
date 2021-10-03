// Check whether each successive pair of numbers in the stack is consecutive or not.

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

int absolute(int a, int b)
{
    if (a > b)
    {
        return (a - b);
    }
    else
    {
        return (b - a);
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

int function(struct stack *s)
{
    if (stackIsEmpty(s))
    {
        return 0;
    }
    else
    {
        struct queue *q = createQueue();
        while (!stackIsEmpty(s))
        {
            enqueue(q, pop(s));
        }
        while (!queueIsEmpty(q))
        {
            push(s, dequeue(q));
        }
        while (!stackIsEmpty(s))
        {
            int p = pop(s);
            enqueue(q, p);
            if (!stackIsEmpty(s))
            {
                int r = pop(s);
                enqueue(q, r);
                if (absolute(p, r) != 1)
                {
                    return 0;
                }
            }
        }
        while (!queueIsEmpty(q))
        {
            push(s, dequeue(q));
        }
        return 1;
    }
}

int main()
{
    struct stack *s = createStack();
    int n;
    printf("Enter the length of the stack (max length =10):\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the stack:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        push(s, arr[i]);
    }
    printf("The given stack is:\n");
    printStack(s);
    if (function(s))
    {
        printf("All the elements are pairwise consecutive\n");
    }
    else
    {
        printf("Ooops!! Not all elements are pairwise consecutive\n");
    }
    return 0;
}