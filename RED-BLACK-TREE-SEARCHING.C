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

struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
        return create(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

int search(struct Node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
            return 1;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return 0;
}

int main()
{
    struct Node *root = NULL;
    int n, x, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    if (search(root, key))
        printf("Element Found\n");
    else
        printf("Element Not Found\n");

    return 0;
}