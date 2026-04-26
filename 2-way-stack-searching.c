#include <stdio.h>
#define MAX 100

int arr[MAX];
int top1 = -1;
int top2 = MAX;

void search1(int x)
{
    for (int i = 0; i <= top1; i++)
    {
        if (arr[i] == x)
        {
            printf("%d found in Stack1 at position %d\n", x, i + 1);
            return;
        }
    }
    printf("%d not found in Stack1\n", x);
}

void search2(int x)
{
    for (int i = MAX - 1; i >= top2; i--)
    {
        if (arr[i] == x)
        {
            printf("%d found in Stack2 at position %d\n", x, MAX - i);
            return;
        }
    }
    printf("%d not found in Stack2\n", x);
}

int main()
{
    int choice, value;
    for (;;)
    {
        printf("\n1.Search Stack1\n2.Search Stack2\n3.Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 3)
            break;
        printf("Enter value to search: ");
        scanf("%d", &value);
        choice == 1 ? search1(value) : choice == 2 ? search2(value)
                                                   : printf("Invalid choice\n");
    }
    return 0;
}