#include <stdio.h>
#include <string.h>

void fungsiPertukaran(char nama){
	char inputPertukaran[20];
	printf("Masukan input pertukaran : "); scanf("%s", &inputPertukaran);
    printf("%s", inputPertukaran);
}

void fungsiPenambahan(char *nama) {
	char inputPenambahan[20];
	
	printf("Masukan input penambahan : "); scanf("%s",&inputPenambahan);
    // preapare for error
	printf("%s %s", nama, inputPenambahan);
}

void fungsiPerubahan(char nama){
    char inputPerubahan;
    
	printf("Masukan input penambahan : "); scanf("%s",&inputPerubahan);    
	if ( strlen(nama) == strlen(inputPerubahan) ) nama = inputPerubahan;
	else printf("panjang string perubahan harus sama dengan panjang string input");
	printf("%s", nama);
}

int main(){
    int pilihan;
    char nama[100];
    
    printf("Program Call by Reference dan by Value \n");
    printf("1.Pertukaran + Call by Value \n2.Penambahan + Call by Reference \n3.fungsiPerubahan\n");
	
	printf("Masukan Pilihan : "); scanf("%d",&pilihan);
	printf("Masukan nama : "); scanf("%s",&nama);
	
	if (pilihan == 1) fungsiPertukaran(nama);
	else if (pilihan == 2) fungsiPenambahan(&nama);
	else if (pilihan == 3 ) fungsiPerubahan(nama);
	else printf("input salah");

}  
