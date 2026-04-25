#include <stdio.h>

int main() {
  int edades[4];
  int acum;
  float prom;

  for (int i = 0; i < 4; i++) {
    printf("Ingresa edad: \n");
    scanf("%d", &edades[i]);
    acum += edades[i];
  }

  for (int i = 0; i < 4; i++) {
    printf("Edad: %d \n", edades[i]);
  }

  prom = (float)acum / 4;
  printf("Promedio: %f", prom);

  return 0;
}