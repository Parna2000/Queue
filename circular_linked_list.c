// circular linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createNode(int data)
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = data;
    head->next = head;
    return head;
}

int length(struct node *head)
{
    int count = 0;
    struct node *ptr = head;
    if (head == NULL)
    {
        return 0;
    }
    do
    {
        ptr = ptr->next;
        count++;
    } while (ptr != head);
    return count;
}

void traversal(struct node *head)
{
    struct node *ptr = head;
    if (head == NULL)
    {
        return;
    }
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}

struct node *insertAtBeginning(struct node *head, int data)
{
    struct node *p = head;
    struct node *q = createNode(data);
    q->next = p;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = q;
    return q;
}
struct node *insertAtEnd(struct node *head, int data)
{
    struct node *p = head;
    struct node *q = createNode(data);
    while (p->next != head)
    {
        p = p->next;
    }
    q->next = head;
    p->next = q;
    return head;
}

struct node *insertAtPosition(struct node *head, int data, int pos)
{
    struct node *p = head;
    int i = 0;
    while (i < pos - 2)
    {
        p = p->next;
        i++;
    }
    struct node *q = createNode(data);
    q->next = p->next;
    p->next = q;
    return head;
}

struct node *deleteAtBeginning(struct node *head)
{
    struct node *p = head;
    struct node *q = head;
    struct node *r = head;
    p = p->next;
    while (q->next != head)
    {
        q = q->next;
    }
    q->next=p;
    free(r);
    return p;
}

struct node *deleteAtEnd(struct node *head)
{
    struct node *p = head;
    struct node *q = p->next;
    while (q->next != head)
    {
        p = p->next;
        q = q->next;
    }
    p->next = head;
    free(q);
    return head;
}

struct node *deleteAtPosition(struct node *head, int pos)
{
    struct node *p = head;
    struct node *q = p->next;
    int i = 0;
    while (i < pos - 2)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}

int main()
{
    int data;
    printf("Enter the initial node:\n");
    scanf("%d", &data);
    struct node *head = NULL;
    printf("Select any one of the following choice\n1.Length of the list\n2.Insert at beginning\n3.Insert at end\n4.Insert at a particular index\n5.Delete at beginning\n6.Delete at end\n7.Delete at a particular index\n8.Traverse the list\n9.Exit\n");
    while (1)
    {
        printf("Enter your choice:\n");
        int choice, val, pos;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("The length of the list is: %d\n", length(head));
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
            printf("The list is\n");
            traversal(head);
            break;
        case 9:
            printf("Bye Bye!!\n");
            return 0;
        }
    }
    return 0;
}