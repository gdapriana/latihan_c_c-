#include <stdio.h>
#include <stdbool.h>

int main() {
    int jumvertex;

    printf("Masukkan Jumlah Vertex: ");
    scanf("%d", &jumvertex);
    int graph[jumvertex][jumvertex];

    for (int i = 0; i < jumvertex; i++) {
        for (int j = 0; j < jumvertex; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                printf ("jika vertex %d dan vertex %d berhubungan, ketikkan 1, 0 jika tidak: ", i + 1, j + 1);
                scanf("%d", &graph[i][j]);
            }
        }
    }


    printf("\nTampilan Dalam Matriks Ketetanggaan: \n");
    for (int i = 0; i < jumvertex; i++) {
        for (int j = 0; j < jumvertex; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n"); 
    }
    printf("\n"); 

    // Pewarnaan Graf

    int color[jumvertex];
    color[0] = 0;
    bool colorUsed[jumvertex];
    for (int i = 1; i < jumvertex; i++) {
        color[i] = -1;
    }

    for (int i = 0; i < jumvertex; i++) {
        colorUsed[i] = false;
    }

    for (int u = 1; u < jumvertex; u++) {
        for (int v = 0; v < jumvertex; v++) {
            if (graph[u][v]) {
                if (color[v] != -1) {
                    colorUsed[color[v]] = true;
                }
            }
        }

        int col;
        for (col = 0; col < jumvertex; col++) 
            if (!colorUsed[col]) {
                break;
            }

            color[u] = col;

            for (int v = 0; v < jumvertex; v++) {
                if (graph[u][v]) {
                    if (color[v] != -1) {
                        colorUsed[color[v]] = false;
                    }
                }
            }
        
    }

    printf("Pewarnaan Vertex: \n");

    for (int u = 0; u < jumvertex; u++) {
        printf("Vertex: %d diisi oleh warna: %d\n", u + 1, color[u]);
    }
}
