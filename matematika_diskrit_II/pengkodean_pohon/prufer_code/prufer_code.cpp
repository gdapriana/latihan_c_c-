#include <iostream>
#include <string>
using namespace std;

// algoritma (kode ke pohon)
// memilih digit 1 pada kode
// cari pada array vertex digit pertama, tetapi tidak ada pada array kode
// hapus nilai pada array kode dan vertex yang terpakai
// gunakan 2 nilai array vertex yang terisa untuk edge terakhir

void kode() {
    int v, i, j, e, min, a;
    cout << "masukkan Jumlah Vertex: ";
    cin >> v;
    e = v -  1;

    // perulangan untuk mengset derajat ke nilai 0
    int edge[e][2], derajat[v + 1];
    for(i = 0; i <= v; i++) {
        derajat[i] = 0;
    }
    for(i = 0; i < e; i++) {
        cout << "Masukkan Edge ke " << i + 1 << endl;
        cin >> edge[i][0] >> edge[i][1];

        derajat[edge[i][0]]++;
        derajat[edge[i][1]]++;  
    }

    
    cout << "\nTotal Derajat" << endl;
    for(i = 1; i <= v; i++) {
        cout << "Vertex ke-" << i << " => " << derajat[i] << endl;
    }
    cout << endl;

    // perulangan untuk memasukan keterhubungan antar vertex
    cout << "Kode: ";
    for(i = 0; i < v - 2; i++) {
        min = 999;
        for(j = 0; j < e; j++) {
            if(derajat[edge[j][0]] && derajat[edge[j][1]] != 0) {
                if(derajat[edge[j][0]] == 1) {
                    if (min > edge[j][0]) {
                        min = edge[j][0];
                        a = j;
                    }
                }

                if(derajat[edge[j][1]]==1) {
                    if(min>edge[j][1]) {
                        min = edge[j][1];
                        a = j;
                    }
                } 
            }
        }
        derajat[edge[a][0]]--;
        derajat[edge[a][1]]--;

        if(derajat[edge[a][0]] == 0) {
            cout << " " << edge[a][1];
        } else {
            cout << " " << edge[a][0];
        }
    }
}

void tree() {
    int i, j, k, jumlah, x = 0;
    cout << "Input jumlah vertex: ";
    cin >> jumlah;

    int vertex[jumlah];
    int kode[jumlah - 2];

    cout << "Masukkan Kode Prufer: " << endl;
    for (i = 0; i < jumlah - 2; i++) {
        cin >> kode[i];
    }
    for(i =0; i < jumlah; i++) {
        vertex[i] = i + 1;
    }

    cout << "Vertex = ";
    for(i = 0; i < jumlah; i++) {
        cout << vertex[i];
    }

    int hitung;
    cout << endl;
    cout << "\nRekontruksi Kode Prufer: " << endl;
    for(i = 0; i < jumlah - 2; i++) {
        for(j = 0; j < jumlah; j++) {
            hitung = 0;
            for(k = 0; k < jumlah - 2; k++) {
                if(kode[k] == vertex[j]) {
                    hitung++;
                }
            }

            if(hitung == 0) {
                break;
            }
        }

        cout << kode[i] << " - " << vertex[j] << endl;
        kode[i] = 0;
        vertex[j] = 0;
    }

    for(i = 0; i < jumlah; i++) {
        if(vertex[i] != 0) {
            if(x == 0) {
                cout << "" << vertex[i];
            }
            if(x == 1) {
                cout << " - " << vertex[i];
            }
            x++;
        }
    }
}

int menu() {
    int input;
    system("cls");
    cout << "Program Kode Prufer" << endl;
    cout << "1. Tree => Kode Prufer" << endl;
    cout << "2. Kode Prufer => Tree" << endl;
    cout << "3. Keluar" << endl;
    cout << "Pilih: ";
    cin >> input;
    return input;
}

int main() {
    int pilihan = menu();
    char lanjutkan;

    while (pilihan != 3) {
        switch (pilihan) {
        case 1:
            system("cls");
            kode();
            break;

        case 2:
            system("cls");
            tree();
            break;

        default:
            cout << "Inputan Invalid" << endl;
            break;
        }

        label_lanjutkan:

        cout << "\nKembali ke menu?(y/n): ";
        cin >> lanjutkan;

        if((lanjutkan == 'y') | (lanjutkan == 'Y')) {
            pilihan = menu();
        } else if ((lanjutkan == 'n') | (lanjutkan == 'N')){
			break;
		} else {
			goto label_lanjutkan;
		}
    }

    cout << "Program Berakhir" << endl;
    cin.get();
    return 0;
} 