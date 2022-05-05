#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 50

struct data {
    int pin, saldo;
    char nama[100];
};

int top = -1;

struct data nasabah[MAX];

void push() {
    if (top == MAX) {
        system("cls");
        puts("MAAF SERVER PENUH!!");
        sleep(2);
    } else {
        top++;
        printf("Masukkan Nama Anda: "); fflush(stdin);
        gets(nasabah[top].nama); 
        printf("Masukkan Pin: "); fflush(stdin);
        scanf("%d", &nasabah[top].pin); 
        printf("Masukkan Saldo Awal: Rp. "); fflush(stdin);
        scanf("%d", &nasabah[top].saldo);
        printf("\n\nNasabah Berhasil Ditambahkan");
        sleep(2);
    }
}

void pop() {
    if (top == -1) {
        puts("DATA KOSONG");
    } else {
        nasabah[top--];
        puts("Nasabah Terakhir Ditambahkan, berhasil dihapus");
        sleep(2);
    }
}

void searching() {

}

void view() {
    if(top == -1) {
        puts("DATA KOSONG");
        sleep(2);
    } else {
        puts("DAFTAR NASABAH");
        for (int i = top; i > -1; i--) {
            printf("Nama Nasabah: %s\n", nasabah[i].nama);
            printf("Pin: %d\n", nasabah[i].pin);
            printf("Saldo: Rp. %d\n", nasabah[i].saldo);
            printf("\n");
        }
        getch();
    }
}


int main() { 
    int pilih, pilihPOP;
    puts("1. Daftar Nasabah Baru");
    puts("2. Hapus nasabah");
    puts("3. Transfer");
    puts("4. Cari Nasabah");
    puts("5. Cetak Nasabah");
    printf("Pilih: ");
    scanf("%d", &pilih);
    
    if (pilih == 1) {
        system("cls");
        push();
        system("cls");
        return main();
    } else if (pilih == 2) {
        system("cls");
        puts("1. Hapus nasabah yang terakhir kali ditambahkan");
        puts("2. Hapus nasabah yang pertama kali ditambahkan");
        printf("pilih: ");
        scanf("%d", &pilihPOP);
        if (pilihPOP == 1) {
            system("cls");
            pop();
            system("cls");
            return main();
        }
    } else if (pilih == 4) {
        system("cls");
        searching();
        system("cls");
        return main();
    } else if (pilih == 5) {
        system("cls");
        view();
        system("cls");
        return main();
    }
}