#include <stdio.h>
#define MAX 100

int arr[MAX];
int top1 = -1;
int top2 = MAX;

void push1(int x)
{
    if (top1 + 1 == top2)
    {
        printf("Overflow\n");
        return;
    }
    arr[++top1] = x;
}

void push2(int x)
{
    if (top1 + 1 == top2)
    {
        printf("Overflow\n");
        return;
    }
    arr[--top2] = x;
}

int main()
{
    int choice, value;
    for (;;)
    {
        printf("\n1.Push Stack1\n2.Push Stack2\n3.Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 3)
            break;
        printf("Enter value: ");
        scanf("%d", &value);
        choice == 1 ? push1(value) : choice == 2 ? push2(value)
                                                 : printf("Invalid choice\n");
        printf("Stack1: ");
        for (int i = 0; i <= top1; i++)
            printf("%d ", arr[i]);
        printf("\nStack2: ");
        for (int i = MAX - 1; i >= top2; i--)
            printf("%d ", arr[i]);
    }
    return 0;
}