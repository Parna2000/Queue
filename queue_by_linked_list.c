// linked list implementation of queue
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int QueueSize(struct node *head)
{
    int count = 0;
    struct node *ptr = head;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    return count;
}

struct node *enqueue(struct node *head, int data)
{
    // insertion at the end of the linked list
    struct node *p = head;
    struct node *q = (struct node *)malloc(sizeof(struct node));
    while (p->next != NULL)
    {
        p = p->next;
    }
    q->data = data;
    q->next = NULL;
    p->next = q;
    return head;
}

struct node *dequeue(struct node *head)
{
    // deletion at the beginning of the linked list
    struct node *p = head;
    struct node *q = head;
    int data = p->data;
    q = q->next;
    free(p);
    printf("%d is dequeued\n", data);
    return q;
}

void deleteQueue(struct node *head)
{
    struct node *p;
    while (head)
    {
        p = head;
        head = head->next;
        free(p);
    }
    free(head);
}

int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 24;
    head->next = NULL;
    printf("Choose any one of the following options:\n1.Enter elements into the queue\n2.Remove elements from the stack\n3.Get the length of the stack\n4.Exit\n");
    while (1)
    {
        int choice, data;
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted:\n");
            scanf("%d", &data);
            head = enqueue(head, data);
            printf("%d is enqueued\n", data);
            break;

        case 2:
            head = dequeue(head);
            break;
        case 3:
            printf("The length of the queue is: %d\n", QueueSize(head));
            break;
        case 4:
            printf("Bye Bye!!\n");
            return 0;
        }
    }
    return 0;
}