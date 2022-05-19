#include <stdio.h>
#define MAX 5

struct STACK {
   int data[MAX];
   int top;
} tumpuk;

void init() {
   data.top = -1;
}

int isEmpty() {
   if (data.top == -1) {
      return 1;
   } else {
      return 0;
   }
}

int isFull() {
   if (data.top == MAX - 1) {
      return 1;
   } else {
      return 0;
   }
}

void push() {
   if (isFull() == 0) {
      data.top++;
      printf("Masukkan Data: ");
      scanf("%d", &data.data[data.top]);
   } else {
      printf("Data Sudah Penuh");
   }
}



int menu() {
   int pilih;
   puts("Menu: ");
   puts("1. Push");
   puts("2. Pop");
   puts("3. Peek");
   puts("4. Clear");
   printf("Pilih: "); fflush(stdin);
   scanf("%d", &pilih);
   return pilih;
}

int main() { 
   int pilih = menu();
   
   switch (pilih) {
      case 1:
         push();
         return main();
      break;

      case 2:
      break;

      case 3:
      break;

      case 4:
      break;init();

      case 5: 
      break;

      default:
         puts("Invalid Input");
         return main();
      break;
   }
}


void pop() {
   printf("data yang di pop = %s\n", tumpuk.data[tumpuk.top]);
   tumpuk.top--;
}

