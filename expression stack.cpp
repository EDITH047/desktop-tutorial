#include <stdio.h>
#include <string.h>
#define MAX 100
char stack1[MAX];
char stack[MAX];
int evalStack[MAX];
int evalTop = -1;
int top = -1;
int top1 = -1;
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
char pop1() {
    if (top1 == -1)
        return '\0';
    else {
        char temp = stack1[top1];
        top1--;
        return temp;
    }
}

int push1(char temp) {
    if (top1 == MAX - 1)
        return 0;
    else {
        top1++;
        stack1[top1] = temp;
        return 0;
    }
}
int evalPop() {
    if (evalTop == -1)
        return 0;
    else {
        int temp = evalStack[evalTop];
        evalTop--;
        return temp;
    }
}   
void evalPush(int temp) {
    if (evalTop == MAX - 1) {
        printf("Evaluation stack overflow\n");
    } else {
        evalTop++;
        evalStack[evalTop] = temp;
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
void postfix()
{
    top = -1;
    top1 = -1; 
    int i = 0;
    while (arr[i] != '\0') 
    {
        if (('a' <= arr[i] && arr[i] <= 'z') || ('A' <= arr[i] && arr[i] <= 'Z')) 
        {
            push1(arr[i]);
        } 
        else if (arr[i] == ')')
        {
            char temp;
            while ((temp=pop()) != '(') 
            {
                push1(temp);
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
        int i = 0;
        switch (choice) 
        {
            case 1:
                postfix();
                i=0;
                printf("The postfix expression is: ");
                while (i <= top1) 
                {
                    printf("%c", stack1[i]);
                    i++;
                }
                printf("\n");
                break;
            case 2:
                postfix();  // convert infix to postfix first
                evalTop = -1;  // reset evaluation stack

                for (i = 0; i <= top1; i++) {
                    char ch = stack1[i];
                    if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')) {
                        int val;
                        printf("Enter the value of %c: ", ch);
                        scanf("%d", &val);
                        evalPush(val);
                    } else {
                        int a = evalPop();
                        int b = evalPop();
                        switch (ch) {
                            case '+': evalPush(b + a); break;
                            case '-': evalPush(b - a); break;
                            case '*': evalPush(b * a); break;
                            case '/':
                                if (a == 0) {
                                    printf("Division by zero error.\n");
                                    return 1;
                                }
                                evalPush(b / a);
                                break;
                            default:
                                printf("Unknown operator %c\n", ch);
                                return 1;
                        }
                    }
                }

                printf("The result is: %d\n", evalPop());
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
