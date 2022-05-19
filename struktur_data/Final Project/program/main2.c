#include <stdio.h>
#include <stdbool.h>
#define MAX_STACK 50

// ADT (abstract data type)




---
int menu() {
    int pilih;
    puts("\n\t-----------------------------------------");
    puts("\t|\t\tPROGRAM ATM\t\t|");
    puts("\t-----------------------------------------");
    puts("\n\t\tMENU:");
    puts("\n\t\t1. DAFTAR NASABAH BARU");
    puts("\t\t2. HAPUS NASABAH"); //menggunakan fungsi stack dan queue
    puts("\t\t3. TRANSFER");
    puts("\t\t4. NABUNG");
    puts("\t\t5. TARIK");
    puts("\t\t6. CARI BASABAH"); // menggunakan sequensial search
    puts("\t\t7. CETAK NASABAH"); //menggunakan bubble sort (berdasarkan nama / jumlah saldo)
    puts("\t\t8. EXIT\n");
    printf("\t\tPILIH[1-8]: ");
    scanf("%d", &pilih);
    return pilih;
}

int main() { 
    int pilih = menu();

    switch (pilih) {
        case 1:
            printf("case 1");
            break;
        case 2:
            printf("case 2");
            break;
        case 3:
            printf("case 3");
            break;
        case 4:
            printf("case 4");
            break;
        case 5:
            printf("case 5");
            break;
        case 6:
            printf("Haii 6");
            break;
        case 7:
            printf("Haii 7");
            break;
        case 8:
            system("cls");
            puts("\n\t---------------------------------------------");
            puts("\t| TERIMAKASIH SUDAH MENGGUNAKAN PROGRAM INI |");
            puts("\t---------------------------------------------");
            sleep(2);
            return 0;
            break;
        default:
            system("cls");
            puts("\n\t-------------------");
            puts("\t| INPUTAN INVALID |");
            puts("\t-------------------");
            sleep(2);
            system("cls");
            return main();
            break;
    }
}