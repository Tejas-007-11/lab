#include <stdio.h>

#define INF 99
#define MAX 100

int p[MAX], c[MAX][MAX], t[MAX][2];

int find(int v) {
    while (p[v])
        v = p[v];
    return v;
}

void union1(int i, int j) {
    p[j] = i;
}

void kruskal(int n) {
    int i, j, k, u, v, min, res1, res2, sum = 0;
    for (k = 1; k < n; k++) {
        min = INF;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (i == j)
                    continue;
                if (c[i][j] < min) {
                    u = find(i);
                    v = find(j);
                    if (u != v) {
                        min = c[i][j];
                        res1 = i;
                        res2 = j;
                    }
                }
            }
        }
        union1(find(res1), find(res2));
        t[k][0] = res1;
        t[k][1] = res2;
        sum = sum + min;
        c[res1][res2] = c[res2][res1] = INF; // Mark the edge as used
    }

    printf("\nCost of spanning tree is = %d\n", sum);
    printf("\nEdges of spanning tree are:\n");
    for (i = 1; i < n; i++)
        printf("%d -> %d\n", t[i][0], t[i][1]);
}

int main() {
    int i, j, n;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
            if (c[i][j] == 0) {
                c[i][j] = INF;
            }
        }
    }

    kruskal(n);
    return 0;
}
