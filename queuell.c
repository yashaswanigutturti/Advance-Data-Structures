#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void display();

void enqueue()
{
    struct node *new;

    new = (struct node *)malloc(sizeof(struct node));

    printf("Enter Element: ");
    scanf("%d", &new->data);

    new->next = NULL;

    if(front == NULL)
    {
        front = rear = new;
    }
    else
    {
        rear->next = new;
        rear = new;
    }

    display();
}

void dequeue()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }

    temp = front;

    printf("Deleted Element: %d\n", temp->data);

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);

    display();
}

void peek()
{
    if(front == NULL)
        printf("Queue is Empty\n");
    else
        printf("Front Element: %d\n", front->data);
}

void display()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue Elements:\n");

    temp = front;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int ch;

    while(1)
    {
        printf("\nQueue Using Linked List\n");
        printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: exit(0);
            default: printf("Invalid Choice\n");
        }
    }
}