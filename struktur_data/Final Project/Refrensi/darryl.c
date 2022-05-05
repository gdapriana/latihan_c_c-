#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define size 2

int hash[size];
int i,hasil=-1;
int simp,num;
int key,z,e,f,g,h,p=0,u,x,c1,depo,pilihan;
int t=0,t1=0;
int A[50];
int temp,temp2;
int g1,g2;

struct StackNode {
	int data;
	struct StackNode* next;
};

struct StackNode* newNode(int data) {
	struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode;
}

int isEmpty(struct StackNode* root) {
	return !root;
}

void push(struct StackNode** root, int data) {
	struct StackNode* stackNode = newNode(data);
	stackNode->next = *root;
	*root = stackNode;
}

int pop(struct StackNode** root) {
	if (isEmpty(*root)) {
		return INT_MIN;
    }
	struct StackNode* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);
	return popped;
}

int peek(struct StackNode* root) {
	if (isEmpty(root)) {
		return INT_MIN;
    }
	return root->data;
}

struct fake {
    int fake1;
    int fake2;
}hehe[50];

struct Database {
    int b;
    int c;
    int pin1;
    int pin;
    int temp;
    int temp1;
    int d;
    int saldo;
    long long nomer;
    int riwayat1;
    int riwayat;
    char c23;
    char code[50];
} data[50];

struct data {
    int x;
    struct data* next;
}*head=NULL,*tail=NULL, *curr, xx;

int pushbelakang(int x) {
    curr = (struct data*)malloc(sizeof(struct data));
    curr->x = x;
    if(head == NULL) {
        head = tail = curr;
    } else {
        tail-> next = curr;
        tail = curr;
    }
    tail->next = NULL;
}

void printll() {
    curr=head;
    while(curr!=NULL) {
        printf("%d\n",curr->x);
        curr=curr->next;
    }
    printf("\n");
    if(head==NULL) {
        printf("\n kosong\n");
    }
    return main();
}

void gantipin() {
    int a;
    puts("========== GANTI PIN ==========");
    p=0;
    inspin();
    pinbaru();
}

void pinbaru() {
    printf("Masukan PIN baru anda : ");
    scanf("%d",&data->temp);
    printf("Konfirmasi PIN baru anda : ");
    scanf("%d",&data->temp1);
    if(data->temp == data->temp1){
        puts("PIN Baru terkonfirmasi");
        data[z].pin1 = data->temp;
    } else {
        puts("PIN baru salah");
        return gantipin();
    }
    puts("PIN telah terganti");
    FILE *fg;
    fg = fopen("pin1.txt","w");
    for(i=0;i<size;i++){
        fprintf(fg,"%lld %d %d\n",data[i].nomer,data[i].pin1,data[i].saldo);
    }
    fclose(fg);
    remove("pin.txt");
    rename("pin1.txt","pin.txt");
}

void ngirim() {
    int a = 0;
    printf("Masukan Nomor bank tujuan anda : ");
    scanf("%d",&a);
    fflush(stdin);
    search1(a);
    fflush(stdin);
}

void transfer() {
    int y,l;
    puts("========Transfer======== : ");
    puts("1. Rp.100.000");
    puts("2. Rp.200.000");
    puts("3. Rp.500.000");
    puts("4. Rp.1.000.000");
    puts("5.Nominal lainnya");
    puts("6.kembali");
    printf("Masukan pilihan anda : ");
    scanf("%d",&y);
    switch(y) {
        case 1:
        if(data[z].saldo<100000){
            puts("Saldo anda tidak mencukupi");
            return transfer();
        }
        data[z].saldo = data[z].saldo-100000;
        simp = 100000;
        break;
        case 2:
        if(data[z].saldo<200000){
            puts("Saldo anda tidak mencukupi");
            return transfer();
        }
        data[z].saldo = data[z].saldo-200000;
        simp = 200000;
        break;
        case 3:
        if(data[z].saldo<500000){
            puts("Saldo anda tidak mencukupi");
            return transfer();
        }
        data[z].saldo = data[z].saldo-500000;
        simp = 500000;
        break;
        case 4:
        if(data[z].saldo<1000000){
            puts("Saldo anda tidak mencukupi");
            return transfer();
        }
        data[z].saldo = data[z].saldo-1000000;
        simp = 1000000;
        break;
        case 5:
        printf("Masukkan Nominal Uang : ");
        scanf("%d",&l);
        if(data[z].saldo<l){
            puts("Saldo anda tidak mencukupi");
            return transfer();
        }
        data[z].saldo = data[z].saldo-l; 
        simp = l;
        break;
        case 6:
        return awal();
        break;
        default : 
        puts("Pilihan salah");
        return transfer();
    }
    ngirim();
    data[u].saldo = data[u].saldo + simp;
    p = 0;
    inspin();
    puts("Transfer berhasil");
    data[t].riwayat = simp;
    data[t].riwayat1 = 3;
    t++;
    t1++;
}

