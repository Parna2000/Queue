#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void stackTraversal(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int isEmpty(struct node *head)
{
    if (head == NULL)
    {
        return 1;
    }
    else
        return 0;
}

int isFull(struct node *head)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        return 1;
    }
    else
        return 0;
}

struct node *push(struct node *head, int x)
{
    if (isFull(head))
    {
        printf("stack overflow\n");
        return NULL;
    }
    struct node *p = head;
    struct node *q = (struct node *)malloc(sizeof(struct node));
    // struct node*p=head;
    q->data = x;
    q->next = p;
    p = q;
    return p;
}

struct node *pop(struct node *head)
{
    if (isEmpty(head))
    {
        printf("stack underflow\n");
    }
    else
    {
        struct node *q = head;
        struct node *p = head;
        int x = p->data;
        p = p->next;
        free(q);
        printf("%d\n", x);
        return p;
    }
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 26;
    head->next = NULL;
    printf("1.Push element\n2.Pop element\n3.Print the stack\n4.Exit\n");
    while (1)
    {
        printf("Enter your choice:\n");
        int choice, num;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be pushed:\n");
            scanf("%d", &num);
            head = push(head, num);
            break;
        case 2:
            printf("The poped element(topmost element) is:\n");
            head = pop(head);
            break;
        case 3:
            printf("The elements of the stack are:\n");
            stackTraversal(head);
            break;
        case 4:
            printf("Bye Bye!!\n");
            return 0;
        }
    }
    printf("success\n");
    return 0;
}