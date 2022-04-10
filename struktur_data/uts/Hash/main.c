#include <stdio.h>
#include <stdlib.h>

struct data {
    int key;
    int IP;
};

struct data *array;

int kapasitas = 10;
int size = 0;

char* nama[10] = {"Apriana", "Sutrisna", "Duta", "Bayu", "Burhan", "ilham", "Adi", "Agung", "James", "Zeeke"};

char* tempat[10] = {"Kelas AS", "Kelas BD", "Kelas CM", "Kelas DG", "Kelas EQ", "Gedung Informatika", "Gedung Matematika", "Gedung Fisika", "Gedung Kimia", "Gedung Biologi"};

int fungsiHash(int key) {
    return (key % kapasitas);
}

void init_array() {
    array = (struct data *)malloc(kapasitas * sizeof(struct data));
    for(int i = 0; i < kapasitas; i++) {
        array[i].key = 0;
        array[i].IP = 0;
    }
}

void insert(int key, int IP) {
    int index = fungsiHash(key);
    if(array[index].IP == 0) {
        array[index].key = key;
        array[index].IP = IP;
        size++;
        printf("\n\tKey (%d) Sudah Dimasukkan \n", key);
    } else if(array[index].key == key) {
        array[index].IP = IP;
    }
}

void remove_data(int key) {
    int index = fungsiHash(key);
    if(array[index].IP == 0) {
        printf("\n\tKey ini tidak ada\n");
    } else {
        array[index].key = 0;
        array[index].IP = 0;
        size--;
        printf("\n\tKey (%d) sudah dihapus\n", key);
    }
}

void display() {
    int i;
    for(i = 0; i < kapasitas; i++) {
        if(array[i].IP == 0) {
            printf("\n\tIndex ke-[%d]: \n", i);
        } else {
            int p = rand()%10;
            printf("\n\tKey: %d | IP: %d | Nama User: %s | Letak Komputer: %s\n", array[i].key, array[i].IP, nama[p], tempat[p]);
        }
    }
}

int main() {
    int pilihan, key, IP, n;
    int c = 0;
    int p = rand()%10;
    init_array();
    int ulang = 0;

    do {
        system("cls");
        printf("\n\t------------------------------");
        printf("\n\t|       PROGRAM HASH IP      |");
        printf("\n\t|    I Komang Gede Apriana   |");
        printf("\n\t|          2108561031        |");
        printf("\n\t------------------------------\n");
        printf("\n\t1. Tambahkan Item ke Hash Table");
        printf("\n\t2. Hapus Item dari Hash Table");
        printf("\n\t3. Tampilkan Hash Table");
        printf("\n\t4. Exit\n");
        printf("\tMasukkan Pilihan Anda: ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1:
                system("cls");
                printf("\n\tMasukkan Key: ");
                scanf("%d", &key);
                printf("\tMasukkan IP (Tanpa Titik): ");
                scanf("%d", &IP);
                insert(key, IP);

                printf("\n\tItem Berhasil Ditambahkan!!");
                sleep(3);
            break;

            case 2:
                system("cls");
                printf("\n\tMasukkan Key Untuk Dihapus: ");
                scanf("%d", &key);
                remove_data(key);
            break;

            case 3:
                system("cls");
                display();
            break;

            case 4:
                system("cls");
                printf("\n\tTerimakasih sudah menggunakan Program\n\n");
                sleep(3);
                return 0;
            break;

            default:
                printf("\n\tINPUTAN INVALID!!\n");
                sleep(3);
            break;
        }

        printf("\n\tKembali Ke Menu? [1.Yes, 2. No]: ");
        scanf("%d", &ulang);
    } while(ulang == 1);
    return 0;
}