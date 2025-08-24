#include <stdio.h>  
#define max 5
int q1[max];
int q2[max];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;
void push(int data) 
{
    if (rear1 == max - 1) {
        printf("Stack overflow\n");
        return;
    }
    if (front1 == -1) 
    {
        front1 = 0;
        rear1++;
        q1[rear1] = data;
    }
    else 
    {
        front2 = 0;
        rear2 = 0;
        q2[rear2] = data;
        while (front1 <= rear1) 
        {
            rear2++;
            q2[rear2] = q1[front1];
            front1++;
        }
        front1 = 0;
        rear1 = rear2;
        for (int i = 0; i <= rear2; i++) {
            q1[i] = q2[i];
        }
        front2 = -1;
        rear2 = -1;
    }
}
int pop() 
{
    if (front1 == -1) 
    {
        printf("Stack underflow\n");
        return -1;
    }
    int data = q1[front1];
    front1++;
    if (front1 > rear1) front1 = rear1 = -1;
    return data;
}
int main() 
{
    printf("Menu\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Exit\n");
    int choice, data;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                data = pop();
                if (data != -1) printf("Popped: %d\n", data);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}