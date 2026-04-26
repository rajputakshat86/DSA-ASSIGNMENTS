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
    if (!root)
        return create(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

struct Node *minValueNode(struct Node *node)
{
    while (node->left)
        node = node->left;
    return node;
}

struct Node *deleteNode(struct Node *root, int key)
{
    if (!root)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else
    {
        if (!root->left)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (!root->right)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
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
    struct Node *root = NULL;
    int n, x, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Enter element to delete: ");
    scanf("%d", &key);

    root = deleteNode(root, key);

    printf("After deletion:\n");
    inorder(root);

    return 0;
}