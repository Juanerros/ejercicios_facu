
#include <stdio.h>

const int TAM = 10;

void readline(int vec[]);

void copyVec(int v[], int vCopy[]) {
  for (int i = 0; i < TAM; i++) {
    vCopy[i] = v[i];
  }
}

void bulkVec(int v[]) {
  int aux = 0;
  for (int i = 0; i < TAM; i++) {
    printf("ingrese numero: \n");
    scanf("%d", &aux);
    if (aux == 0) {
      continue;
    }
    v[i] = aux;
  }
}

void addVecs(int vResult[], int v1[], int v2[]) {
  for (int i = 0; i < TAM; i++) {
    vResult[i] = v1[i] + v2[i];
  }
}

void printVec(int v[]) {
  for (int i = 0; i < TAM; i++) {
    printf("num: %d", v[i]);
    printf("\n");
  }
}

int main() {
  int VecA[10];
  int VecB[10];
  int VecC[10];

  bulkVec(VecA);

  copyVec(VecA, VecB);

  addVecs(VecC, VecA, VecB);

  readline(VecC);

  printVec(VecC);

  return 0;
}

void readline(int vec[]) {
  int aux;
  for (int i = 0; i < TAM - 1; i++) {

    for (int j = 0; j < TAM - 1 - i; j++) {

      if (vec[j] < vec[j + 1]) {
        aux = vec[j];
        vec[j] = vec[j + 1];
        vec[j + 1] = aux;
      }

    }
  }
}