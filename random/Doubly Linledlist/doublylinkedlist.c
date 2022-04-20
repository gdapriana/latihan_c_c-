#include <stdio.h>
#include <stdlib.h>

struct tnode{
    struct tnode *prev;
    int NIM, nLogika, nAritmatika, nPemrograman;
    char nama[30];
    struct tnode *next;
};

struct tnode *head = NULL;
struct tnode *tail = NULL;

int isEmpty()
{
    if(tail == NULL) return 1;
    else return 0;
}

void header() {
    printf("--------------------------\n");
    printf("| PROGRAM DATA MAHASISWA |\n");
    printf("|   DOUBLE LINKED LIST   |\n");
    printf("--------------------------\n");
}

void footer() {
    system("cls");
    printf("|     Terima Kasih     |\n");
}

void menu();
void tambahData();
void hapusData();
void lihatData();
void rataLogika();

int main() {
    header();
    menu();
    footer();
    return 0;
}

void menu() {
    int pilMenu;

    do {
        printf("Menu:\n");
        printf("1. Tambah Data\n");
        printf("2. Hapus Data\n");
        printf("3. Tampilkan Data\n");
        printf("4. Rata - rata Nilai Logika\n");
        printf("5. Keluar\n");
        printf("Ketik pilihan anda : ");
        scanf("%d", &pilMenu);

        switch(pilMenu) {
            case 1: {
                system("cls");
                header();
                tambahData();
                break;
            }
            case 2: {
                system("cls");
                header();
                hapusData();
                break;
            }
            case 3: {
                system("cls");
                lihatData();
                break;
            }
            case 4: {
                system("cls");
                rataLogika();
                break;
            }
            default:
                printf("\nMohon maaf! Pilihan tidak ada pada menu\n");
        }
    } while(pilMenu != 5);
}

void tambahData() {
    struct tnode *dataBaru, *baru;
    dataBaru = (struct tnode*)malloc(sizeof(struct tnode));
    printf("Ketik NIM Mahasiswa   : ");
    scanf("%d", &dataBaru->NIM);fflush(stdin);
    printf("Ketik Nama Mahasiswa  : ");
    gets(dataBaru->nama);fflush(stdin);
    printf("Ketik Nilai Logika : ");
    scanf("%d", &dataBaru->nLogika);fflush(stdin);
    printf("Ketik Nilai Aritmatika : ");
    scanf("%d", &dataBaru->nAritmatika);fflush(stdin);
    printf("Ketik Nilai Pemrograman : ");
    scanf("%d", &dataBaru->nPemrograman);fflush(stdin);
    baru = dataBaru;
    baru->next = NULL;
    baru->prev = NULL;
    if(isEmpty() == 1) {
        head = baru;
        tail = head;
        head->next = NULL;
        head->prev = NULL;
        tail->next = NULL;
        tail->prev = NULL;
    } else{
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
        tail->next = NULL;
    }
    printf("\nData dari : \n");
    printf("NIM               : %d\n", baru->NIM);
    printf("Nama              : %s\n", baru->nama);
    printf("Nilai Logika      : %d\n", baru->nLogika);
    printf("Nilai Aritmatika  : %d\n", baru->nAritmatika);
    printf("Nilai Pemrograman : %d\n", baru->nPemrograman);
    printf("Telah ditambahkan\n");
}

void hapusData() {
    struct tnode *hapus;
    int bilHapus;

    if(isEmpty() == 0) {
        printf("Ketik NIM dari data yang ingin anda hapus : ");
        scanf("%d", &bilHapus);
        if(head->NIM == bilHapus) {
            if(head->next != NULL){
                hapus = head;
                head = head->next;
                head->prev = NULL;
            } else{
                head = NULL;
                tail = NULL;
            }
        } else if(tail->NIM == bilHapus){
            if(head->next != NULL) {
                hapus = tail;
                tail = tail->prev;
                tail->next = NULL;
            } else{
                head = NULL;
                tail = NULL;
            }
        } else{
            hapus = head;
            while(hapus->NIM != bilHapus){
                hapus = hapus->next;
            }
            hapus->prev->next = hapus->next;
            hapus->next->prev = hapus->prev;
            free(hapus);
        }
        printf("Data telah dihapus\n");
    } else{
        printf("Maaf! Data masih kosong\n");
    }
}

void lihatData() {
    struct tnode *bantu;
    bantu = head;
    if(isEmpty() == 0) {
        printf("-------------------------------------\n");
        printf("|         Menampilkan Data          |\n");
        printf("-------------------------------------\n");
        while(bantu != tail->next){
            printf("NIM                  : %d\n", bantu->NIM);
            printf("Nama                 : %s\n", bantu->nama);
            printf("Nilai Logika         : %d\n", bantu->nLogika);
            printf("Nilai Aritmatika     : %d\n", bantu->nAritmatika);
            printf("Nilai Pemrograman    : %d\n\n", bantu->nPemrograman);
            bantu = bantu->next;
        }
    } else{
        printf("\nMaaf! Data masih kosong\n");
    }
}

void rataLogika() {
    struct tnode *bantu;
    bantu = head;
    int jumlahNode = 0;
    float rata = 0, jumlahNilai = 0;

    while(bantu != tail->next) {
        jumlahNilai = jumlahNilai + bantu->nLogika;
        jumlahNode++;
        bantu = bantu->next;
    }
    rata = jumlahNilai / jumlahNode;
    printf("|                         Menampilkan Data                       |\n");
    printf("|   rata - rata dari nilai logika perlombaan adalah %.2f        |\n\n", rata);
}