#include <stdio.h>
#include <stdlib.h>

struct a{
    int n;
    struct a *next;
}*h;

struct a *kembalikanAlamat(struct a *bantu, int nomor) {
    for(int i = 0; i < nomor; i++) {
        bantu = bantu -> next;
    }
    return bantu;
};

void tampolData(struct a *tampol) {
    printf("Data dalam linked list: ");
    while(tampol) {
        printf("%d\t", tampol -> n);
        tampol = tampol -> next;
    }
    printf("\n");
}

int kembalikanJumlah(struct a *bantu) {
    int jum = 0;
    while(bantu) {
        jum++;
        bantu = bantu ->next;
    }
    return jum;
}

void insertData(int data, struct a *bantukyak) {
    struct a *help;
    if (bantukyak -> n > data) {
        help = (struct a*) malloc (sizeof(struct a));
        help -> n = data;
        help -> next = bantukyak;
        h = help;
    } else {
        while(bantukyak -> next != NULL) {
            if(bantukyak -> n < data) {
                if(bantukyak -> next -> n > data) {
                    help = bantukyak -> next;
                    bantukyak -> next = (struct a*) malloc (sizeof(struct a));
                    bantukyak -> next -> n = data;
                    bantukyak -> next -> next = help;
                }
            }
            bantukyak = bantukyak -> next;
        }
    }
}

int bagiDua(int data, struct a *bantukuy) {
    struct a *help;
    int l = 0;
    int r = kembalikanJumlah(bantukuy);
    int ketemu = 0;
    int m = (l + r) / 2;
    while(l <= r && !ketemu) {
        m = (l + r) / 2;
        help = kembalikanAlamat(bantukuy, m);
        if(data > help -> n) {
            l = m + 1;
        }
        if(data == help -> n) {
            ketemu = l;
            return l;
        }
        if(data < help -> n) {
            r = m - 1;
        }
    }
    insertData(data, bantukuy);
    return 0;
}

void tampolDataArray(int myArray[], int jumlah) {
    printf("Data dalam Array: ");
    for(int z = 0; z < jumlah; z++) {
        printf("%d\t", myArray[z]);
    }
    printf("\n");
}

void inputArray(int data, int index, int arr[], int *jumlah) {
    int i;
    int temp;
    if(data < arr[index]) {
        i = index + 1;
    }
    int tempA = arr[i];
    arr[i] = data;
    while(arr[i]) {
        temp = arr[i+1];
        arr[i+1] = tempA;
        tempA = temp;
        i++;
    }
    (*jumlah)++;
}

int searcMyArray(int arr[], int data, int *jumlah) {
    int l = 0;
    int t = *jumlah - 1;
    int ketemu = 0;
    int a;

    while((l <= t) && (!ketemu))  {
        a = (l + t) / 2;
        if(data > arr[a]) {
            l = a + 1;
        } 
        if(data == arr[a]) {
            ketemu = l;
        } 
        if(data < arr[a]) {
            t = a - 1;
        }
    }

    if(ketemu == 0) {
        inputArray(data, a, arr, jumlah);
    }
    return ketemu;
}

int main() { 
    printf("SINGLE LINK LIST\n");\
    struct a *satu = (struct a*) malloc (sizeof(struct a));
    satu -> n = 2;
    struct a *dua = (struct a*) malloc (sizeof(struct a));
    dua -> n = 3;
    struct a *tiga = (struct a*) malloc (sizeof(struct a));
    tiga -> n = 5;
    struct a *empat = (struct a*) malloc (sizeof(struct a));
    empat -> n = 7;
    struct a *lima = (struct a*) malloc (sizeof(struct a));
    lima -> n = 11;

    h = satu;
    h -> next = dua;
    h -> next -> next = tiga;
    h -> next -> next -> next = empat;
    h -> next -> next -> next -> next = lima;
    h -> next -> next -> next -> next -> next = NULL;

    tampolData(h);
    printf("Data 1: %d\n", bagiDua(1, h));
    printf("Data 2: %d\n", bagiDua(2, h));
    printf("Data 6: %d\n", bagiDua(6, h));
    printf("Data 7: %d\n", bagiDua(7, h));
    printf("Data 8: %d\n", bagiDua(10, h));
    tampolData(h);

    printf("\nARRAY\n");
    int arr[100];
    arr[0] = 2; arr[1] = 3; arr[2] = 5; arr[3] = 7; arr[4] = 11;
    int n = 5;

    tampolDataArray(arr, n);
    printf("Data 1: %d\n", searcMyArray(arr, 1, &n));
    printf("Data 2: %d\n", searcMyArray(arr, 2, &n));
    printf("Data 6: %d\n", searcMyArray(arr, 6, &n));
    printf("Data 7: %d\n", searcMyArray(arr, 7, &n));
    printf("Data 8: %d\n", searcMyArray(arr, 8, &n));
    tampolDataArray(arr, n);
}