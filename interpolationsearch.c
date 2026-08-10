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

int isIterative(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high && key >= arr[low] && key <= arr[high])
    {
        if (arr[low] == arr[high])
        {
            if (arr[low] == key)
                return low;
            return -1;
        }

        int pos = low + ((key - arr[low]) * (high - low))
                         / (arr[high] - arr[low]);

        if (arr[pos] == key)
            return pos;

        else if (arr[pos] < key)
            low = pos + 1;

        else
            high = pos - 1;
    }

    return -1;
}

int isRecursive(int arr[], int low, int high, int key)
{
    if (low > high || key < arr[low] || key > arr[high])
        return -1;

    if (arr[low] == arr[high])
    {
        if (arr[low] == key)
            return low;
        return -1;
    }

    int pos = low + ((key - arr[low]) * (high - low))
                     / (arr[high] - arr[low]);

    if (arr[pos] == key)
        return pos;

    else if (arr[pos] < key)
        return isRecursive(arr, pos + 1, high, key);

    else
        return isRecursive(arr, low, pos - 1, key);
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

    int result1 = isIterative(arr, n, key);

    int result2 = isRecursive(arr, 0, n - 1, key);

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