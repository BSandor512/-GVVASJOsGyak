#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char input[100];
    printf("Adjon meg egy parancsot: ");
    scanf("%s", input);
    system(input);
    return 0;
}
