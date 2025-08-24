#include <stdio.h>
#define MAX 5
int stack1[MAX];
int stack[MAX];
int top = -1;
int top1 = -1;
int pop() {
    if (top == -1)
        return -1;
    else {
        int temp = stack[top];
        top--;
        return temp;
    }
}

int push(int temp) {
    if (top >= MAX - 1)
    {
        printf("Stack overflow\n");
        return -1;
    }
    else {
        top++;
        stack[top] = temp;
        return 0;
    }
}
int pop1() {
    if (top1 == -1)
        return -1;
    else {
        int temp = stack1[top1];
        top1--;
        return temp;
    }
}

int push1(int temp) {
    if (top1 >= MAX - 1) {
        printf("Stack overflow\n");
        return -1;
    } 
    else {
        top1++;
        stack1[top1] = temp;
        return 0;
    }
}
void enqueue(int data) 
{
    push(data);
}
int dequeue() 
{
    if (top == -1 && top1 == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    while (top != -1) 
    {
        push1(pop());
    }
    return pop1();
}
int main() 
{
    printf("Menu\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Exit\n");
    int choice, data;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                data = dequeue();
                if (data != -1) printf("Dequeued: %d\n", data);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}