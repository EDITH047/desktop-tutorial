#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* lptr;
    struct Node* rptr;  
};
struct Node* head = NULL;
void createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->lptr = NULL;
    newNode->rptr = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->rptr != NULL) {
            temp = temp->rptr;
        }
        temp->rptr = newNode;
        newNode->lptr = temp;
    }
}
void bubblesort()
{
    if (head == NULL || head->rptr == NULL) {
        return; 
    }
    int temp1;
    struct Node* current;
    struct Node* temp;
    current=head;
    int f;
    while (current != NULL) {
        temp = head->rptr;
        f = 1;
        while (temp != NULL) {
            if (temp->lptr->data > temp->data) {
                temp1 = temp->data;
                temp->data = temp->lptr->data;
                temp->lptr->data = temp1;
                f=0;
            }
            temp = temp->rptr;
        }
        if (f == 1) {
            return; 
        }
        current = current->rptr;
    }
}

void displayList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        if (temp->rptr != NULL) {
            printf("<-> ");
        }
        temp = temp->rptr;
    }
    printf("\n");
}
int main() {
    int choice, value;
    while (1) {
        printf("1. Create Node\n");
        printf("2. Display List\n");
        printf("3. Sort List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data for new node: ");
                scanf("%d", &value);
                createNode(value);
                break;
            case 2:
                displayList();
                break;
            case 3:
                bubblesort();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
