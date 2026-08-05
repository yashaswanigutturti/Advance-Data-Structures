#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void display();

void enqueue()
{
    int x;

    if(rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    printf("Enter Element: ");
    scanf("%d", &x);

    if(front == -1)
        front = 0;

    rear++;
    queue[rear] = x;

    display();
}

void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted Element: %d\n", queue[front]);

    front++;

    if(front > rear)
        front = rear = -1;

    display();
}

void peek()
{
    if(front == -1)
        printf("Queue is Empty\n");
    else
        printf("Front Element: %d\n", queue[front]);
}

void display()
{
    int i;

    if(front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue Elements:\n");

    for(i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    printf("\n");
}

int main()
{
    int ch;

    while(1)
    {
        printf("\nQueue Using Array\n");
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