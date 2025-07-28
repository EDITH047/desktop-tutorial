#include <stdio.h>
#include <ctype.h>
char c[]={'+','-','*','/','^','(',')','#'};
int isp[]={2,2,4,4,5,0,0,0};
int icp[]={1,1,3,3,6,9,0};
int h=-1;
char s[20];
int top=-1;
void push(char x)
{
    if(top>=19)
    {
        printf("Stack is full");
    }
    else
    {
        top+=1;
        s[top]=x;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("%c",s[top]);
        top--;
    }
}
char nexttoken(char b[])
{
    h+=1;
    return b[h];
}
void postfix(char a[])
{
    h=-1;
    char x=nexttoken(a);
    while(x!='#')
    {
        if((isalpha(x))>0)
        {
            printf("%c",x);
        }
        else if(x==')')
        {
            while(s[top]!='(')
            {
                printf("%c",s[top]);
                top--;
            }
            if(top!=-1)
            top--;
        }
        else
        {
            int isp1=-1;
            char z=s[top];
            for (int i =0;i<8;i++) 
            {
                if (c[i]==z) 
                {
                    isp1=isp[i];
                    break;
                }
            }
            int icp1 = -1;
            for (int i =0;i<8;i++) 
            {
                if (c[i]==x) 
                {
                    icp1=icp[i];
                    break;
                }
            }
            while(isp1>=icp1)
            {
                pop();
                if (s[top] == '#') break;
                z = s[top];
                for (int i=0;i<8;i++) 
                {
                    if (c[i]==z) 
                    {
                        isp1=isp[i];
                        break;
                    }
                }
            }
            push(x);
        }
        x=nexttoken(a);
    }
    while(top>=0)
    {
        pop();
    }
}
int main()
{
    char a[20];
    printf("Enter the infix expression\n");
    scanf("%s",a);
    push('#');
    postfix(a);
    printf("\n");
    return 0;
}