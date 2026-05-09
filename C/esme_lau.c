#include <stdio.h>

int main() {
  // realice un programa que identifique si su numero es par o no
  int numero, resultado
  printf("Ingrese el numero a identificar");
  scanf("%d", &numero);
  resultado = numero / 2;
  if (resultado ==0) {
    printf("el numero es par");
  } else {
    printf("el numero es impar");
  }
}
