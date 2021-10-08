// insertion in a tree
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct queue
{
    int size;
    int f;
    int r;
    struct node **arr;
};
struct node *createNode(int data)
{
    struct node *root = malloc(sizeof(struct node));
    if (!root)
    {
        return NULL;
    }
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}
struct queue *createQueue()
{
    struct queue *q = malloc(sizeof(struct queue));
    if (!q)
    {
        return NULL;
    }
    q->size = 20;
    q->f = -1;
    q->r = -1;
    q->arr = malloc(q->size * sizeof(struct node *));
    return q;
}
int isEmpty(struct queue *q)
{
    return (q->f == -1);
}
int isFull(struct queue *q)
{
    return (q->r + 1) % q->size == q->f;
}
void EnQueue(struct queue *q, struct node *root)
{
    if (isFull(q))
    {
        return;
    }
    q->r = (q->r + 1) % q->size;
    q->arr[q->r] = root;
    if (q->f == -1)
    {
        q->f = q->r;
    }
}
struct node *DeQueue(struct queue *q)
{
    if (isEmpty(q))
    {
        return NULL;
    }
    struct node *root = q->arr[q->f];
    if (q->f == q->r)
    {
        q->f = q->r = -1;
    }
    else
        q->f = (q->f + 1) % q->size;
    return root;
}
void printtree(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        struct queue *q = createQueue();
        struct node *temp = NULL;
        EnQueue(q, root);
        while (!isEmpty(q))
        {
            temp = DeQueue(q);
            printf("%d ", temp->data);
            if (temp->left)
            {
                EnQueue(q, temp->left);
            }
            if (temp->right)
            {
                EnQueue(q, temp->right);
            }
        }
        printf("\n");
    }
}
void insert(struct node *root, int data)
{
    struct node *new = createNode(data);
    if (root == NULL)
    {
        root = new;
        return;
    }
    else
    {
        struct queue *q = createQueue();
        struct node *temp = NULL;
        EnQueue(q, root);
        while (!isEmpty(q))
        {
            temp = DeQueue(q);
            if (temp->left)
            {
                EnQueue(q, temp->left);
            }
            else
            {
                temp->left = new;
                return;
            }
            if (temp->right)
            {
                EnQueue(q, temp->right);
            }
            else
            {
                temp->right = new;
                return;
            }
        }
    }
}
int main()
{
    // struct node *root = (struct node *)malloc(sizeof(struct node));
    struct node *root = createNode(23); /*           23          */
    struct node *r1 = createNode(20);   /*           /\          */
    struct node *r2 = createNode(25);   /*          20 25        */
    struct node *r3 = createNode(18);   /*          /\  /\       */
    struct node *r4 = createNode(21);   /*         18 21 24 26   */
    struct node *r5 = createNode(24);
    struct node *r6 = createNode(26);
    root->left = r1;
    root->right = r2;
    r1->left = r3;
    r1->right = r4;
    r2->left = r5;
    r2->right = r6;
    printf("The tree is:\n");
    printtree(root);
    int data;
    printf("Enter the number to be inserted:\n");
    scanf("%d", &data);
    insert(root, data);
    printf("The new tree is:\n");
    printtree(root);
    return 0;
}