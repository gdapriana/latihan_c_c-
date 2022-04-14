#include <stdio.h>
#include <string.h>

int main() { 
    system("cls");
    char nama[100];
    printf("Masukkan Nama: ");
    gets(nama);
    printf("%s", strupr(nama));
}