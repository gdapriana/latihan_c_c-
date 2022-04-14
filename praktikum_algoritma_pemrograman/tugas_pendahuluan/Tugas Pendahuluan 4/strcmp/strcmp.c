#include <stdio.h>

int main() { 
    system("cls");
    char kata1[100], kata2[100];
    int hasil;

    printf("Masukkan Kata 1: ");
    gets(kata1);
    printf("Masukkan Kata 2: ");
    gets(kata2);

    hasil = strcmp(kata1, kata2);
    printf("hasil = %d", hasil);
}