void withdraw() {
    int w;
    puts("=============Withdraw============");
    puts("1. Rp.100.000");
    puts("2. Rp.200.000");
    puts("3. Rp.500.000");
    puts("4. Rp.1.000.000");
    puts("5.Nominal lainnya");
    puts("6.kembali");
    printf("Masukan pilihan anda : ");
    scanf("%d",&g);
    switch(g) {
        case 1:
        if(data[z].saldo<100000){
            printf("Saldo anda tidak mencukupi");
            return withdraw();
        }
        data[z].saldo = data[z].saldo - 100000;
        w = 100000;
        break;
        case 2:
        if(data[z].saldo<200000){
            printf("Saldo anda tidak mencukupi");
            return withdraw();
        }
        data[z].saldo = data[z].saldo - 200000;
        w = 200000;
        break;
        case 3:
        if(data[z].saldo<500000){
            printf("Saldo anda tidak mencukupi");
            return withdraw();
        }
        data[z].saldo = data[z].saldo - 500000;
        w = 500000;
        break;
        case 4:
        if(data[z].saldo<1000000){
            puts("Saldo anda tidak mencukupi");
            return withdraw();
        }
        data[z].saldo = data[z].saldo - 1000000;
        w = 1000000;
        break;
        case 5:
        printf("Masukan nominal : ");
        scanf("%d",&h);
        if(data[z].saldo<h){
            puts("Saldo anda tidak mencukupi");
            return withdraw();
        }
        data[z].saldo = data[z].saldo - h;
        w = h;
        break;
        case 6:
        return awal();
        break;
        default:
        puts("Pilihan salah");
        return withdraw();
    }  
    p = 0;
    inspin();
    puts("Transaksi berhasil");
    puts("Jumlah saldo anda saat ini : ");
    printf("Rp. %d",data[z].saldo);
    data[t].riwayat = w;
    data[t].riwayat1 = 2;
    t++;
    t1++;
}

void deposit() {
    puts("========Deposit========");
    puts("Pilih jumlah pecahan uang : ");
    puts("1. Rp. 20.000");
    puts("2. Rp. 50.000");
    puts("3. Rp. 75.000");
    puts("4. Rp. 100.000");
    puts("5.kembali");
    printf("Masukan pilihan anda : ");
    scanf("%d",&e);
    if(e==5){
        return awal();
    }
    printf("Masukan jumlah lembar : ");
    scanf("%d",&f);
    switch(e) {
    case 1:
        system("cls");
        depo = 20000*f;
        break;
    case 2:
        system("cls");
        depo = 50000*f;
        break;
    case 3:
        system("cls");
        depo = 75000*f;
        break;
    case 4:
    system("cls");
    depo = 100000*f;
    break;
    default :
        puts("Pilihan salah");
        return deposit();
    }
    data[z].saldo = data[z].saldo+depo;
    p = 0;
    inspin();
    puts("Transaksi berhasil");
    puts("Jumla saldo anda saat ini : ");
    printf("Rp. %d",data[z].saldo);
    data[t].riwayat=depo;
    data[t].riwayat1=1;
    t++;
    t1++;
}

void ceksaldo() {
    puts("Jumlah saldo anda : ");
    printf("Rp. %d\n",data[z].saldo);
}

void init() {
    int i;
    for(i = 0; i < size; i++)
        hash[i] = -1;
}

void insert(int value1) {
    int key = value1 % size;
    if(hash[key] == -1) {
        hash[key] = value1;
        printf("\n");
    } else {
        printf("Collision : hash[%d] has element %d already!\n",key,hash[key]);
        printf("Unable to insert %d\n", value1);
    }
}

void search1(int value1) {
    fflush(stdin);
    key = 0;
    key = value1 % size;
    if(hash[key] == value1) {
        printf("Nomor terverifikasi\n");
        u = key;
    } else {
        printf("Nomor anda tidak terdata\n");
        return ngirim();
    }
}

void search(int value1) {
    key = value1 % size;
    if(hash[key] == value1) {
        printf("Nomor terverifikasi\n");
        z = key;
    } else {
        printf("Nomor anda tidak terdata\n");
        return main();
    }
}

void inspin() {
    fflush(stdin);
    printf("Masukkan Pin Anda : ");
    scanf("%d",&data->pin);
    printf("====================================\n");
    if(data->pin==data[z].pin1){
        printf("PIN benar\n");
    } else {
        printf("PIN salah\n");
        p++;
        if(p>3){
            puts("PIN salah lebih dari 3x transaksi gagal");
            exit(0);
        } else {
            printf("Attemp %d : \n",p);
            return inspin();
        }
    }
}

void gtw() {
    for(t = 0; t < t1; t++) {
        if(data[t].riwayat1==1){
            printf("Deposit %d\n",data[t].riwayat);
        } else if(data[t].riwayat1==2) {
            printf("Withdraw %d\n",data[t].riwayat);
        } else if(data[t].riwayat1==3) {
            printf("Transfer %d\n",data[t].riwayat);
        }
    }
}

