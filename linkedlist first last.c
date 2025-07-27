#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node *head = NULL;
void create(int data)
{
    struct Node *temp, *prev;
    if (head == NULL)
    {
        head = (struct Node*)malloc(sizeof(struct Node));
        head->data = data;
        head->next = NULL;
    } 
    else 
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = data;
        temp->next = NULL;
        prev = head;
        while (prev->next != NULL) {
            prev = prev->next;
        }
        prev->next = temp;
    }
}

int main() 
{
    int choice, data;
    while (1) {
        printf("1. Create Node\n");
        printf("2. Display List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data for new node: ");
                scanf("%d", &data);
                create(data);
                break;
            case 2:
                struct Node* temp = head;
                if (temp == NULL) {
                    printf("List is empty.\n");
                } else {
                    printf("Linked List: ");
                    while (temp != NULL) {
                        printf("%d -> ", temp->data);
                        temp = temp->next;
                    }
                    printf("NULL\n");
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
    