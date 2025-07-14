#include <stdio.h>
#include <string.h>
#define max 100
char arr[100];
int top=(-1),n;
char stack[max];
void push(char temp)
{
    if (top>=max-1)
    {
        printf("The stack is full");
    }
    else
    {
        top++;
        stack[top]=temp;
    }
}
int pop()
{
    if (top==-1) 
    {
        return 0;
    }
    else
    {
        top--;
        return 1;
    }
}
int balanced()
{
    for (int i=0;i<n;i++)
    {
        if (arr[i]=='(')
        {
            push('(');
        }
        else if (arr[i]==')')
        {
            if (top==-1)
            {
                printf("Unbalanced");
                return 0;
            }
            else
            {
                pop();
            }  
        }
    }
    if (top==-1)
    {
        printf("Balanced");
    }
    else
    {
        printf("Unbalanced");
    }
    return 0;
}
int main()
{
    printf("Enter the equation:");
    scanf("%s",arr);
    n=strlen(arr);
    balanced();
    return 0;
}