void pppop() {
    struct StackNode* root = NULL;
    for(t=0;t<t1;t++){
        push(&root,data[t].riwayat);
    }
    for(t = t1; t > t1 - 4; t--){
        if(data[t].riwayat1 == 1){
            printf("Deposit %d\n",pop(&root));
        } else if(data[t].riwayat1 == 2){
            printf("Withdraw %d\n", pop(&root));
        } else if(data[t].riwayat1 == 3){
            printf("Transfer %d\n", pop(&root));
        }
    }
}

void sssort() {
    for(i  =0; i < t1; i++){
        hehe[i].fake1 = data[i].riwayat1 ;
        hehe[i].fake2 = data[i].riwayat;
    }
    int j;
    for (i = 1; i <t1; i++) {
        for (j = 0; j < t1 - i; j++) {
            if (hehe[j].fake1 > hehe[j + 1].fake1) {
                temp = hehe[j].fake1;
                hehe[j].fake1 = hehe[j+1].fake1;
                hehe[j+1].fake1=temp;
                    
                temp2 = hehe[j].fake2;
                hehe[j].fake2 = hehe[j+1].fake2;
                hehe[j+1].fake2 = temp2;
            }
        }
        for(t=0;t<t1;t++) {
            if(hehe[t].fake1==1) {
                printf("Deposit %d\n",hehe[t].fake2);
            } else if(hehe[t].fake1==2) {
                printf("Withdraw %d\n",hehe[t].fake2);
            } else if(hehe[t].fake1==3){
                printf("Transfer %d\n",hehe[t].fake2);
            }
        }
    }
    puts("Ketik riwayat yang ingin anda cari : ");
    puts("Deposit = 1,withdraw = 2,transfer = 3");
    puts("contoh input : 2 100000");
    printf("Masukan inputan : ");
    scanf("%d %d",&g1,&g2);
    for(i=0;i<t1;i++) {
        if (g1==data[i].riwayat1 && g2==data[i].riwayat) {
            printf("Transaksi dilakukan pada Transaksi ke %d",i+1);
        }
    }
}

void history() {
    int a;
    puts("Lihat Riwayat Transaksi : ");
    puts("1. Lihat riwayat terakir");
    puts("2. Lihat seluruh riwayat");
    puts("3. cari riwayat");
    printf("Masukkan Pilihan : ");
    scanf("%d",&a);
    if(a==1) {
        pppop();
    } else if(a==2){
        gtw();
    } else if(a==3){
        sssort();
    } else{
        puts("Pilihan salah");
        return history();
    }       
}

void awal() {
    struct StackNode* root = NULL;
    p=0;
    char konfirmasi[5];
    awal:
    inspin();
    puts("========MENU========");
    printf("1. Cek Saldo\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Transfer\n");
    printf("5. Lihat Riwayat Transaksi\n");
    printf("6. Ganti PIN\n");
    printf("7. EXIT\n");
    printf("Masukkan Pilihan anda (1-7) : ");
    scanf("%d",&pilihan);
    switch(pilihan){
        case 1:
            system("cls");
            ceksaldo();
            break;
        case 2:
            system("cls");
            deposit();
            break;
        case 3 :
            system("cls");
            withdraw();
            break;
        case 4 :
            system("cls");
            transfer();
            break;
        case 5 :
            system("cls");
            for(t=0;t<t1;t++){
                pushbelakang(data[t].riwayat);
            }
            history();
            break;
        case 6 :
            system("cls");
            gantipin();
            break;
        case 7 :
            goto akhir;
            return 0;
            break;
            default : printf("Pilihan anda salah");
    }

    konfirmasi:
    printf("\nApakah anda ingin bertransaksi kembali ? Y/T : ");
    scanf("%s",&konfirmasi);
    if(strcmp(konfirmasi, "Y") == 0 || strcmp(konfirmasi, "y") == 0){
        goto awal;
    } else if(strcmp(konfirmasi, "T") == 0 || strcmp(konfirmasi, "t") == 0){
        goto akhir;
        akhir:
        system("cls");
        printf("================================");
        printf("\nTerimakasih sudah bertransaksi");
        printf("\n================================\n");
    } else{
        printf("\nPilihan salah");
        goto konfirmasi;
    }
}

int main () {
	int num;
    int a;
    FILE *fp,*fd;
    fp = fopen("pin.txt","r");
    while(!feof(fp)){
        fscanf(fp,"%lld %d %d",&data[i].nomer,&data[i].pin1,&data[i].saldo);
        i++;
    }
    fclose(fp);
    init();
    for(i=0;i<size;i++){
        insert(data[i].nomer);   
    }
    int salah = 0;

    printf("===================================\n");
    printf("\tSelamat datang di ATM \n");
    printf("===================================\n");
    printf("Masukan nomor kartu anda : ");
    scanf("%d",&a);
    search(a);
    awal();
    FILE *fw;
    fw = fopen("pin1.txt","w");
    for(i=0;i<size;i++){
        fprintf(fw,"%lld %d %d\n",data[i].nomer,data[i].pin1,data[i].saldo);
    }
    fclose(fw);
    remove("pin.txt");
    rename("pin1.txt","pin.txt");
    return 0;
}