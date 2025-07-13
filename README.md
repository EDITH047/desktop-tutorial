#include <stdio.h>
int main()
{
    int n1,n2;
    printf("Enter the number of coefficient of first polynomial:");
    scanf("%d",&n1);
    int poly1[n1][2];
    for (int i=0;i<n1;i++)
    {
            printf("Enter the coefficient:\n");
            scanf("%d",&poly1[i][0]);
            printf("Enter its exponenet:\n");
            scanf("%d",&poly1[i][1]);
    }
    printf("Enter the number of coefficient of second polynomial:");
    scanf("%d",&n2);
    int poly2[n2][2];
    for (int i=0;i<n2;i++)
    {
            printf("Enter the coefficient:\n");
            scanf("%d",&poly2[i][0]);
            printf("Enter its exponenet:\n");
            scanf("%d",&poly2[i][1]);
    }
    int poly3[n1+n2][2];
    int k=0;
    for (int i=0;i<n1;i++)
    {
        int f=0;
        for (int j=0;j<n2;j++)
        {
            if (poly1[i][1]==poly2[j][1])
            {
                poly3[k][0]=poly1[i][0]+poly2[j][0];
                poly3[k][1]=poly1[i][1];
                k++;
                f=1;
                break;
            }
        }
        if (f==0)
        {
            poly3[k][0]=poly1[i][0];
            poly3[k][1]=poly1[i][1];
            k++;
        }
    }
    for (int i=0;i<k-1;i++)
    {
        for (int j=0;j<k-1-i;j++)
        {
            int temp1,temp0;
            if (poly3[j][1]<poly3[j+1][1])
            {
                temp1=poly3[j][1];
                poly3[j][1]=poly3[j+1][1];
                poly3[j+1][1]=temp1;
                temp0=poly3[j][0];
                poly3[j][0]=poly3[j+1][0];
                poly3[j+1][0]=temp0;
            }
        }
    }
    printf("The equation is: ");
    for (int i=0;i<k;i++)
    {
        if (poly3[i][1]==0)
        {
            printf("%d",poly3[i][0]);
        }
        else
        {
            printf("%d(x^%d) ",poly3[i][0],poly3[i][1]);
            if (i!=(k-1))
            {
                printf("+ ");
            }
        }
        if (i==k-1)
        {
            printf(" = 0");
        }
    }
    return 0;
}
