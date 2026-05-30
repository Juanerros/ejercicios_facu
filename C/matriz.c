#include <stdio.h>

int vec[3][3];
const int TAM = 3;

int main() {
  int aux;

  // Ingreso
  for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++) {
      printf("Ingresa numero: ");
      scanf("%d", &vec[i][j]);
      printf("\n");
    }
  }

  // Orden
  for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++) {

      if (vec[i][j] % 2 == 0) {
        aux = vec[i][j];
        vec[i][j] = vec[i][0];
        vec[i][0] = aux;  
      }
    }
  }

  // Print
  for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++) {
      printf("%d \t", vec[i][j]);
    }
    printf("\n");
  }

  return 0;
}