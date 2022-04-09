#include <stdio.h>

int main() {
    const float phi = 3.14;
    int r, l, k;

    printf("PROGRAM LUAS DAN KELILING LINGKARAN\n\n");
    
    printf("Masukkan Jari-jari: ");
    scanf("%d", &r);

    l = phi * (r * r);

    k = 2 * phi * r;

    printf("\nLuas Lingkaran dengan jari-jari %d adalah %d\n", r, l);
    printf("Keliling Lingkaran dengan jari-jari %d adalah %d\n", r, k);
}