#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void enkripsi(char*kalimat, int shift) {
    int i;
    for(i = 0; i < strlen(kalimat); i++) {
        if(kalimat[i] != 32) {
            kalimat[i] += shift;
            if((kalimat[i] > 90 && kalimat[i] < 97)||kalimat[i] > 122) {
                kalimat[i] -= 26;
            }
        }
    }
}

int main() {
    char kalimat[100];
    int shift;

    printf("Masukkan String  :");
    scanf("%[^\n]s", &kalimat);

    printf("Masukkan Shift   : ");
    scanf("%d", &shift);

    enkripsi(kalimat,shift);
    printf("Hasil Shift      : %s",kalimat);
    return 0;
}