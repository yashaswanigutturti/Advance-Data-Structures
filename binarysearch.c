#include <stdio.h>

void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int bsIterative(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        else if (arr[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int bsRecursive(int arr[], int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
        return mid;

    else if (arr[mid] < key)
        return bsRecursive(arr, mid + 1, high, key);

    else
        return bsRecursive(arr, low, mid - 1, key);
}

int main()
{
    int arr[100], n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    sort(arr, n);

    printf("Sorted array: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    int result1 = bsIterative(arr, n, key);

    int result2 = bsRecursive(arr, 0, n - 1, key);

    if (result1 != -1)
        printf("Iterative: Element found at index %d\n", result1);
    else
        printf("Iterative: Element not found\n");

    if (result2 != -1)
        printf("Recursive: Element found at index %d\n", result2);
    else
        printf("Recursive: Element not found\n");

    return 0;
}