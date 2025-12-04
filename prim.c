#include <stdio.h>

#define INF 99999

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];
    int selected[n]; // 0 for False, 1 for True

    // Initialize selected array to 0 (False)
    for (int i = 0; i < n; i++) selected[i] = 0;

    printf("\nEnter Adjacency Matrix (Use 0 for no edge, or value > %d):\n", INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Prim's Algorithm Logic
    int num_edge = 0;
    int total_weight = 0;
    selected[0] = 1; // Start with the first vertex

    printf("\nMinimum Spanning Tree Edges:\n");
    while (num_edge < n - 1) {
        int min = INF;
        int x = 0, y = 0;

        for (int i = 0; i < n; i++) {
            if (selected[i]) { // If node i is part of the MST
                for (int j = 0; j < n; j++) {
                    // If node j is NOT selected, AND edge exists, AND it's smaller than current min
                    if (!selected[j] && graph[i][j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, graph[x][y]);
        selected[y] = 1; // Mark node y as selected
        num_edge++;
        total_weight += graph[x][y];
    }

    printf("Total Weight: %d\n", total_weight);

    return 0;
}