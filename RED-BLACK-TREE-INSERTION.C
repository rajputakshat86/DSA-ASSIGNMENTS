#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data, color;
    struct Node *left, *right, *parent;
};

struct Node *root, *NIL;

struct Node *newNode(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->color = 1;
    n->left = n->right = n->parent = NIL;
    return n;
}

void leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    x->right = y->left;
    if (y->left != NIL)
        y->left->parent = x;
    y->parent = x->parent;

    if (x->parent == NIL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    y->left = x->right;
    if (x->right != NIL)
        x->right->parent = y;
    x->parent = y->parent;

    if (y->parent == NIL)
        root = x;
    else if (y == y->parent->right)
        y->parent->right = x;
    else
        y->parent->left = x;

    x->right = y;
    y->parent = x;
}

void fixInsert(struct Node *z)
{
    while (z->parent->color == 1)
    {
        struct Node *y;
        if (z->parent == z->parent->parent->left)
        {
            y = z->parent->parent->right;
            if (y->color == 1)
            {
                z->parent->color = y->color = 0;
                z->parent->parent->color = 1;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->right)
                {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = 0;
                z->parent->parent->color = 1;
                rightRotate(z->parent->parent);
            }
        }
        else
        {
            y = z->parent->parent->left;
            if (y->color == 1)
            {
                z->parent->color = y->color = 0;
                z->parent->parent->color = 1;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = 0;
                z->parent->parent->color = 1;
                leftRotate(z->parent->parent);
            }
        }
    }
    root->color = 0;
}

void insert(int data)
{
    struct Node *z = newNode(data), *y = NIL, *x = root;

    while (x != NIL)
    {
        y = x;
        if (data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if (y == NIL)
        root = z;
    else if (data < y->data)
        y->left = z;
    else
        y->right = z;

    fixInsert(z);
}

void inorder(struct Node *r)
{
    if (r != NIL)
    {
        inorder(r->left);
        printf("%d(%c) ", r->data, r->color ? 'R' : 'B');
        inorder(r->right);
    }
}

int main()
{
    NIL = (struct Node *)malloc(sizeof(struct Node));
    NIL->color = 0;
    root = NIL;

    int n, x;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insert(x);
    }

    inorder(root);
}