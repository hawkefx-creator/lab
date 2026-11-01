/* A-6 */
PART A – 6
   Graph of Cities using Adjacency Matrix, DFS and BFS
   ============================================================ */

#include <stdio.h>

#define MAX 20

int a[MAX][MAX], n, visited[MAX];
char city[MAX][30];

void dfs(int v) {
    int i;

    visited[v] = 1;
    printf("%s ", city[v]);

    for (i = 0; i < n; ++i)
        if (a[v][i] && !visited[i])
            dfs(i);
}

void bfs(int start) {
    int q[MAX], f = 0, r = 0, i, v;

    for (i = 0; i < n; ++i)
        visited[i] = 0;

    q[r++] = start;
    visited[start] = 1;

    while (f < r) {
        v = q[f++];
        printf("%s ", city[v]);

        for (i = 0; i < n; ++i)
            if (a[v][i] && !visited[i]) {
                visited[i] = 1;
                q[r++] = i;
            }
    }
}

int main(void) {
    int i, j, ch, s;

    printf("Number of cities (max %d): ", MAX);
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        puts("Invalid number.");
        return 1;
    }

    for (i = 0; i < n; ++i) {
        printf("City %d name: ", i);
        scanf("%29s", city[i]);
    }

    puts("Enter adjacency matrix (0/1), row by row:");

    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            scanf("%d", &a[i][j]);

    puts("Adjacency matrix:");

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j)
            printf("%d ", a[i][j]);

        putchar('\n');
    }

    printf("Starting node index (0 to %d): ", n - 1);
    scanf("%d", &s);

    if (s < 0 || s >= n) {
        puts("Invalid starting node.");
        return 1;
    }

    do {
        puts("\n1.DFS 2.BFS 3.Exit");
        printf("Choice: ");
        scanf("%d", &ch);

        for (i = 0; i < n; ++i)
            visited[i] = 0;

        if (ch == 1) {
            printf("DFS reachable nodes: ");
            dfs(s);
            putchar('\n');
        }
        else if (ch == 2) {
            printf("BFS reachable nodes: ");
            bfs(s);
            putchar('\n');
        }
        else if (ch == 3)
            puts("Exiting.");
        else
            puts("Invalid choice.");

    } while (ch != 3);

    return 0;
}


/* ============================================================
