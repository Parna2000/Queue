// doubly linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *createNode(int data)
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = data;
    head->next = NULL;
    head->prev = NULL;
    return head;
}

void traversal(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node *insertAtBeginning(struct node *head, int data)
{
    struct node *p = head;
    struct node *q = createNode(data);
    q->next = p;
    p->prev = q;
    p = q;
    return p;
}
struct node *insertAtEnd(struct node *head, int data)
{
    struct node *p = head;
    struct node *q = createNode(data);
    while (p->next != NULL)
    {
        p = p->next;
    }
    q->next = NULL;
    q->prev = p;
    p->next = q;
    return head;
}

struct node *insertAtPosition(struct node *head, int data, int pos)
{
    struct node *p = head;
    struct node *r = head->next;
    int i = 0;
    while (i < pos - 2)
    {
        p = p->next;
        r = r->next;
        i++;
    }
    struct node *q = createNode(data);
    q->next = p->next;
    q->prev = p;
    r->prev = q;
    p->next = q;
    return head;
}

struct node *deleteAtBeginning(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    q->prev = NULL;
    free(p);
    return q;
}

struct node *deleteAtEnd(struct node *head)
{
    struct node *p = head;
    struct node *q = p->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct node *deleteAtPosition(struct node *head, int pos)
{
    struct node *p = head;
    struct node *q = p->next;
    struct node *r = q->next;
    int i = 0;
    while (i < pos - 2)
    {
        p = p->next;
        q = q->next;
        r = r->next;
        i++;
    }
    p->next = q->next;
    r->prev = q->prev;
    free(q);
    return head;
}

int main()
{
    int data;
    printf("Enter the initial node:\n");
    scanf("%d", &data);
    struct node *head = createNode(data);
    printf("Select any one of the following choice\n1.Traverse the list\n2.Insert at beginning\n3.Insert at end\n4.Insert at a particular index\n5.Delete at beginning\n6.Delete at end\n7.Delete at a particular index\n8.Exit\n");
    while (1)
    {
        printf("Enter your choice:\n");
        int choice, val, pos;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("The list is\n");
            traversal(head);
            break;
        case 2:
            printf("Enter the element to be inserted\n");
            scanf("%d", &val);
            head = insertAtBeginning(head, val);
            printf("%d is inserted at beginning\n", val);
            break;
        case 3:
            printf("Enter the element to be inserted\n");
            scanf("%d", &val);
            head = insertAtEnd(head, val);
            printf("%d is inserted at the end\n", val);
            break;
        case 4:
            printf("Enter the element to be inserted\n");
            scanf("%d", &val);
            printf("Enter the position:\n");
            scanf("%d", &pos);
            head = insertAtPosition(head, val, pos);
            printf("%d is inserted at %dth position\n", val, pos);
            break;
        case 5:
            head = deleteAtBeginning(head);
            printf("The element at the beginning is deleted\n");
            break;
        case 6:
            head = deleteAtEnd(head);
            printf("The element at the end is deleted\n");
            break;
        case 7:
            printf("Enter the position:\n");
            scanf("%d", &pos);
            head = deleteAtPosition(head, pos);
            printf("The element at %dth position is deleted\n", pos);
            break;
        case 8:
            printf("Bye Bye!!\n");
            return 0;
        }
    }
    return 0;
}