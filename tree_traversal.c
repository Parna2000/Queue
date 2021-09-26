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

void preorder(struct node *root)
{
    if (root)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void inorder(struct node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
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
    printf("Choose any one of the following:\n1.Preorder Traversal\n2.Inorder Traversal\n3.Postorder Traversal\n4.Exit\n");
    while (1)
    {
        int choice;
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("The preorder traversal of the above tree is:\n");
            preorder(root);
            printf("\n");
            break;
        case 2:
            printf("The inorder traversal of the above tree is:\n");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("The postorder traversal of the above tree is:\n");
            postorder(root);
            printf("\n");
            break;
        case 4:
            printf("Bye Bye!!\n");
            return 0;
        }
    }
    return 0;
}