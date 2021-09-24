// implementation of queue using two stacks
#include <stdio.h>
#include <stdlib.h>
#define max 5
struct stack
{
    int stacksize;
    int top;
    int *sarr;
};
// struct queue{
//     int queuesize;
//     int f;
//     int r;
//     int*qarr;
// };
struct queue
{
    struct stack *s1;
    struct stack *s2;
};
struct stack *createStack()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    if (!s)
    {
        return NULL;
    }
    else
    {
        s->stacksize = max;
        s->top = -1;
        s->sarr = (int *)malloc(max * sizeof(int));
        if (!s->sarr)
        {
            return NULL;
        }
    }
    return s;
}
struct queue *createQueue()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    if (!q)
    {
        return NULL;
    }
    else
    {
        q->s1 = createStack();
        if (!q->s1)
        {
            return NULL;
        }
        q->s2 = createStack();
        if (!q->s2)
        {
            return NULL;
        }
    }
    return q;
}
int stackIsEmpty(struct stack *s)
{
    return (s->top == -1);
}
int stackIsFull(struct stack *s)
{
    return (s->top == s->stacksize - 1);
}
void push(struct stack *s, int data)
{
    if (stackIsFull(s))
    {
        printf("stack overflow\n");
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
        printf("stack underflow\n");
        return 0;
    }
    else
    {
        data = s->sarr[s->top];
        s->top--;
    }
    return data;
}
int queueIsEmpty(struct queue *q)
{
    return (stackIsEmpty(q->s1) && stackIsEmpty(q->s2));
}
int queueIsFull(struct queue *q)
{
    return (stackIsFull(q->s1) || stackIsFull(q->s2));
}
void enqueue(struct queue *q, int data)
{
    if (queueIsFull(q))
    {
        printf("queue overflow\n");
    }
    else
    {
        push(q->s1, data);
    }
}
int dequeue(struct queue *q)
{
    if (queueIsEmpty(q))
    {
        printf("queue underflow\n");
        return 0;
    }
    else
    {
        if (!stackIsEmpty(q->s2))
        {
            return pop(q->s2);
        }
        else
        {
            int data, i = 0;
            int n = q->s1->top;
            while (i != n)
            {
                push(q->s2, pop(q->s1));
                i++;
            }
            return pop(q->s1);
        }
    }
}
int stacksize(struct stack *s)
{
    return s->top + 1;
}
int QueueSize(struct queue *q)
{
    return (stacksize(q->s1) + stacksize(q->s2));
}

int main()
{
    struct queue *q = createQueue();
    printf("1.Add element to the queue\n2.Remove element from the queue\n3.Give the size of the queue\n4.Exit\n");
    while (1)
    {
        int choice, data;
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be added:\n");
            scanf("%d", &data);
            enqueue(q, data);
            printf("%d is enqueued\n", data);
            break;

        case 2:
            printf("The element dequeued is: %d\n", dequeue(q));
            break;

        case 3:
            printf("The size of the queue is: %d\n", QueueSize(q));
            break;
        case 4:
            printf("Bye Bye!!\n");
            return 0;
        }
    }
    return 0;
}