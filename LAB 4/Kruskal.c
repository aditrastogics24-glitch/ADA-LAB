#include <stdio.h>

#define MAX 10
#define INF 999

int parent[MAX];

// Find set (root of vertex)
int find(int i) {
    while (parent[i] != 0)
        i = parent[i];
    return i;
}

// Union of two sets
int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int n, cost[MAX][MAX];
    int i, j, min, mincost = 0;
    int a, b, u, v, ne = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = INF; // no edge
        }
    }

    // Initialize parent array
    for(i = 0; i < n; i++) {
        parent[i] = 0;
    }

    printf("\nEdges selected:\n");

    // Repeat until n-1 edges
    while(ne < n - 1) {
        min = INF;

        // Find minimum edge
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        // Find roots
        u = find(u);
        v = find(v);

        // If no cycle, include edge
        if(uni(u, v)) {
            printf("%d - %d = %d\n", a, b, min);
            mincost += min;
            ne++;
        }

        // Remove edge
        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}
