#include <iostream>
#include <stdlib.h>
using namespace std;

// yang aku ubah
// hapus => delete_data
// tampil => view
// hash => hashing_table
// tampilan menu

int hashing_table[5];

void inisialisasi() {
    for(int i=1;i<=5;i++) {
        hashing_table[i]=-1;
    }
}

int cek_kosong() {
    int kosong=0;
    for(int i=1;i<=5;i++) {
        if(hashing_table[i]==-1) {
            kosong++;
        }
    }
    if(kosong!=0) {
        return 1;
    } else {
        return 0;
    }
}

int pengacak() {
    int acak;
    lagi:
    acak=rand()%6;

    if(acak==0) {
        goto lagi;
    }
return acak;
}

void input(int input) {
    int indeks;
    if(cek_kosong()==0) {
        cout<<"Tempat penyimpan data penuh\n";
    } else {
        indeks=pengacak();
        acak:
        if(hashing_table[indeks]!=-1) {
            cout<<"Terjadi tabrakan pada indeks : " << indeks << endl;
            if(indeks==5) {
                indeks=1;
                cout<<"Karena indeks = 5 maka indeks dikembalikan ke 1\n";
                goto acak;
            } else {
                indeks++;
                cout<<"Tambah indeks menjadi "<< indeks <<endl;
            }
            goto acak;
        } else {
            hashing_table[indeks]=input;
            cout<<"Data masuk pada indeks "<< indeks <<endl;
        }
    }
}

void searching(int cari) {
    int temu=0;
    for(int i=1;i<=5;i++) {
        if(hashing_table[i]==cari) {
            temu=1;
        }
    }
    if(temu==1) {
        cout<<"Data ditemukan\n";
    } else {
        cout<<"Data tidak ditemukan\n";
    }
}

void delete_data(int hapus) {
    int del=0;
    for(int i=1;i<=5;i++) {
        if(hashing_table[i]==hapus) {
            del=1;
            hashing_table[i]=-1;
        }
    }

    if(del==0) {
        cout<<"Data tidak ada\n";
    } else {
        cout<<"Data terhapus\n";
    }
}

void view() {
    for(int i=1;i<=5;i++) {
        cout<<"Indeks ke " <<i<< ": ";
        if(hashing_table[i]!=-1) {
            cout<<hashing_table[i]<<endl;
        } else {
            cout<<"kosong\n";
        }
    }
}

int main() {
    inisialisasi();
    int pilihan,data;

    do {
        menu:
        system("cls");
        cout<<"-----------------------\n";
        cout<<"|                     |\n";
        cout<<"|   PROGRAM HASHING   |\n";
        cout<<"| PUNYA SUCIK (INI WM)|\n";
        cout<<"|                     |\n";
        cout<<"-----------------------\n";
        cout<<"| 1.Input data        |\n";
        cout<<"| 2.Searching data    |\n";
        cout<<"| 3.Delete data       |\n";
        cout<<"| 4.View data         |\n";
        cout<<"| 5.Keluar            |\n";
        cout<<"-----------------------\n";
        cout<<"Pilihan : ";
        cin>>pilihan;

        switch(pilihan) {
            case 1:
                system("cls");
                cout<<"Masukkan data (harus positif) : ";
                cin>>data;
                if(data<0) {
                    cout<<"Data tidak boleh negatif\n";
                    cout<<"\n ";
                    system("pause");
                    goto menu;
                }
                input(data);
                cout<<"\n ";
                system("pause");
            break;

            case 2:
                system("cls");
                cout<<"Masukkan data yang dicari : ";
                cin>>data;
                searching(data);
                cout<<"\n ";
                system("pause");
            break;

            case 3:
                system("cls");
                cout<<"Masukkan data yang dihapus : "; 
                cin>>data;
                delete_data(data);
                cout<<"\n ";
                system("pause");
            break;

            case 4:
                system("cls");
                view();
                cout<<"\n ";
                system("pause");
                break;
        }
    } while(pilihan!=5);
}
