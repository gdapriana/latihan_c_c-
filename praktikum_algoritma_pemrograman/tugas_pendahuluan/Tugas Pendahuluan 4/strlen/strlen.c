#include <stdio.h>

int main() { 
    system("cls");
    char nama[100];

    printf("Masukkan nama: ");
    gets(nama);

    printf("jumlah huruf %d\n", strlen(nama));
}