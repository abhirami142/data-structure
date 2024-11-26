#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 6

//vertex count
int vertex_count = 0;

// vertex definitions
struct vertex {
    char data;
    bool visited;
};

//array of vertices
struct vertex *graph[MAX];

//adjacency matrix
int adj_matrix[MAX][MAX];

//stack
int stack[MAX];
int top = -1;

void push(int data) {
    if (top >= MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = data;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack[top--];
}

int peek() {
    return stack[top];
}

bool is_stack_empty() {
    return top == -1;
}

// add vertex to the vertex list
void add_vertex(char data) {
    struct vertex *new = (struct vertex*)malloc(sizeof(struct vertex));
    new->data = data;
    new->visited = false;
    graph[vertex_count] = new;
    vertex_count++;
}

// add edge to the adjacency matrix
void add_edge(int start, int end) {
    if (start >= vertex_count || end >= vertex_count) {
        printf("Invalid vertices for edge!\n");
        return;
    }
    adj_matrix[start][end] = 1;
    adj_matrix[end][start] = 1;
}

// to return adjacent vertex
int adj_vertex(int vertex_get) {
    for (int i = 0; i < vertex_count; i++) {
        if (adj_matrix[vertex_get][i] == 1 && !graph[i]->visited) {
            return i;
        }
    }
    return -1;
}

// to display vertex value
void display_vertex(int pos) {
    printf("%c ", graph[pos]->data);
}

void dfs() {
    printf("\n|||||||||||||||||||||||||||||||\n");
    graph[0]->visited = true;
    display_vertex(0);
    push(0);

    while (!is_stack_empty()) {
        int current = peek();
        int unvisited = adj_vertex(current);

        if (unvisited == -1) {
            pop();
        } else {
            graph[unvisited]->visited = true;
            display_vertex(unvisited);
            push(unvisited);
        }
    }
    printf("\n|||||||||||||||||||||||||||||||\n");

    // Reset visited status
    for (int i = 0; i < vertex_count; i++) {
        graph[i]->visited = false;
    }
}

void show() {
    printf("\n.................................\n");
    for (int i = 0; i < vertex_count; i++) {
        printf("\n Edge position of '%c' is %d\n", graph[i]->data, i);
    }
    printf("\n.................................\n");
}

int main() {
    int opt;
    char data;
    int edge_1, edge_2;

    // Initialize adjacency matrix to 0
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            adj_matrix[i][j] = 0;
        }
    }

    do {
        printf("\n1) Add vertex \n2) Create edge \n3) Traversal \n0) Exit \nChoose option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                printf("\nEnter data to be added to vertex: ");
                scanf(" %c", &data);
                add_vertex(data);
                break;
            case 2:
                show();
                printf("\nEnter edge starting: ");
                scanf("%d", &edge_1);
                printf("\nEnter edge ending: ");
                scanf("%d", &edge_2);
                add_edge(edge_1, edge_2);
                break;
            case 3:
                dfs();
                break;
            default:
                printf("\nInvalid option, try again!\n");
        }
    } while (opt != 0);

    return 0;
}

