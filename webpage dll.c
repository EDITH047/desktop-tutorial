#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char webpage[100];
struct Node
{
    char data[100];
    struct Node *rptr;
    struct Node *lptr;
};
struct Node *current = NULL;
void new_webpage()
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    strcpy(new_node->data, webpage);
    new_node->rptr = NULL;
    new_node->lptr = current;
    if (current != NULL)
    {
        if (current->rptr != NULL)
        {
            new_node->rptr = current->rptr;
            current->rptr->lptr = new_node;
        }
        current->rptr = new_node;
        
    }
    current = new_node;
}
char* back()
{
    if (current != NULL && current->lptr != NULL)
    {
        current = current->lptr;
        return current->data;
    }
    else
    {
        return "No previous webpage";
    }
}
char* forward()
{
    if (current != NULL && current->rptr != NULL)
    {
        current = current->rptr;
        return current->data;
    }
    else
    {
        return "No next webpage";
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("1. New Webpage\n2. Back\n3. Forward\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter webpage URL: ");
            scanf("%s", webpage);
            new_webpage();
            printf("Current webpage: %s\n", current->data);
        }
        else if (choice == 2)
        {
            printf("Current webpage: %s\n", back());
        }
        else if (choice == 3)
        {
            printf("Current webpage: %s\n", forward());
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
