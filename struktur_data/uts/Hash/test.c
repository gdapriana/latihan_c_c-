#include <stdio.h>
#include <stdlib.h>
char tic[3][3];
int cek_menang();
void pemain1_X_gerak();
void pemain1_O_gerak();
void pemain2_X_gerak();
void pemain2_O_gerak();
void liat_papan();
void buat_papan();
int keluar();


// mulai permainan
int main()
{ // buat_papan() untuk memanggil array tic
  buat_papan();
  int pilihan;
  printf("petunjuk: \n");
  // arr liat dan int liat sebagai petunjuk koordinat
  int liat[3][3];
  int Liat = 1;
  for(int s = 0; s < 3; s++){
    for(int t = 0; t < 3; t++){
      liat[s][t] = Liat;
      Liat++;
      printf("%i ", liat[s][t]);
    }
    printf("\n");
  }
  // memilih pilihan
  printf("\nMasukkan pilihan; \n1. X\n2. O");
  printf("\n>>");
  scanf("%i", &pilihan);
  char lese;
  lese = 1;
  // menyediakan pilihan untuk pemain
  switch(pilihan){
    case(1):
      // menggunakan do while sebagai looping
      do{
        liat_papan();
        pemain1_X_gerak();
        cek_menang();
        liat_papan();
        pemain2_O_gerak();
        cek_menang();
        if(lese == 0){
          break;
        }
        }while(lese > 0);
      break;
    case(2):
      do{
        liat_papan();
        pemain2_X_gerak();
        cek_menang();
        liat_papan();
        pemain1_O_gerak();
        cek_menang();
        if(lese == 0){
          break;
        }
        }while(lese > 0);
      break;
      // invalid jika pemain salah menginput
    default:
      printf("pilihan invalid");
      break;
  }
  return 0;
}
// fungsi void untuk membuat papan
void buat_papan(void){
  int i, j, kotak;
  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      tic[i][j] = ' ';
    }
  }
}
// fungsi void untuk pemain1 (pemain X)
void pemain1_X_gerak(void){
  int X1;
  printf("Pemain1");
  printf("\nmasukkan koordinat kursor kamu: \n");
  scanf("%i", &X1);
  if(X1 == 1 && tic[0][0] == ' '){
    tic[0][0] = 'X';
  }
  if(X1 == 1 && tic[0][0] != ' '){
    printf("invalid");
  }
  if(X1 == 2 && tic[0][1] == ' '){
    tic[0][1] = 'X';
  }
  if(X1 == 2 && tic[0][1] != ' '){
    printf("invalid");
  }
  if(X1 == 3 && tic[0][2] == ' '){
    tic[0][2] = 'X';
  }
  if(X1 == 3 && tic[0][2] != ' '){
    printf("invalid");
  }
  if(X1 == 4 && tic[1][0] == ' '){
    tic[1][0] = 'X';
  }
  if(X1 == 4 && tic[1][0] != ' '){
    printf("invalid");
  }
  if(X1 == 5 && tic[1][1] == ' '){
    tic[1][1] = 'X';
  }
  if(X1 == 5 && tic[1][1] != ' '){
    printf("invalid");
  }
  if(X1 == 6 && tic[1][2] == ' '){
    tic[1][2] = 'X';
  }
  if(X1 == 6 && tic[1][2] != ' '){
    printf("invalid");
  }
  if(X1 == 7 && tic[2][0] == ' '){
    tic[2][0] = 'X';
  }
  if(X1 == 7 && tic[2][0] != ' '){
    printf("invalid");
  }
  if(X1 == 8 && tic[2][1] == ' '){
    tic[2][1] = 'X';
  }
  if(X1 == 8 && tic[2][1] != ' '){
    printf("invalid");
  }
  if(X1 == 9 && tic[2][2] == ' '){
    tic[2][2] = 'X';
  }
  if(X1 == 9 && tic[2][2] != ' '){
    printf("invalid");
  }
  else {
    printf("koordinat tidak tepat pada kotak\n");
  }
}
//fungsi void untuk pemain1 (pemain O)
void pemain1_O_gerak(void){
  int O1;
  printf("Pemain1");
  printf("\nmasukkan koordinat kursor kamu: \n");
  scanf("%i", &O1);
  if(O1 == 1 && tic[0][0] == ' '){
    tic[0][0] = 'O';
  }
  if(O1 == 1 && tic[0][0] != ' '){
    printf("invalid");
  }
  if(O1 == 2 && tic[0][1] == ' '){
    tic[0][1] = 'O';
  }
  if(O1 == 2 && tic[0][1] != ' '){
    printf("invalid");
  }
  if(O1 == 3 && tic[0][2] == ' '){
    tic[0][2] = 'O';
  }
  if(O1 == 3 && tic[0][2] != ' '){
    printf("invalid");
  }
  if(O1 == 4 && tic[1][0] == ' '){
    tic[1][0] = 'O';
  }
  if(O1 == 4 && tic[1][0] != ' '){
    printf("invalid");
  }
  if(O1 == 5 && tic[1][1] == ' '){
    tic[1][1] = 'O';
  }
  if(O1 == 5 && tic[1][1] != ' '){
    printf("invalid");
  }
  if(O1 == 6 && tic[1][2] == ' '){
    tic[1][2] = 'O';
  }
  if(O1 == 6 && tic[1][2] != ' '){
    printf("invalid");
  }
  if(O1 == 7 && tic[2][0] == ' '){
    tic[2][0] = 'O';
  }
  if(O1 == 7 && tic[2][0] != ' '){
    printf("invalid");
  }
  if(O1 == 8 && tic[2][1] == ' '){
    tic[2][1] = 'O';
  }
  if(O1 == 8 && tic[2][1] != ' '){
    printf("invalid");
  }
  if(O1 == 9 && tic[2][2] == ' '){
    tic[2][2] = 'O';
  }
  if(O1 == 9 && tic[2][2] != ' '){
    printf("invalid");
  }
  else {
    printf("koordinat tidak tepat pada kotak\n");
  }
}
// fungsi void untuk pemain2 (pemain X)
void pemain2_X_gerak(void){
  int X1;
  printf("Pemain2");
  printf("\nmasukkan koordinat kursor kamu: \n");
  scanf("%i", &X1);
  if(X1 == 1 && tic[0][0] == ' '){
    tic[0][0] = 'X';
  }
  if(X1 == 1 && tic[0][0] != ' '){
    printf("invalid");
  }
  if(X1 == 2 && tic[0][1] == ' '){
    tic[0][1] = 'X';
  }
  if(X1 == 2 && tic[0][1] != ' '){
    printf("invalid");
  }
  if(X1 == 3 && tic[0][2] == ' '){
    tic[0][2] = 'X';
  }
  if(X1 == 3 && tic[0][2] != ' '){
    printf("invalid");
  }
  if(X1 == 4 && tic[1][0] == ' '){
    tic[1][0] = 'X';
  }
  if(X1 == 4 && tic[1][0] != ' '){
    printf("invalid");
  }
  if(X1 == 5 && tic[1][1] == ' '){
    tic[1][1] = 'X';
  }
  if(X1 == 5 && tic[1][1] != ' '){
    printf("invalid");
  }
  if(X1 == 6 && tic[1][2] == ' '){
    tic[1][2] = 'X';
  }
  if(X1 == 6 && tic[1][2] != ' '){
    printf("invalid");
  }
  if(X1 == 7 && tic[2][0] == ' '){
    tic[2][0] = 'X';
  }
  if(X1 == 7 && tic[2][0] != ' '){
    printf("invalid");
  }
  if(X1 == 8 && tic[2][1] == ' '){
    tic[2][1] = 'X';
  }
  if(X1 == 8 && tic[2][1] != ' '){
    printf("invalid");
  }
  if(X1 == 9 && tic[2][2] == ' '){
    tic[2][2] = 'X';
  }
  if(X1 == 9 && tic[2][2] != ' '){
    printf("invalid");
  }
  else {
    printf("koordinat tidak tepat pada kotak\n");
  }
}
// fungsi void untuk pemain2 (pemain O)
void pemain2_O_gerak(void){
  int O1;
  printf("Pemain2");
  printf("\nmasukkan koordinat kursor kamu: \n");
  scanf("%i", &O1);
  if(O1 == 1 && tic[0][0] == ' '){
    tic[0][0] = 'O';
  }
  if(O1 == 1 && tic[0][0] != ' '){
    printf("invalid");
  }
  if(O1 == 2 && tic[0][1] == ' '){
    tic[0][1] = 'O';
  }
  if(O1 == 2 && tic[0][1] != ' '){
    printf("invalid");
  }
  if(O1 == 3 && tic[0][2] == ' '){
    tic[0][2] = 'O';
  }
  if(O1 == 3 && tic[0][2] != ' '){
    printf("invalid");
  }
  if(O1 == 4 && tic[1][0] == ' '){
    tic[1][0] = 'O';
  }
  if(O1 == 4 && tic[1][0] != ' '){
    printf("invalid");
  }
  if(O1 == 5 && tic[1][1] == ' '){
    tic[1][1] = 'O';
  }
  if(O1 == 5 && tic[1][1] != ' '){
    printf("invalid");
  }
  if(O1 == 6 && tic[1][2] == ' '){
    tic[1][2] = 'O';
  }
  if(O1 == 6 && tic[1][2] != ' '){
    printf("invalid");
  }
  if(O1 == 7 && tic[2][0] == ' '){
    tic[2][0] = 'O';
  }
  if(O1 == 7 && tic[2][0] != ' '){
    printf("invalid");
  }
  if(O1 == 8 && tic[2][1] == ' '){
    tic[2][1] = 'O';
  }
  if(O1 == 8 && tic[2][1] != ' '){
    printf("invalid");
  }
  if(O1 == 9 && tic[2][2] == ' '){
    tic[2][2] = 'O';
  }
  if(O1 == 9 && tic[2][2] != ' '){
    printf("invalid");
  }
  else {
    printf("koordinat tidak tepat pada kotak\n");
  }
}
// fungsi void untuk display papan
void liat_papan(void){
  int liat;
  for(liat = 0; liat < 3; liat++){
    printf("\n %c | %c | %c ", tic[liat][0], tic[liat][1], tic[liat][2]);
    if(liat != 2){
      printf("\n===|===|===\n");
    }
    printf("\n");
  }
}
// fungsi void untuk menentukan pemenang
int cek_menang(){
  int i;
  for(i = 0; i < 3; i++){
    if(tic[i][0] == tic[i][1] && tic[i][0] == tic[i][2] && tic[i][0] != ' '){
      printf("%c menang", tic[i][0]);
     
    }
  }
  for(i = 0; i < 3; i++){
    if(tic[0][i] == tic[1][i] && tic[0][i] == tic[2][i] && tic[0][i] != ' '){
      printf("%c menang", tic[0][i]);
    return keluar();
    }
  }
  if(tic[0][0] == tic[1][1] && tic[0][0] == tic[2][2] && tic[0][0] != ' '){
    printf("%c menang", tic[0][0]);
    return keluar();
  }
  if(tic[2][0] == tic[1][1] && tic[2][0] == tic[0][2] && tic[2][0] != ' '){
    printf("%c menang", tic[2][0]);
    return keluar();
      
  }
  
}

int keluar(){
  printf("\n");
  system("pause");

  return 0;
}