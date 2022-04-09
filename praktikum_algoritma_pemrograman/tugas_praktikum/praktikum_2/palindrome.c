#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    system("cls");
    int pilih;
    printf("\n\t   --------------\n");
    printf("\t   | PALINDROME |\n");
    printf("\t   |   APRIANA  |\n");
    printf("\t   | 2108561031 |\n");
    printf("\t   --------------\n");
    printf("\n\tMENU: \n");
    printf("\t1. Cek Palindrome Kata\n");
    printf("\t2. Cek Palindrome Angka\n");
    printf("\t3. Keluar\n");
    printf("\tPilih: ");
    scanf("%d", &pilih);
    fflush(stdin);

    switch (pilih) {
    case 1:
        system("cls");
        char kata[100];
        bool palindrome = true;

        printf("\n\t-------------------\n");
        printf("\t| PALINDROME KATA |\n");
        printf("\t-------------------\n");
        printf("\tMasukkan Satu/Lebih Kata: ");
        gets(kata);

        int panjangKata = strlen(kata);
        int belakangKata = panjangKata - 1;

        for(int a = 0; a < panjangKata; a++) {
            if((char)tolower(kata[a])!=(char)tolower(kata[belakangKata])) {
                palindrome = false;
                break;
            }
            belakangKata--;
        }

        printf("\n\tKata Sebelum dibalik: %s\n", kata);
        printf("\tKata Setelah Dibalik: ");
        for (int i = panjangKata; i >= 0; i--) {
            printf("%c", kata[i]);
        }
        printf("\n\n");

        if(palindrome) {
            printf("\tKata %s Merupakan PALINDROME\n", kata);
        } else {
            printf("\tKata %s BUKAN PALINDROME\n", kata);
        }
        sleep(3);
        break;
    case 2:
        system("cls");
        int n, reversed = 0, remainder, original;
        printf("\n\t--------------------\n");
        printf("\t| PALINDROME ANGKA |\n");
        printf("\t--------------------\n");
        printf("\tMasukkan Beberapa Angka: ");
        scanf("%d", &n);
        original = n;

        while (n != 0) {
            remainder = n % 10;
            reversed = reversed * 10 + remainder;
            n /= 10;
        }

        printf("\n\tAngka Sebelum Dibalik: %d\n", original);
        printf("\tAngka Setelah Dibalik: %d\n\n", reversed);

        if (original == reversed) {
            printf("\tAngka %d Merupakan PALINDROME\n", original);
        } else {
            printf("\tAngka %d BUKAN PALINDROME\n", original);
        }
        
        sleep(3);
        break;
    case 3:
        system("cls");
        printf("\n\t-------------\n");
        printf("\t| GOOD BYE! |\n");
        printf("\t-------------\n");
        sleep(3);
        return 0;
        break;
    default:
        system("cls");
        printf("\n\t-------------------\n");
        printf("\t| INPUTAN INVALID |\n");
        printf("\t-------------------\n");
        sleep(3);
        return main();
        break;
    }
}
