#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;
int n;
char arr[100];

char pop() {
    if (top == -1)
        return '\0';
    else {
        char temp = stack[top];
        top--;
        return temp;
    }
}

int push(char temp) {
    if (top == MAX - 1)
        return 0;
    else {
        top++;
        stack[top] = temp;
        return 0;
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
    }
}

int main() {
    int choice;
    while (1) 
    {
        printf("\tMenu\nconvert infix to postfix------1\nCalculate the result----2\nExit----0\n");
        printf("Enter the choice:");
        scanf("%d", &choice);
        if (choice == 0) 
        {
            printf("The program is exited");
            break;
        }
        printf("Enter the equation:");
        scanf("%s", arr);
        n = strlen(arr);
        switch (choice) 
        {
            case 1:
                int i = 0;
                while (arr[i] != '\0') 
                {
                    if (('a' <= arr[i] && arr[i] <= 'z') || ('A' <= arr[i] && arr[i] <= 'Z')) 
                    {
                        printf("%c", arr[i]);
                    } 
                    else if (arr[i] == ')')
                    {
                        char temp;
                        while ((temp=pop()) != '(') 
                        {
                            printf("%c",temp);
                        }
                    } 
                    else
                    {
                        while (isp(stack[top]) >= icp(arr[i]) && top != -1) 
                        {
                            printf("%c", pop());
                        }
                        push(arr[i]);
                    }
                    i++;
                }
                while (top != -1) 
                {
                    printf("%c", pop());
                }
                break;
            // Additional cases and calculation logic can be implemented here
        }
    }
    return 0;
}
