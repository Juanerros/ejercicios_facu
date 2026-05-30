#include <stdio.h>

int main() {
  int legajos[50] = {0}, mayores[50] = {0};
  float sueldos[50] = {0};
  int posiMay = 0;

  int i = 0;
  int auxL = 0;
  float auxS = 0.00;

  do {
    printf("Ingrese legajo:\n");
    scanf("%d", &auxL);

    printf("Ingrese sueldo:\n");
    scanf("%f", &auxS);
    legajos[i] = auxL;
    sueldos[i] = auxS;

    if (i != 0) {
      if (auxS >= sueldos[i - 1]) {
        mayores[posiMay] = auxS;
        posiMay++;
      }
    }

    i++;
  } while (auxL != 0 && auxS != 0.00);

  for (int j = 0; j < 50; j++) {
    if (legajos[j] != 0 && sueldos[j] != 0.00) {
      printf("Legajo: %i ", legajos[j]);
      printf("Sueldo: %f \t", sueldos[j]);
      printf("\n");
    }
  }

  for (int j = 0; j < 50; j++) {
    if (mayores[j] != 0) {
      printf("El/los mayor/es sueldo/s son: %i", mayores[j]);
    }
  }

  return 0;
}