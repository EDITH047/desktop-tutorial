#include <stdio.h>  
#define max 5
int q1[max];
int q2[max];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;
void enqueue1(int data) {
    if (rear1 == max - 1) {
        return;
    }
    if (front1 == -1) {
        front1 = 0;
    }
    rear1++;
    q1[rear1] = data;
}
void enqueue2(int data) {
    if (rear2 == max - 1) {
        return;
    }
    if (front2 == -1) {
        front2 = 0;
    }
    rear2++;
    q2[rear2] = data;
}
int dequeue1() {
    if (front1 == -1) {
        return -1;
    }
    int data = q1[front1];
    front1++;
    if (front1 > rear1) front1 = rear1 = -1;
    return data;
}
int dequeue2() {
    if (front2 == -1) {
        return -1;
    }
    int data = q2[front2];
    front2++;
    if (front2 > rear2) front2 = rear2 = -1;
    return data;
}
void push(int data) 
{
    if (rear1 == max - 1) {
        printf("Stack overflow\n");
        return;
    }
    front2=rear2=-1;
    enqueue2(data);
    while (front1 != -1) 
    {
        enqueue2(dequeue1());
    }
    front1 = 0;
    rear1 = rear2;
    for (int i = 0; i <= rear2; i++) {
        q1[i] = q2[i];
    }
    front2 = -1;
    rear2 = -1;
    
}
int pop() 
{
    if (front1 == -1) 
    {
        printf("Stack underflow\n");
        return -1;
    }
    return dequeue1();
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