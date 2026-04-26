#include <stdio.h>
#define MAX 100

int arr[MAX];
int top1 = -1;
int top2 = MAX;

void display1()
{
    if (top1 == -1)
    {
        printf("Stack1 is empty\n");
        return;
    }
    for (int i = 0; i <= top1; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void display2()
{
    if (top2 == MAX)
    {
        printf("Stack2 is empty\n");
        return;
    }
    for (int i = MAX - 1; i >= top2; i--)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int choice;
    for (;;)
    {
        printf("\n1.Display Stack1\n2.Display Stack2\n3.Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 3)
            break;
        choice == 1 ? display1() : choice == 2 ? display2()
                                               : printf("Invalid choice\n");
    }
    return 0;
}