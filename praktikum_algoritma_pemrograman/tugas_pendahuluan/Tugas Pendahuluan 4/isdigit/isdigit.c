#include <stdio.h>
#include <string.h>

int main() { 
    system("cls");
    char kata1 = '1';
    char kata2 = 'a';

    printf("Apakah kata 1 berupa angka? %d\n", isdigit(kata1));
    printf("Apakah kata 2 berupa angka? %d", isdigit(kata2));

}