#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int largest = arr[0];
    int second = arr[0];

   
    if (arr[1] > largest) {
        second = largest;
        largest = arr[1];
    } else {
        second = arr[1];
    }

    for (int i = 2; i < n; i++) {
        if (arr[i] > largest) {
            second = largest;
            largest = arr[i];
        } else if (arr[i] > second && arr[i] < largest) {
            second = arr[i];
        }
    }

    if (largest == second)
        printf("No second largest element exists.\n");
    else
        printf("Second largest element is: %d\n", second);

    return 0;
}
