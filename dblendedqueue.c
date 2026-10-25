#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

void insertFront(int x)
{
    if ((front == 0 && rear == MAX - 1) ||
        (front == rear + 1))
    {
        printf("Deque is full\n");
    }
    else
    {
        if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = MAX - 1;
        }
        else
        {
            front--;
        }

        deque[front] = x;
        printf("Inserted %d at front\n", x);
    }
}

void insertRear(int x)
{
    if ((front == 0 && rear == MAX - 1) ||
        (front == rear + 1))
    {
        printf("Deque is full\n");
    }
    else
    {
        if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == MAX - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        deque[rear] = x;
        printf("Inserted %d at rear\n", x);
    }
}

void deleteFront()
{
    if (front == -1)
    {
        printf("Deque is empty\n");
    }
    else
    {
        printf("Deleted element: %d\n", deque[front]);

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == MAX - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
}

void deleteRear()
{
    if (front == -1)
    {
        printf("Deque is empty\n");
    }
    else
    {
        printf("Deleted element: %d\n", deque[rear]);

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = MAX - 1;
        }
        else
        {
            rear--;
        }
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Deque is empty\n");
    }
    else
    {
        printf("Deque elements: ");
        i = front;

        while (1)
        {
            printf("%d ", deque[i]);

            if (i == rear)
                break;

            i = (i + 1) % MAX;
        }

        printf("\n");
    }
}

int main()
{
    int choice, x;

    while (1)
    {
        printf("\n1. Insert Front");
        printf("\n2. Insert Rear");
        printf("\n3. Delete Front");
        printf("\n4. Delete Rear");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                insertFront(x);
                break;

            case 2:
                printf("Enter element: ");
                scanf("%d", &x);
                insertRear(x);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
