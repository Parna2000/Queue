// postOrder traversal
#include <stdlib.h>
#include <stdio.h>
#define max 10
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct stack
{
    int size;
    int top;
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

struct stack *createStack()
{
    struct stack *s = malloc(sizeof(struct stack));
    if (!s)
    {
        return NULL;
    }
    s->size = max;
    s->top = -1;
    s->arr = malloc(max * sizeof(struct node *));
    if (!s->arr)
    {
        return NULL;
    }
    return s;
}

int isEmpty(struct stack *s)
{
    return (s->top == -1);
}

int isFull(struct stack *s)
{
    return (s->top == s->size - 1);
}

void push(struct stack *s, struct node *root)
{
    if (isFull(s))
    {
        printf("Stack overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top] = root;
}

void pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow\n");
        return;
    }
    struct node *tree = s->arr[s->top];
    s->top--;
    // return tree;
}

struct node *top(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow\n");
        return NULL;
    }
    struct node *tree = s->arr[s->top];
    // s->top--;
    return tree;
}

void postOrder(struct node *root)
{
    struct node *previous = NULL;
    struct stack *s = createStack();
    do
    {
        while (root != NULL)
        {
            push(s, root);
            root = root->left;
        }
        while (root == NULL && !isEmpty(s))
        {
            root = top(s);
            if (root->right == NULL || root->right == previous)
            {
                printf("%d ", root->data);
                pop(s);
                previous = root;
                root = NULL;
            }
            else
            {
                root = root->right;
            }
        }
    } while (!isEmpty(s));
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
    printf("The preorder traversal of the given tree is:\n");
    postOrder(root);
    return 0;
}