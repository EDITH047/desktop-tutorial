#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
int n;
char arr[100];
struct Node
{
    char data;
    struct Node* left;
    struct Node* right;
};
struct Node *root = NULL;
struct Node* pop() {
    if (top == -1)
        return NULL;
    else {
        struct Node* temp = (struct Node*)stack[top];
        top--;
        return temp;
    }
}
void push(struct Node* temp) {
    if (top == MAX - 1)
        return;
    else {
        top++;
        stack[top] = (char)temp;
    }
}
int isp(char temp) {
    if ((temp == '-') || (temp == '+')) 
        return 2;
    else if ((temp == '*') || (temp == '/'))
        return 5;
    else if (temp == '^')
        return 8;
    else if (temp == '(') 
        return 0;
    else
        return -1;
}

int icp(char temp) {
    if ((temp == '-') || (temp == '+')) {
        return 2;
    } else if ((temp == '*') || (temp == '/')) {
        return 5;
    } else if (temp == '^')
        return 9;
    else if (temp == '(') {
        return 10;
    } else if (temp == ')') {
        return 0;
    } else {
        return -1;
    }
}
char traverse()
{
    struct Node* node = root;
    if (node == NULL) {
        return '\0';
    }
    char left = traverse(node->left);
    char right = traverse(node->right);
    return node->data;
}
void postfix()
{ 
    top = -1; 
    int i = 0;
    while (arr[i] != '\0') 
    {
        if (('a' <= arr[i] && arr[i] <= 'z') || ('A' <= arr[i] && arr[i] <= 'Z')) 
        {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = arr[i];
            newNode->left = NULL;
            newNode->right = NULL;
            push(newNode);
        } 
        else if (arr[i] == ')')
        {
            char temp;
            while ((temp=pop()) != '(') 
            {
                push(temp);
            }
        } 
        else
        {
            while (isp(stack[top]) >= icp(arr[i]) && top != -1) 
            {
                push1(pop());
            }
            push(arr[i]);
        }
        i++;
    }
    while (top != -1) 
    {
        push1(pop());
    }
}
}