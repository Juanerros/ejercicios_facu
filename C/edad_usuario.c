#include <stdio.h>

char actual[10] = "01/01/2000";
char persona[10] = "01/01/2000";

int main() {
    int edad, dia, mes, ano;
    
    printf("Ingresa fecha actual:\n");
    scanf("%s", actual);

    printf("Ingresa fecha de nacimiento:\n");
    scanf("%s",persona);

    
    dia = strtol(actual[0] + actual[1], null, 10);
    mes = strtol(actual[0] + actual[1], null, 10);
    ano = strtol(actual[0] + actual[1], null, 10);

    return 0;
}