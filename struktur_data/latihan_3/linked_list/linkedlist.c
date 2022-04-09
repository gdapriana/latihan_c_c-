#include <stdio.h>
#include <conio.h>

struct node {
    int data;
    struct node* next;
};

struct node* head;
struct node* tail;
struct node* curr;
struct node* entry;
struct node* del;

void inisialisasi() {
    head = NULL;
    tail = NULL;
}

void input(int dt) {
    entry = (struct node* )malloc(sizeof(struct node));
    entry -> data = dt;
    entry -> next = NULL;

    if (head == NULL) {
        head = entry;
        tail = head;
    } else {
        tail -> next = entry;
        tail = entry;
    }
}

void hapus() {
    int simpan;
    if (head == NULL) {
        printf("\nLinked List kosong. Penghapusan tidak bisa dilakukan!!\n");
    } else {
        simpan = head -> data;
        del = head;
        head = head -> next;
        free(del);

        printf("\nData yang dihapus adalah %d\n", simpan);
    }
}

void cetak() {
    curr = head;
    if (head == NULL) {
        printf("\nTidak ada data dalam Linked List\n");
    } else {
        printf("\nData yang ada dalam Linked List adalah\n");
        while (curr != NULL) {
            printf("%d -> ", curr -> data);
            curr = curr -> next;
        }
        printf("NULL\n");
    }
}

void menu() {
    char pilih, ulang;
    int data;

    do {
        system("cls");
        printf("LINKED LIST PROGRAM\n");
        printf("===================\n");
        printf("Menu: \n");
        printf("1. Input Data\n");
        printf("2. Hapus Data\n");
        printf("3. Cetak Data\n");
        printf("4. Exit\n");
        printf("Masukkan Pilihan Anda: ");
        scanf("%c", &pilih);

        switch (pilih) {
        case '1':
            printf("\nMasukkan Data: ");
            scanf("%d", &data);
            input(data);
            break;
        case '2':
            hapus();
            break;
        case '3':
            cetak();
            break;
        case '4':
            exit(0);
            break;
        default:
            printf("\nPilih Ulang\n");
        }
        printf("\nKembali Ke Manu? (y/n)");
        scanf("%s", &ulang);
        fflush(stdin);
    } while (ulang == 'y' || ulang == 'Y');
}

int main() {
    inisialisasi();
    menu();

    return 0;
}
