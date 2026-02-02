#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[100];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter element to search: ");
    scanf("%d", &key);

    int found = 0;
    int index;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            found = 1;
            index = i;
            break;
        }
    }

    if (found)
    {
        printf("Element found at index %d (0-based).\n", index);
        char choice;
        printf("Do you want to delete it? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y')
        {
            for (int i = index; i < n - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            n--;
            printf("Array after deletion:\n");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Element not found.\n");
        char choice;
        printf("Do you want to insert it? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y')
        {
            int pos;
            printf("Enter index to insert (0-based): ");
            scanf("%d", &pos);

            if (pos < 0 || pos > n)
            {
                printf("Invalid index!\n");
            }
            else
            {
                for (int i = n; i > pos; i--)
                {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = key;
                n++;

                printf("Array after insertion:\n");
                for (int i = 0; i < n; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}
