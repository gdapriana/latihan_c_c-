#include <stdio.h>

int main() {
    int umur = 20;

    if (umur >= 18) {
        printf ("Kamu Sudah Dewasa");
    } else if (umur < 18 && umur >= 12) {
        printf ("Kamu Masih Remaja");
    } else {
        printf("Kamu masih kecil");
    }
}