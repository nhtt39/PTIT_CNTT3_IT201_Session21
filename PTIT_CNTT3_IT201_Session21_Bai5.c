#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {return;}
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* graph[], int startNode, int endNode) {
    struct Node* newNode = createNode(endNode);
    newNode->next = graph[startNode];
    graph[startNode] = newNode;
}

void displayGraph(struct Node* graph[], int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        printf("Node %d: ", i);
        struct Node* current = graph[i];
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void freeGraph(struct Node* graph[], int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        struct Node* current = graph[i];
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main() {
    struct Node* graph[3] = {NULL, NULL, NULL};

    addEdge(graph, 1, 2);

    printf("Danh sach ke sau khi them canh (1, 2):\n");
    displayGraph(graph, 3);

    addEdge(graph, 0, 1);

    printf("\nDanh sach ke sau khi them canh (0, 1):\n");
    displayGraph(graph, 3);

    freeGraph(graph, 3);

    return 0;
}
