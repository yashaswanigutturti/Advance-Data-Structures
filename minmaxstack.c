#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = x;
}

void sortAscending()
{
    int i, j, temp;

    for (i = 0; i <= top; i++)
    {
        for (j = i + 1; j <= top; j++)
        {
            if (stack[i] > stack[j])
            {
                temp = stack[i];
                stack[i] = stack[j];
                stack[j] = temp;
            }
        }
    }
}

void sortDescending()
{
    int i, j, temp;

    for (i = 0; i <= top; i++)
    {
        for (j = i + 1; j <= top; j++)
        {
            if (stack[i] < stack[j])
            {
                temp = stack[i];
                stack[i] = stack[j];
                stack[j] = temp;
            }
        }
    }
}

void display()
{
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    printf("\n");
}

int main()
{
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        push(x);
    }

    sortAscending();

    printf("Stack in Min order: ");
    display();

    printf("Minimum element = %d\n", stack[0]);

    sortDescending();

    printf("Stack in Max order: ");
    display();

    printf("Maximum element = %d\n", stack[0]);

    return 0;
}