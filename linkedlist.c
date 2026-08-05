#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertbeg();
void insertend();
void insertpos();
void deletebeg();
void deleteend();
void deletepos();
void display();
void search();

int main()
{
    int choice;

    while(1)
    {
        printf("\n----- Single Linked List -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Search\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                insertbeg();
                display();
                break;

            case 2:
                insertend();
                display();
                break;

            case 3:
                insertpos();
                display();
                break;

            case 4:
                deletebeg();
                display();
                break;

            case 5:
                deleteend();
                display();
                break;

            case 6:
                deletepos();
                display();
                break;

            case 7:
                search();
                break;

            case 8:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}

void insertbeg()
{
    struct Node *new;

    new = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d",&new->data);

    new->next = head;
    head = new;
}

void insertend()
{
    struct Node *new, *temp;

    new = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d",&new->data);

    new->next = NULL;

    if(head == NULL)
    {
        head = new;
        return;
    }

    temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new;
}

void insertpos()
{
    int pos, i;

    struct Node *new, *temp;

    printf("Enter position: ");
    scanf("%d",&pos);

    if(pos == 1)
    {
        insertbeg();
        return;
    }

    new = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d",&new->data);

    temp = head;

    for(i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Invalid Position\n");
        free(new);
        return;
    }

    new->next = temp->next;
    temp->next = new;
}

void deletebeg()
{
    struct Node *temp;

    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    temp = head;
    head = head->next;

    free(temp);

    printf("Node Deleted\n");
}

void deleteend()
{
    struct Node *temp, *prev;

    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("Node Deleted\n");
        return;
    }

    temp = head;

    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    free(temp);

    printf("Node Deleted\n");
}

void deletepos()
{
    int pos, i;

    struct Node *temp, *prev;

    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d",&pos);

    if(pos == 1)
    {
        deletebeg();
        return;
    }

    temp = head;

    for(i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Invalid Position\n");
        return;
    }

    prev->next = temp->next;

    free(temp);

    printf("Node Deleted\n");
}

void display()
{
    struct Node *temp;

    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void search()
{
    int key, pos = 1;

    struct Node *temp = head;

    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    printf("Enter element to search: ");
    scanf("%d",&key);

    while(temp != NULL)
    {
        if(temp->data == key)
        {
            printf("Element found at position %d\n", pos);
            return;
        }

        temp = temp->next;
        pos++;
    }

    printf("Element Not Found\n");
}