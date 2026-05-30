#include <stdio.h>

void printVec(int v[]) {
  for (int j = 0; j < 3; j++) {
    printf("num: %d", v[j]);
    printf("\n");
  }
}

void bulkVec(int v[]) {
  for (int i = 0; i < 3; i++) {
    printf("ingrese numero: \n");
    scanf("%d", &v[i]);
  }
}

int main() {
  int num[3];

  bulkVec(num);

  printVec(num);

  return 0;
}