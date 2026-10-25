#include <stdio.h>
#include <string.h>
#define MAX 100

char undoStack[MAX][50];
char redoStack[MAX][50];
int topUndo = -1, topRedo = -1;
char text[50];

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Type Text");
        printf("\n2. Undo");
        printf("\n3. Redo");
        printf("\n4. Display Text");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter text: ");
                scanf(" %[^\n]", text);

                strcpy(undoStack[++topUndo], text);
                topRedo = -1;

                printf("Text added\n");
                break;

            case 2:
                if (topUndo <= 0)
                {
                    printf("Nothing to undo\n");
                }
                else
                {
                    strcpy(redoStack[++topRedo],
                           undoStack[topUndo--]);

                    strcpy(text, undoStack[topUndo]);

                    printf("Undo successful\n");
                }
                break;

            case 3:
                if (topRedo == -1)
                {
                    printf("Nothing to redo\n");
                }
                else
                {
                    strcpy(text, redoStack[topRedo]);
                    strcpy(undoStack[++topUndo], text);
                    topRedo--;

                    printf("Redo successful\n");
                }
                break;

            case 4:
                if (topUndo == -1)
                    printf("Text is empty\n");
                else
                    printf("Current text: %s\n",
                           undoStack[topUndo]);
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
