#include <stdio.h>

int main() { 
    char data[50];

    FILE *fp;
    fp = fopen("data.txt", "w");
    for(int i = 0; i < 5; i++) {
        printf("Masukkan data ke %d: ", i + 1);
        gets(data);
        fprintf(fp, "%s\n", data);
    }
    fclose(fp);
    printf("Data berhasil dicetak");
    return 0;
}