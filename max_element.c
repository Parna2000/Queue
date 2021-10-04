// findthe maximum element of a binary tree

#include <stdlib.h>
#include <stdio.h>
#define max 10
struct node
{
    int data;
    struct node *left;
    struct node *right;
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

int maxElement(struct node *root)
{
    int m = 0, left, right, root_val;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        root_val = root->data;
        left = maxElement(root->left);
        right = maxElement(root->right);
        if (left > right)
        {
            m = left;
        }
        else
            m = right;
        if (root_val > m)
            m = root_val;
        return m;
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
    printf("The maximum element of the given tree is: %d\n", maxElement(root));
    return 0;
}