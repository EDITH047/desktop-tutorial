#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void insertionofnode(int value)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("No memory");
        return;
    }
    newnode->data=value;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    {
        printf("No memory");
        return;
    }
    newnode->data=value;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void searchkey(int key)
{
    struct node *temp=head;
    int flag=0;
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        if(temp->data==key)
        {
            flag++;
        }
        temp=temp->next;
    }
    if(flag!=0)
    {
        printf("The value is found\n");
    }
    else
    {
        printf("The value is not found\n");
    }
}
int main()
{
    int n;
    printf("Enter the number of nodes to be entered\n");
    scanf("%d",&n);
    printf("Enter the elements to be entered into the nodes");
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        insertionofnode(x);
    }
    int key;
    printf("Enter the value to be searched for in the list");
    scanf("%d",&key);
    searchkey(key);
    return 0;
}

