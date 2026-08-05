#include <stdio.h>

#define MAX 100

int arr[MAX], n = 0;

void insert(int pos, int value);
void Delete(int pos);
void display();
int search(int key);

int main()
{
    int choice, pos, value, key, result;

    do
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Search\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &value);
                insert(pos, value);
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                Delete(pos);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Enter element to search: ");
                scanf("%d", &key);
                result = search(key);

                if(result != -1)
                    printf("Element found at position %d\n", result + 1);
                else
                    printf("Element not found\n");
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 5);

    return 0;
}

void insert(int pos, int value)
{
    int i;

    if(pos < 1 || pos > n + 1)
    {
        printf("Invalid position\n");
        return;
    }

    for(i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = value;
    n++;

    printf("Element Inserted\n");
}

void Delete(int pos)
{
    int i;

    if(n == 0 || pos < 1 || pos > n)
    {
        printf("Invalid position\n");
        return;
    }

    for(i = pos - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    printf("Element Deleted\n");
}

void display()
{
    int i;

    if(n == 0)
    {
        printf("Array is Empty\n");
        return;
    }

    printf("Array Elements: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int search(int key)
{
    int i;

    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            return i;
        }
    }

    return -1;
}