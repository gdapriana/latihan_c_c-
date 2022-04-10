#include <stdio.h>

int main() {
    int nim;
    char nama[100], kelas;

    printf("Masukkan Nama   : ");
    scanf(" %[^\n]s", &nama);
    printf("Masukkan NIM    : ");
    scanf(" %d", &nim);
    printf("Masukkan Kelas  : ");
    scanf(" %c", &kelas);

    printf("\nNama    : %s\n", nama);
    printf("NIM     : %d\n", nim);
    printf("Kelas   : %c", kelas);
}