#include <stdio.h>

int Particion(int[], int, int);
void Ordenar(int[], int, int);
void Swap(int[], int, int);

int main() {
  int Vec[10];

  for (int I = 0; I < 10; I++) {
    scanf("%d", &Vec[I]);
  }

  Ordenar(Vec, 9, 0);
  printf("\n\n\n\n");
  for (int J = 0; J < 10; J++) {
    printf("%d ", Vec[J]);
  }

  return 0;
}

void Ordenar(int Vec[], int H_P, int L_P) {

  if (L_P < H_P) {
    int Pivote = Particion(Vec, H_P, L_P);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             Ordenar(Vec, Pivote - 1, L_P);
    Ordenar(Vec, H_P, Pivote + 1);
  }
}

int Particion(int Vec[], int H_P, int L_P) {
  int Pivote = Vec[H_P];
  int I = L_P - 1;
  for (int J = L_P; J < H_P; J++) {
    if (Vec[J] >= Pivote) {
      I++;
      Swap(Vec, J, I);
    }
  }
  I++;
  Swap(Vec, I, H_P);
  return I;
}

void Swap(int Vec[], int I, int J) {
  int Aux = Vec[I];
  Vec[I] = Vec[J];
  Vec[J] = Aux;
}
