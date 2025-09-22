#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int vertex;
    struct Node* next;
}; 
struct Node *adj_list[100];
int n;
int visited[100];
int stack[100];
int top=-1;
int queue[100];
int front=-1;
int rear=-1;
void push(int v)
{
    stack[++top]=v;
}
int pop()
{
    return stack[top--];
}
int isEmpty()
{
    return top==-1;
}
void enqueue(int v)
{
    if (front==-1 && rear==-1)
    {
        front=rear=0;
    }
    else
    {
        rear++;
    }
    queue[rear]=v;
}
int dequeue()
{
    int v=queue[front];
    if (front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front++;
    }
    return v;
}
int isQueueEmpty()
{
    return front==-1 && rear==-1;
}
void read_graph() {
    struct Node *newnode, *temp;
    int edges;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Is there an edge between %d and %d (1/0): ", i + 1, j + 1);
            scanf("%d", &edges);

            if (edges == 1) {
                newnode = (struct Node*)malloc(sizeof(struct Node));
                newnode->vertex = j; 
                newnode->next = NULL;

                if (adj_list[i] == NULL) {
                    adj_list[i] = newnode;
                } else {
                    temp = adj_list[i];
                    while (temp->next != NULL)
                        temp = temp->next;
                    temp->next = newnode;
                }
            }
        }
    }
}

void DFS(int start) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    struct Node *temp;
    push(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int v = pop();
        printf("%d ", v + 1); 
        temp = adj_list[v];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                push(temp->vertex);
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
}

void BFS(int start) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    struct Node *temp;
    enqueue(start);
    visited[start] = 1;

    while (!isQueueEmpty()) {
        int v = dequeue();
        printf("%d ", v + 1);
        temp = adj_list[v];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                enqueue(temp->vertex);
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
}

int main()
{
    int i,choice,v;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        adj_list[i]=NULL;
        visited[i]=0;
    }
    read_graph();
    printf("Adjacency List:\n");
    for (i=0;i<n;i++)
    {           
        struct Node *temp=adj_list[i];
        printf("%d: ",i+1);
        while (temp!=NULL)
        {
            printf("%d -> ", temp->vertex + 1);
            temp=temp->next;
        }
        printf("NULL\n");
    }
    printf("1. DFS\n2. BFS\nEnter your choice: ");
    scanf("%d",&choice);
    printf("Enter starting vertex: ");
    scanf("%d",&v);

    if (choice==1)
    {
        printf("DFS Traversal: ");
        DFS(v - 1);   
    }
    else if (choice==2)
    {
        printf("BFS Traversal: ");
        BFS(v - 1);  
    }
    else
    {
        printf("Invalid choice\n");
    }
    return 0;
}

