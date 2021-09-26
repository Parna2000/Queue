#include <stdlib.h>
#include <stdio.h>

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

int search(struct node *root, int data)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root != NULL && root->left == NULL && root->right == NULL)
    {
        if (root->data == data)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        int i = (search(root, data) || search(root->left, data) || search(root->right, data));
        return i;
    }
}

int main()
{
    struct node *root = createNode(23); /*            23          */
    struct node *r1 = createNode(20);   /*            /\          */
    struct node *r2 = createNode(25);   /*           20 25        */
    struct node *r3 = createNode(100);  /*           /\  /\       */
    struct node *r4 = createNode(21);   /*         18 21 24 26    */
    struct node *r5 = createNode(24);
    struct node *r6 = createNode(26);
    root->left = r1;
    root->right = r2;
    r1->left = r3;
    r1->right = r4;
    r2->left = r5;
    r2->right = r6;
    printf("Enter the element to be searched:\n");
    int n;
    scanf("%d", &n);
    if (search(root, n))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}