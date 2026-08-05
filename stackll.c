#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void display();

void push()
{
    struct node *new;

    new = (struct node *)malloc(sizeof(struct node));

    printf("Enter Element: ");
    scanf("%d", &new->data);

    new->next = top;
    top = new;

    display();
}

void pop()
{
    struct node *temp;

    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;

    printf("Deleted Element: %d\n", temp->data);

    top = top->next;
    free(temp);

    display();
}

void peek()
{
    if(top == NULL)
        printf("Stack is Empty\n");
    else
        printf("Top Element: %d\n", top->data);
}

void display()
{
    struct node *temp;

    if(top == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack Elements:\n");

    temp = top;

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
        printf("\nStack Using Linked List\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: exit(0);
            default: printf("Invalid Choice\n");
        }
    }
}