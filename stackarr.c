#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void display();

void push()
{
    int x;

    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &x);

    top++;
    stack[top] = x;

    display();
}

void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("Deleted Element = %d\n", stack[top]);
    top--;

    display();
}

void peek()
{
    if(top == -1)
        printf("Stack is Empty\n");
    else
        printf("Top Element = %d\n", stack[top]);
}

void display()
{
    int i;

    if(top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack Elements:\n");

    for(i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    printf("\n");
}

int main()
{
    int ch;

    while(1)
    {
        printf("\nStack Using Array\n");
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