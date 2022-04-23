#include <stdio.h>
#include <string.h>

void tukar(char nama){
	char inputPertukaran[20];
	printf("Masukan input pertukaran: "); scanf("%s", &inputPertukaran);
    printf("%s", inputPertukaran);
}

void tambah(char *nama) {
	char inputPenambahan[20];
	
	printf("Masukan input penambahan: "); scanf("%s",&inputPenambahan);
	printf("%s %s", nama, inputPenambahan);
}

void ubah(char nama){
    char inputPerubahan[20];
    
	printf("Masukan input penambahan: "); scanf("%s",&inputPerubahan);    
	if ( strlen(nama) == strlen(inputPerubahan) ) {
		nama = inputPerubahan;
	} else {
		printf("panjang string perubahan harus sama dengan panjang string input");
	}
	printf("%s", nama);
}

int main(){
    int pilihan;
    char nama[100];
    
    printf("Program Call by Reference dan by Value \n");
    printf("1.Pertukaran + Call by Value \n2.Penambahan + Call by Reference \n3.ubah\n");
	
	printf("Masukan Pilihan : "); scanf("%d",&pilihan);
	printf("Masukan nama : "); scanf("%s",&nama);
	
	if (pilihan == 1) {
		tukar(nama);
	} else if (pilihan == 2) {
		tambah(&nama);
	} else if (pilihan == 3 ) {
		ubah(nama);
	} else {
		printf("input salah");
	}
}  
