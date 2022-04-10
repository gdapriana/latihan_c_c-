#include <iostream>
#include <string>
using namespace std;

// Algoritma (pohon ke kode)
// Inisialisasi kode Prufer sebagai kosong / 0.
// Mulailah dengan daun dengan label terendah, katakan x. 
// Temukan simpul yang menghubungkannya dengan sisa pohon, katakan y.
// Hapus x dari pohon dan tambahkan y ke Kode Prufer
// Ulangi langkah 2 di atas sampai kita memiliki dua node.


// pohon ke kode prufer
void kode() {
    int v, i, j, e, min, a;
    // v = menampung jumlah vertex dari user
    // i, j = untuk melakukan perulangan
    // e = untuk menampung jumlah edge
    cout << "masukkan Jumlah Vertex: ";
    cin >> v;
    e = v -  1;
    // misalkan vertex input = 5
    // e = (5 - 1) = 4

    int edge[e][2], derajat[v + 1];
    // edge[4][2], derajat[6]

    // perulangan untuk mengset derajat ke nilai 0
    for(i = 0; i <= v; i++) {
        // i = 0; i <= 5; i++
        derajat[i] = 0;
        // derajat[0] = 0;
        // derajat[1] = 0;
        // derajat[2] = 0;
        // derajat[3] = 0;
        // derajat[4] = 0;
        // derajat[5] = 0;
    }

    // perulangan untuk memasukan keterhubungan antar vertex
    for(i = 0; i < e; i++) {
        // i = 0; i < 4; i++
        cout << "Masukkan Edge ke " << i + 1 << endl;
        // masukkan edge ke 1
        // masukkan edge ke 2
        // masukkan edge ke 3
        // masukkan edge ke 4

        cin >> edge[i][0] >> edge[i][1];
        // edge[0][0] (1) >> edge[0][1] (2) 
        // edge[1][0] (2) >> edge[1][1] (3)
        // edge[2][0] (3) >> edge[2][1] (4)
        // edge[3][0] (4) >> edge[3][1] (5)

        derajat[edge[i][0]]++;
        // derajat[1] = 0 + 1 = 1
        // derajat[2] = 0 + 1 = 1
        // derajat[3] = 0 + 1 = 1
        // derajat[4] = 0 + 1 = 1
        derajat[edge[i][1]]++;
        // derajat[2] = 0 + 1 = 1
        // derajat[3] = 1 + 1 = 2
        // derajat[4] = 1 + 1 = 2
        // derajat[5] = 0 + 1 = 1
    }

    // menampilkan derajat yang dihasilkan
    cout << "\nTotal Derajat" << endl;
    for(i = 1; i <= v; i++) {
        // i = 1; 1 <= 5; 1++
        cout << "Vertex ke-" << i << " => " << derajat[i] << endl;
        // derajat 1 = 1
        // derajat 2 = 2
        // derajat 3 = 2
        // derajat 4 = 2
        // derajat 5 = 1
    }
    cout << endl;

    // perulangan untuk menghasilkan kode prufer
    cout << "Kode: ";
    for(i = 0; i < v - 2; i++) {
        // i = 0; 0 < 3; i++

        min = 999;
        for(j = 0; j < e; j++) {
            // j = 0; 0 < 4; j++

            if(derajat[edge[j][0]] && derajat[edge[j][1]] != 0) {
                if(derajat[edge[j][0]] == 1) {
                    if (min > edge[j][0]) {
                        min = edge[j][0];
                        a = j;
                    }
                }

                if(derajat[edge[j][1]]==1) {
                    if(min > edge[j][1]) {
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

// kode prufer ke pohon
void tree() {
    int i, j, k, jumlah, x = 0;
    // var i, j, k = untuk perulangan
    // jumlah = untuk menampung jumlah vertex

    // mengambil inputan dari user
    cout << "Input jumlah vertex: ";
    cin >> jumlah;

    int vertex[jumlah];
    int kode[jumlah - 2];

    // perulangan untuk menginputkan kode prufer
    cout << "Masukkan Kode Prufer: " << endl;
    for (i = 0; i < jumlah - 2; i++) {
        cin >> kode[i];
    }
    for(i = 0; i < jumlah; i++) {
        vertex[i] = i + 1;
    }

    // tampilkan jumlah vertex
    cout << "Vertex = ";
    for(i = 0; i < jumlah; i++) {
        cout << vertex[i];
    }

    int hitung;
    cout << endl;
    cout << "\nRekontruksi Kode Prufer: " << endl;

    // perulangan untuk memperoleh rekontruksi
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

    // perulangan untuk menampilkan rekontruksi yang di dapat tadi
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