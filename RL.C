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
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
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
    int a, b, c, d;
    printf("Enter root, right child, right-left child, extra node: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    struct Node *root = create(a);
    root->right = create(b);
    root->right->left = create(c);
    root->right->left->left = create(d);

    printf("Before rotation: ");
    inorder(root);

    root->right = rightRotate(root->right);
    root = leftRotate(root);

    printf("\nAfter RL Rotation: ");
    inorder(root);

    return 0;
}