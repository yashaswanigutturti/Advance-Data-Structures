#include <stdio.h>
#define MAX 5

int data[MAX], priority[MAX];
int n = 0;

void insert()
{
    int x, p, i;

    if (n == MAX)
    {
        printf("Priority Queue is full\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &x);

    printf("Enter priority: ");
    scanf("%d", &p);

    i = n - 1;

    while (i >= 0 && priority[i] > p)
    {
        data[i + 1] = data[i];
        priority[i + 1] = priority[i];
        i--;
    }

    data[i + 1] = x;
    priority[i + 1] = p;
    n++;

    printf("Element inserted\n");
}

void delete()
{
    int i;

    if (n == 0)
    {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Deleted element: %d\n", data[0]);

    for (i = 0; i < n - 1; i++)
    {
        data[i] = data[i + 1];
        priority[i] = priority[i + 1];
    }

    n--;
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
