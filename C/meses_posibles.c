#include <stdio.h>

int main() {
    int mes = 1;

    do{
        printf("Ingresa el mes:\n");
        scanf("%d", &mes);
    } while(mes < 1|| mes > 12);


    return 0;
}