#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data, priority;
    struct Node *next;
};

struct Node *front = NULL;

void insert()
{
    struct Node *newnode, *temp;
    int x, p;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &x);
    printf("Enter priority: ");
    scanf("%d", &p);

    newnode->data = x;
    newnode->priority = p;
    newnode->next = NULL;

    if (front == NULL || p < front->priority)
    {
        newnode->next = front;
        front = newnode;
    }
    else
    {
        temp = front;

        while (temp->next != NULL &&
               temp->next->priority <= p)
        {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }

    printf("Element inserted\n");
}

void delete()
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("Priority Queue is empty\n");
    }
    else
    {
        temp = front;

        printf("Deleted element: %d\n", front->data);

        front = front->next;
        free(temp);
    }
}

void display()
{
    struct Node *temp = front;

    if (front == NULL)
    {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Data\tPriority\n");

    while (temp != NULL)
    {
        printf("%d\t%d\n", temp->data, temp->priority);
        temp = temp->next;
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
