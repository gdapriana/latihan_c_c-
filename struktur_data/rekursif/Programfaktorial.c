#include <stdio.h>

int faktorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * faktorial(n-1)
    }
}

int main() {
    int bil;
    printf("Masukkan Nilai: ");
    scanf("%d", &bil);
    printf("Hasil dari faktorial %d adalah %d", bil, faktorial(bil));
}