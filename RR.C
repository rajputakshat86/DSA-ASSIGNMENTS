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

struct Node *leftRotate(struct Node *x)
{
    if (x == NULL || x->right == NULL)
        return x;

    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
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

    printf("Enter root, right child, right-right child: ");
    scanf("%d %d %d", &a, &b, &c);

    struct Node *root = create(a);
    root->right = create(b);
    root->right->right = create(c);

    printf("Before RR Rotation: ");
    inorder(root);

    if (root && root->right)
        root = leftRotate(root);

    printf("\nAfter RR Rotation: ");
    inorder(root);

    return 0;
}