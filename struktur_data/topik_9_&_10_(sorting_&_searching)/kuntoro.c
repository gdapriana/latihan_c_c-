#include <stdio.h>
#include <stdlib.h>

struct a{
    int n;
    struct a *next;
}*h;

struct a *kembalikanAlamat(struct a *bantu, int nomor) {
    for(int i=0; i<nomor; i++) {
        bantu=bantu->next;
    }
    return bantu;
};

void tampolData(struct a *tampol) {
    printf("Data dalam linked list : ");
    while(tampol){
        printf("%d\t", tampol->n);
        tampol=tampol->next;
    }
    printf("\n");
}

int kembalikanJumlah(struct a *bantu){
    int jum=0;
    while(bantu) {
        jum++;
        bantu=bantu->next;
    }
    return jum;
}

void insertDataYuk(int data, struct a *bantukyak) {
    struct a *help;
    if(bantukyak->n>data) {
        help=(struct a*)malloc(sizeof(struct a));
        help->n=data;
        help->next=bantukyak;
        h=help;
    } else {
        while(bantukyak->next!=NULL) {
            if(bantukyak->n<data){
                if(bantukyak->next->n>data) {
                    help=bantukyak->next;
                    bantukyak->next=(struct a*)malloc(sizeof(struct a));
                    bantukyak->next->n=data;
                    bantukyak->next->next=help;
                }
            }
            bantukyak=bantukyak->next;
        }
    }
}

int bagiDuaYes(int data, struct a *bantukuy) {
    struct a *help;
    int l=0;
    int r=kembalikanJumlah(bantukuy);
    int ketemu=0;
    int m=(l+r)/2;
    while(l<=r && !ketemu) {
        m=(l+r)/2;
        help=kembalikanAlamat(bantukuy,m);
        if(data>help->n) {
            l=m+1;
        }
        if(data==help->n) {
            ketemu=1;
            return 1;
        }
        if(data<help->n){
            r=m-1;
        }
    }
    insertDataYuk(data,bantukuy);
return 0;
}

void tampolDataArray(int arrayku[], int jumlahkuy) {
    printf("Data dalam array : ");
    for(int z=0; z<jumlahkuy; z++) {
        printf("%d\t", arrayku[z]);
    }
    printf("\n");
}

void insArr(int data, int indeks, int arr[], int *jumlahkuy) {
    int i;
    int temp;
    if(data<arr[indeks]) {
        i=indeks;
    }
    if(data>arr[indeks]) {
        i=indeks+1;
    }
    int temp1=arr[i];
    arr[i]=data;
    while(arr[i]) {
        temp=arr[i+1];
        arr[i+1]=temp1;
        temp1=temp;
        i++;
    }
(*jumlahkuy)++;
}

int searchArrayku(int arraylah[], int datakuy, int *jumlahkuy) {
    int l=0;
    int r=*jumlahkuy-1;
    int ketemu=0;
    int m;
    while((l<=r)&&(!ketemu)) {
        m=(l+r)/2;
        if(datakuy>arraylah[m])
    l=m+1;
    if(datakuy==arraylah[m])
    ketemu=1;
    if(datakuy<arraylah[m])
        r=m-1;
    }
    if(ketemu==0){
        insArr(datakuy,m,arraylah,jumlahkuy);
    }
return ketemu;
}

int main(){
//pendefinisian single linked list
    printf("Jonas Kuntoro || D || 1908561069\n\n");
    printf("\nBAGIAN INI KHUSUS UNTUK SINGLE LINKED LIST !\n");
    struct a *satu=(struct a*)malloc(sizeof(struct a)); satu->n=2;
    struct a *dua=(struct a*)malloc(sizeof(struct a)); dua->n=3;
    struct a *tiga=(struct a*)malloc(sizeof(struct a)); tiga->n=5;
    struct a *empat=(struct a*)malloc(sizeof(struct a)); empat->n=7;
    struct a *lima=(struct a*)malloc(sizeof(struct a)); lima->n=11;
    h=satu;
    h->next=dua;
    h->next->next=tiga;
    h->next->next->next=empat;
    h->next->next->next->next=lima;
    h->next->next->next->next->next=NULL;
    //pendefinisian single linked list
    tampolData(h);
    printf("Data 1 : %d\n", bagiDuaYes(1,h));
    printf("Data 2 : %d\n", bagiDuaYes(2,h));
    printf("Data 6 : %d\n", bagiDuaYes(6,h));
    printf("Data 7 : %d\n", bagiDuaYes(7,h));
    printf("Data 8 : %d\n", bagiDuaYes(10,h));
    tampolData(h);
    
    printf("\nBAGIAN INI KHUSUS UNTUK ARRAY !\n");
    int arrayku[100];
    arrayku[0]=2; arrayku[1]=3; arrayku[2]=5; arrayku[3]=7; arrayku[4]=11;
    int narrayku=5;
    tampolDataArray(arrayku,narrayku);
    printf("Data 1 : %d\n", searchArrayku(arrayku,1,&narrayku));
    printf("Data 2 : %d\n", searchArrayku(arrayku,2,&narrayku));
    printf("Data 6 : %d\n", searchArrayku(arrayku,6,&narrayku));
    printf("Data 7 : %d\n", searchArrayku(arrayku,7,&narrayku));
    printf("Data 8 : %d\n", searchArrayku(arrayku,8,&narrayku));
    tampolDataArray(arrayku,narrayku);
}