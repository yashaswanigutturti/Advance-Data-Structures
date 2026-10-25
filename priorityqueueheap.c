#include <stdio.h>
#define MAX 100

int data[MAX], priority[MAX];
int n = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert()
{
    int x, p, i, parent;

    if (n == MAX)
    {
        printf("Priority Queue is full\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &x);
    printf("Enter priority: ");
    scanf("%d", &p);

    i = n;
    data[i] = x;
    priority[i] = p;
    n++;

    while (i > 0)
    {
        parent = (i - 1) / 2;

        if (priority[parent] <= priority[i])
            break;

        swap(&priority[parent], &priority[i]);
        swap(&data[parent], &data[i]);

        i = parent;
    }

    printf("Element inserted\n");
}

void delete()
{
    int i = 0, left, right, smallest;

    if (n == 0)
    {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Deleted element: %d\n", data[0]);

    data[0] = data[n - 1];
    priority[0] = priority[n - 1];
    n--;

    while (1)
    {
        left = 2 * i + 1;
        right = 2 * i + 2;
        smallest = i;

        if (left < n &&
            priority[left] < priority[smallest])
            smallest = left;

        if (right < n &&
            priority[right] < priority[smallest])
            smallest = right;

        if (smallest == i)
            break;

        swap(&priority[i], &priority[smallest]);
        swap(&data[i], &data[smallest]);

        i = smallest;
    }
}

void display()
{
    int i;

    if (n == 0)
    {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Data\tPriority\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\n", data[i], priority[i]);
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
