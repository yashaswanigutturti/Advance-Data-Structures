#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

/* Insert from left/front */
void pushLeft(int x)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    for (int i = top; i >= 0; i--)
    {
        stack[i + 1] = stack[i];
    }

    stack[0] = x;
    top++;

    printf("%d inserted from left\n", x);
}

/* Insert from right/top */
void pushRight(int x)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    top++;
    stack[top] = x;

    printf("%d inserted from right\n", x);
}

/* Delete from left/front */
void popLeft()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("%d deleted from left\n", stack[0]);

    for (int i = 0; i < top; i++)
    {
        stack[i] = stack[i + 1];
    }

    top--;
}

/* Delete from right/top */
void popRight()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("%d deleted from right\n", stack[top]);

    top--;
}

/* Display */
void display()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack: ");

    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

    printf("\n");
}

int main()
{
    int choice, x;

    while (1)
    {
        printf("\n----- DOUBLE ENDED STACK -----\n");
        printf("1. Insert from Left\n");
        printf("2. Insert from Right\n");
        printf("3. Delete from Left\n");
        printf("4. Delete from Right\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                pushLeft(x);
                break;

            case 2:
                printf("Enter element: ");
                scanf("%d", &x);
                pushRight(x);
                break;

            case 3:
                popLeft();
                break;

            case 4:
                popRight();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Program ended.\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}