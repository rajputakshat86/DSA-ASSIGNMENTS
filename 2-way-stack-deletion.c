#include <stdio.h>
#define MAX 100

int arr[MAX];
int top1 = -1;
int top2 = MAX;

void pop1()
{
    if (top1 == -1)
    {
        printf("Stack1 Underflow\n");
        return;
    }
    printf("Deleted from Stack1: %d\n", arr[top1--]);
}

void pop2()
{
    if (top2 == MAX)
    {
        printf("Stack2 Underflow\n");
        return;
    }
    printf("Deleted from Stack2: %d\n", arr[top2++]);
}

int main()
{
    int choice;
    for (;;)
    {
        printf("\n1.Pop Stack1\n2.Pop Stack2\n3.Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 3)
            break;
        choice == 1 ? pop1() : choice == 2 ? pop2()
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