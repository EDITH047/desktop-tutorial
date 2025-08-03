#include <stdio.h>
#include <stdlib.h>
struct list
{
    int data;
    struct list *next; 
};
struct list *head = NULL;
struct list *rare = NULL;

void createNode(int value) {
    struct list *newNode = (struct list *)malloc(sizeof(struct list));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        rare = newNode;
        newNode->next = head; 
    } else {
        rare->next = newNode;
        rare = newNode;
        rare->next = head; 
    }
}
int main()
{
    while (1) {
        int value;
        printf("Enter a value to add to the circular linked list (or -1 to exit): ");
        scanf("%d", &value);
        if (value == -1) {
            break;
        }
        createNode(value);
    }
    struct list *current = head;
    if (current != NULL) {
        do {
            printf("%d -> ", current->data);
            current = current->next;
        } while (current != head);
    }
    printf("(head)\n");

    return 0;
}



