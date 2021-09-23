#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    else
        return 0;
}

int isFull(struct queue *q)
{
    if (q->r = q->size - 1)
    {
        return 1;
    }
    else
        return 0;
}

void enqueue(struct queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue overflow\n");
    }
    q->r++;
    q->arr[q->r] = data;
    printf("%d is enqueued\n",data);
}

void dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("Queue underflow\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
        printf("%d is dequeued\n", a);
    }
}

void queueTraversal(struct queue *q)
{
    for (int i = 0; i < q->r + 1; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 5;
    q->f = q->r = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));
    printf("1.Enqueue a number to the queue\n2.Dequeue a number from the queue\n3.List the elements of the queue\n4.Exit\n");
    while (1)
    {
        int data, choice;
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number to be enqueued:\n");
            scanf("%d", &data);
            enqueue(q, data);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            printf("All elements of the queue are:\n");
            queueTraversal(q);
            break;
        case 4:
            printf("Bye Bye!!\n");
            // break;
            return 0;
        }
    }
    printf("success\n");
    return 0;
}