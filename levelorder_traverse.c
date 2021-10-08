// level order traversal of a tree
#include <stdio.h>
#include <stdlib.h>
#define max 20
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
}

struct queue *craeteQueue()
{
    struct queue *q = malloc(sizeof(struct queue));
    if (!q)
    {
        return NULL;
    }
    q->size = max;
    q->f = -1;
    q->r = -1;
    q->arr = malloc(max * sizeof(struct node *));
}

int isEmpty(struct queue *q)
{
    return (q->f == -1);
}

int isFull(struct queue *q)
{
    return ((q->r + 1) % q->size == q->f);
}

void EnQueue(struct queue *q, struct node *root)
{
    if (isFull(q))
    {
        printf("Queue overflow!!\n");
        return;
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = root;
        if (q->f == -1)
            q->f = q->r;
    }
}

struct node *DeQueue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow!!\n");
        return NULL;
    }
    else
    {
        struct node *root = q->arr[q->f];
        if (q->r == q->f)
        {
            q->r = q->f = -1;
        }
        else
        {
            q->f = (q->f + 1) % q->size;
        }
        return root;
    }
}

void levelOrder(struct node *root)
{
    if (!root)
    {
        return;
    }
    struct queue *q = craeteQueue();
    struct node *temp = NULL;
    EnQueue(q, root);
    while (!isEmpty(q))
    {
        temp = DeQueue(q);
        printf("%d ", temp->data);
        if(temp->left)
        EnQueue(q, temp->left);
        if(temp->right)
        EnQueue(q, temp->right);
    }
    printf("\n");
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
    printf("The level order traversal of the tree is:\n");
    levelOrder(root);
    return 0;
}