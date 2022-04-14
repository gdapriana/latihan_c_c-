#include <stdio.h>

int main() { 
    system("cls");
    char huruf1 = 'A';
    char huruf2 = 'a';

    printf("%c = %d\n", huruf1, isupper(huruf1));
    printf("%c = %d", huruf2, isupper(huruf2));

}