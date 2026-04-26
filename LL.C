#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *create(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}

void inorder(struct Node *root)
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
    int a, b, c;
    printf("Enter root, left child, left-left child: ");
    scanf("%d %d %d", &a, &b, &c);

    struct Node *root = create(a);
    root->left = create(b);
    root->left->left = create(c);

    printf("Before rotation: ");
    inorder(root);

    root = rightRotate(root);

    printf("\nAfter LL (Right Rotation): ");
    inorder(root);

    return 0;
}