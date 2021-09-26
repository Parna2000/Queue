// find the maximum element of a binary tree
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

int max(int a, int b, int c)
{
    int arr[3];
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    for (int i = 0; i < 2; i++)
    {
        int maxid = i;
        for (int j = i + 1; j < 3; j++)
        {
            if (arr[j] > arr[maxid])
            {
                maxid = j;
            }
        }
        if (maxid != i)
        {
            int temp = arr[maxid];
            arr[maxid] = arr[i];
            arr[i] = temp;
        }
    }
    return arr[0];
}

int maxElement(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root != NULL && root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    else
    {
        int l = maxElement(root->left);
        int r = maxElement(root->right);
        int m = max(l, r, root->data);
        return m;
    }
}

int main()
{
    struct node *root = createNode(23); /*            23          */
    struct node *r1 = createNode(20);   /*            /\          */
    struct node *r2 = createNode(25);   /*           20 25        */
    struct node *r3 = createNode(100);   /*           /\  /\       */
    struct node *r4 = createNode(21);   /*         18 21 24 26    */
    struct node *r5 = createNode(24);
    struct node *r6 = createNode(26);
    root->left = r1;
    root->right = r2;
    r1->left = r3;
    r1->right = r4;
    r2->left = r5;
    r2->right = r6;
    printf("The maximum element of the tree is: %d\n",maxElement(root));
    return 0;
}