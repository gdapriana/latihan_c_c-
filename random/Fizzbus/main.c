#include <stdio.h>

void fizzBus(int data) {
    if (data % 3 == 0 && data % 5 == 0) {
        printf("FizzBus");
    } else if (data % 5 == 0) {
        printf("Bus");
    } else if (data % 3 == 0) {
        printf("Fizz");
    } else {
        printf("Bukan Fizz/Bus");
    }
}

void main() {
    int input;
    printf("Input Number: ");
    scanf("%d", &input);
    fizzBus(input);
}