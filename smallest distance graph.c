#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 1000000  


struct Node {
    int dest, weight;
    struct Node* next;
};

struct Node* adj[MAX];

struct Node* newNode(int dest, int weight) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->dest = dest;
    node->weight = weight;
    node->next = NULL;
    return node;
}
void addEdge(int src, int dest, int weight) {
    struct Node* node = newNode(dest, weight);
    node->next = adj[src];
    adj[src] = node;
}
void small_dist(int V, int src) {
    int dist[V], visited[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        int minDist = INF;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }
        if (u == -1) break;  // 
        visited[u] = 1;
        struct Node* node = adj[u];
        while (node) {
            int v = node->dest;
            int w = node->weight;
            if (!visited[v] && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
            node = node->next;
        }
    }
    printf("City\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}
int main() {
    int V = 4;
    for (int i = 0; i < V; i++) adj[i] = NULL;

    addEdge(0, 1, 5);
    addEdge(0, 2, 2);
    addEdge(1, 3, 1);
    addEdge(2, 3, 7);

    int source = 0;
    small_dist(V, source);

    return 0;
}