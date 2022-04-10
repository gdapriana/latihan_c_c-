#include <stdio.h>

void main(){

    int array[5] = {14, 81, 52, 34, 75, 56};
    int length = sizeof(array) / sizeof(*array);

    printf("Panjang isi array adalah: %d\n", length);
}