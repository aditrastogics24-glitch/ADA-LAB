#include <stdio.h>

#define MAX 100

int main() {
    int n, V[MAX][MAX];
    int indegree[MAX], visited[MAX];
    int TP[MAX];
    int i, j, tp_count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &V[i][j]);
        }
    }

    // Step 1: Compute indegree
    for(i = 0; i < n; i++) {
        indegree[i] = 0;
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(V[j][i] == 1) {
                indegree[i]++;
            }
        }
    }

    // Step 2: Initialize visited
    for(i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Step 3: Topological Sort
    while(1) {
        int w = -1;

        for(i = 0; i < n; i++) {
            if(visited[i] == 0 && indegree[i] == 0) {
                w = i;
                break;
            }
        }

        if(w == -1) {
            break;
        }

        TP[tp_count++] = w;
        visited[w] = 1;

        for(i = 0; i < n; i++) {
            if(V[w][i] == 1) {
                indegree[i]--;
            }
        }
    }

    // Step 4: Check for cycle
    if(tp_count < n) {
        printf("No Topological Sequence (Cycle detected)\n");
    } else {
        printf("Topological Order:\n");
        for(i = 0; i < tp_count; i++) {
            printf("%d ", TP[i]);
        }
        printf("\n");
    }

    return 0;
}
