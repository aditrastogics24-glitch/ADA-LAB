#include <stdio.h>

#define MAX 10
#define INF 9999

int main() {
    int n, a[MAX][MAX];
    int d[MAX], p[MAX], s[MAX];
    int i, j, source, u, min;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if(a[i][j] == 0)
                a[i][j] = INF;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    // Initialization
    for(i = 0; i < n; i++) {
        d[i] = a[source][i];
        p[i] = source;
        s[i] = 0;
    }

    d[source] = 0;
    s[source] = 1;

    // Main algorithm
    for(i = 1; i < n; i++) {
        min = INF;

        for(j = 0; j < n; j++) {
            if(s[j] == 0 && d[j] < min) {
                min = d[j];
                u = j;
            }
        }

        s[u] = 1;

        for(j = 0; j < n; j++) {
            if(s[j] == 0 && d[u] + a[u][j] < d[j]) {
                d[j] = d[u] + a[u][j];
                p[j] = u;
            }
        }
    }

    // Output
    printf("\nVertex\tDistance\tPath\n");

    for(i = 0; i < n; i++) {
        printf("%d\t%d\t\t", i, d[i]);

        int path[MAX], k = 0, v = i;

        while(v != source) {
            path[k++] = v;
            v = p[v];
        }
        path[k++] = source;

        for(j = k - 1; j >= 0; j--) {
            printf("%d", path[j]);
        }

        printf("\n");
    }

    return 0;
}
