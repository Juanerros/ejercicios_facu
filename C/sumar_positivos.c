#include <stdio.h>

int main() {
    int sum = 0;
    int num = 0;

    do{
        printf("Ingresa el numero:\n");
        scanf("%d", &num);
        if(num > 0) sum += num;
    } while(num > 0);

    printf("Suma: %d", sum);

    return 0;
}