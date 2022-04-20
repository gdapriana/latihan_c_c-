#include <stdio.h>
#define max 4

struct data {
    char nim[10], nama[100];
    float IPK;
};

int main() { 
    struct data mahasiswa[max];

    for(int i = 0; i < max; i++) {
        printf("Data Mahasiswa ke-[%d]\n", i + 1);
        printf("Masukkan Nama: ");
        gets(mahasiswa[i].nama);
        printf("Masukkan NIM: ");
        gets(mahasiswa[i].nim);
        printf("Masukkan IPK: ");
        scanf("%f", &mahasiswa[i].IPK);
        printf("\n");
        fflush(stdin);
    }

    printf("TAMPILKAN DATA MAHASISWA\n");
    for(int i = 0; i < max; i++) {
        printf("Data Mahasiswa ke-[%d]\n", i + 1);
        printf("Nama: %s\n", mahasiswa[i].nama);
        printf("NIM: %s\n", mahasiswa[i].nim);
        printf("IPK: %.2f\n", mahasiswa[i].IPK);
        printf("\n");
    }
}