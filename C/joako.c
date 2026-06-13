#include <stdio.h>

const int row = 3;
const int column = 4;

void initMatriz(int[][column]);
void printMatriz(int[][column]);
void sortMatriz(int[][column]);
void sortVector(int[]);
void Matriz_Ordenada(int[][column]);

int main() {
  int matrizpapu[row][column];

  initMatriz(matrizpapu);

  //   sortMatriz(matrizpapu);

  //   printMatriz(matrizpapu);

  Matriz_Ordenada(matrizpapu);

  printMatriz(matrizpapu);

  return 0;
}

void initMatriz(int matrizpapu[][column]) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      int aux = 0;
      printf("Ingrese num: \t");
      scanf("%i", &aux);
      matrizpapu[i][j] = aux;
    }
  }
}

void sortMatriz(int matriz[][column]) {

  int Vec[row + column];
  int K = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column - 1; j++) {
      Vec[K] = matriz[i][j];
      K++;
    }
  }
  sortVector(Vec);
  K = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column - 1; j++) {
      matriz[i][j] = Vec[K];
      K++;
    }
  }
}

void sortVector(int Vec[]) {
  for (int i = 0; i < row * column; i++) {
    for (int j = 0; j < row * column - 1; j++) {
      int aux = Vec[j];
      Vec[j] = Vec[j + 1];
      Vec[j + 1] = aux;
    }
  }
}

void printMatriz(int matriz[][column]) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      printf("%d \t", matriz[i][j]);
    }
    printf("\n");
  }
}