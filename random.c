#include <stdio.h>
#include <stdbool.h>

int main() { 
    
    int data[10] = {1,2,3,4,5,90,76,43,67,8};
    int cari;
    bool temu = false;

    printf("Masukkan data yang ingin di cari: ");
    scanf("%d", &cari);

    for(int i = 0; i < sizeof(data); i++) {
        if(data[i] == cari) {
            temu = true;
            break;
        }
    }

    if(temu == true) {
        printf("\nData Ditemukan!!\n");
    } else {
        printf("\nData Tidak Ditemukan!!\n");
    }
}