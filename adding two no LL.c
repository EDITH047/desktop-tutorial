#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node *head1 = NULL;
struct Node *head2 = NULL;
struct Node *result = NULL;

void create(struct Node **head, int data)
{
    struct Node *temp, *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode==NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
    }
    else 
    {
        temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void reverse(struct Node **head)
{
    struct Node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) 
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
int main() 
{
    int data;
    printf("Enter the first number(Enter the digits from left to right and -1 to exit): ");
    while (1) {
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        create(&head1, data);
    }
    printf("Enter the second number(Enter the digits from left to right and -1 to exit): ");
    while (1) {
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        create(&head2, data);
    }
    reverse(&head1);
    reverse(&head2);
    struct Node *ptr1 = head1;
    struct Node *ptr2 = head2;
    int carry = 0;
    while (ptr1 != NULL || ptr2 != NULL || carry != 0) {
        int sum = carry;
        if (ptr1 != NULL) {
            sum += ptr1->data;
            ptr1 = ptr1->next;
        }
        if (ptr2 != NULL) {
            sum += ptr2->data;
            ptr2 = ptr2->next;
        }
        carry = sum / 10;
        create(&result, sum % 10);
    }
    reverse(&result);
    printf("Sum: ");
    struct Node *temp = result;
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}