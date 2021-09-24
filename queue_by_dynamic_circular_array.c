// implementation of queue by dynamic circular array
#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

struct queue *createQueue()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    if (!q)
        return NULL;
    q->size = 1;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    if (!q->arr)
        return NULL;
    return q;
}

int IsEmpty(struct queue *q)
{
    return (q->f == -1);
}
int IsFull(struct queue *q)
{
    return ((q->r + 1) % q->size == q->f);
}

int QueueSize(struct queue *q)
{
    return ((q->size - q->f + q->r + 1) % q->size);
}

void resize(struct queue *q)
{
    int max = q->size;
    q->size = q->size * 2;
    q->arr = realloc(q->arr, q->size);
    if (!q->arr)
    {
        printf("Memory error\n");
        return;
    }
    if (q->f > q->r)
    {
        for (int i = 0; i < q->f; i++)
        {
            q->arr[i + max] = q->arr[i];
        }
        q->r = q->r + max;
    }
}

void enqueue(struct queue *q, int data)
{
    if (IsFull(q))
    {
        resize(q);
    }
    q->r = (q->r + 1) % q->size;
    q->arr[q->r] = data;
    if (q->f == -1)
    {
        q->f = q->r;
    }
}
int dequeue(struct queue *q)
{
    int data = 0;
    if (IsEmpty(q))
    {
        printf("Stack underflow\n");
    }
    else
    {
        data = q->arr[q->f];
        if (q->f == q->r)
        {
            q->f = q->r = -1;
        }
        else
            q->f = (q->f + 1) % q->size;
    }
    return data;
}

void deleteQueue(struct queue *q)
{
    if (q)
    {
        if (q->arr)
        {
            free(q->arr);
        }
        free(q);
    }
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
    printf("success\n");
    return 0;
}