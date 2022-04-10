#include <stdio.h>
#include <stdbool.h>
#define NODE 8

int graph[NODE][NODE] = {
//   A  B  C  D  E  F  G  H
    {0, 1, 0, 0, 0, 0, 0, 1}, // A
    {1, 0, 1, 0, 0, 0, 1, 1}, // 1
    {0, 1, 0, 1, 0, 0, 1, 0}, // C
    {0, 0, 1, 0, 1, 0, 0, 0}, // D
    {0, 0, 0, 1, 0, 1, 1, 0}, // E
    {0, 0, 0, 0, 1, 0, 1, 0}, // F
    {0, 1, 1, 0, 1, 1, 0, 1}, // G                                            
    {1, 1, 0, 0, 0, 0, 1, 0}  // H
};

void graphColoring() {
    int color[NODE];
    color[0] = 0;
    bool colorUsed[NODE];

    for (int i = 1; i < NODE; i++) {
        color[i] = -1;
    }

    for (int i = 0; i < NODE; i++) {
        colorUsed[i] = false;
    }

    for (int u = 1; u < NODE; u++) {
        for (int v = 0; v < NODE; v++) {
            if (graph[u][v]) {
                if (color[v] != -1) {
                    colorUsed[color[v]] = true;
                }
            }
        }

        int col;
        for (col = 0; col < NODE; col++) 
            if (!colorUsed[col]) {
                break;
            }

            color[u] = col;

            for (int v = 0; v < NODE; v++) {
                if (graph[u][v]) {
                    if (color[v] != -1) {
                        colorUsed[color[v]] = false;
                    }
                }
            }
        
    }

    for (int u = 0; u < NODE; u++) {
        printf("Simpul: %d diisi oleh warna: %d\n", u, color[u]);
    }
}
    


int main() {
    graphColoring();
}