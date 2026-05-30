#include <stdio.h>

int operation(int p, int q, char ope) {
  switch (ope) {
  case '+':
    return p || q;
    break;
  case '.':
    return p && q;
    break;
  }
  return -1;
}

void printExpretion(char chara[]) {
  int lastQ = 0;
  char prep = lastQ ? 'p' : 'q';

  for (int i = 0; i <= 3; i++) {
    printf("%c", prep);
    printf("%c", chara[i]);
  }
}

int main() {
  int q, p, r, cant = 0, j = 0;

  char operaradores[2];

  do {
    printf("Ingresa cantidad de variables [1-3]:\n");
    scanf("%d", &cant);
  } while (cant != 1 || cant != 2 || cant != 3);
  do {
    printf("Ingresa operador [+/.]:\n");
    scanf("%c", &operaradores[j]);
    j++;
  } while (cant != '+' || cant != '.' || j >= cant - 1);

  printExpretion(operaradores);

  return 0;
}