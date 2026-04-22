#include <stdio.h>

int main() {
    int dia = 1;
    
    printf("Ingresa dia:\n");
    scanf("%d", &dia);

    switch(dia) {
        case 1:
            printf("Dia de la semana: Lunes \n");
            break;
        case 2:
            printf("Dia de la semana: Martes \n");
            break;
        case 3:
            printf("Dia de la semana: Miercoles \n");
            break;
        case 4:
            printf("Dia de la semana: Jueves \n");
            break;
        case 5:
            printf("Dia de la semana: Viernes \n");
            break;
        case 6:
        case 7:
            printf("Dia de la semana: Fin de semana \n");
            break;
        default: 
            printf("ERROR: entrda invalida \n");
            break;
    }

    return 0;
}