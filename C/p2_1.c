#include <stdio.h>

void cargarSueldos(int[], float[]);
void cargarHoras(int[], int[], int[]);
void calcularTotal(int[], int[], float[], int[], int[], int[]);
int buscarSueldo(int, int[], float[]);
void mayoresSueldos(int[], float[]);
void mostrarVectores(int[]);

int main() {
  int legajo[350] = {0};   // 4 cifras
  float sueldo[350] = {0}; // real > 0

  int legajo2[350] = {0}; // 4 cifras
  int hora[350] = {0};    // > 0
  int seccion[350] = {0}; // 101-108

  int total[350] = {0};

  cargarSueldos(legajo, sueldo);

  printf("\nCARGA DE HORAS: \n");
  cargarHoras(legajo2, hora, seccion);

  calcularTotal(legajo, legajo2, sueldo, hora, seccion, total);

  mayoresSueldos(legajo, sueldo);

  mostrarVectores(total);

  return 0;
}

void cargarSueldos(int legajo[], float sueldo[]) {
  int puedeIngresar = 1;
  int i = 0;

  while (puedeIngresar) {
    int auxLegajo = 0;
    float auxSueldo = 0;

    printf("Ingrese numero de legajo: \n");
    scanf("%d", &auxLegajo);

    if (auxLegajo == 0) {
      puedeIngresar = 0;
    } else {
      printf("Ingrese sueldo: \n");
      scanf("%f", &auxSueldo);

      if (auxSueldo <= 0) {
        printf("Error, el sueldo tiene que se mayor a cero");
        puedeIngresar = 0;
      } else {
        legajo[i] = auxLegajo;
        sueldo[i] = auxSueldo;
      }
    }
    i++;
  }
}

void cargarHoras(int legajo2[], int hora[], int seccion[]) {
  int puedeIngresar = 1;
  int i = 0;

  while (puedeIngresar) {
    int auxLegajo = 0;
    int auxHora = 0;
    int auxSeccion = 0;

    printf("Ingrese numero de legajo: \t");
    scanf("%d", &auxLegajo);

    if (auxLegajo == 0) {
      puedeIngresar = 0;
    } else {
      printf("Ingrese horas trabajadas: \t");
      scanf("%d", &auxHora);

      if (auxHora <= 0) {
        printf("Error, las horas tienen que se mayor a cero");
      }

      printf("Ingrese seccion: \t");
      scanf("%d", &auxSeccion);

      if (auxSeccion < 101 || auxSeccion > 108) {
        printf("Error, la seccion tiene que ser entre 101 a 108");
        puedeIngresar = 0;
      } else {
        legajo2[i] = auxLegajo;
        hora[i] = auxHora;
        seccion[i] = auxSeccion;
      }
    }
    i++;
  }
}

void calcularTotal(int legajo[], int legajo2[], float sueldo[], int hora[],
                   int seccion[], int total[]) {

  for (int i = 0; i < 350; i++) {
    int auxLegajo2 = legajo2[i];
    int sueldoObtenido = buscarSueldo(auxLegajo2, legajo, sueldo);
    int auxTotal = sueldoObtenido * hora[i];

    total[seccion[i]] += auxTotal;
  }
}

int buscarSueldo(int numLegajo, int legajo[], float sueldo[]) {
  int sueldoEncontrado = 0;

  for (int i = 0; i < 350; i++) {
    if (legajo[i] == numLegajo) {
      sueldoEncontrado = sueldo[i];
    }
  }

  return sueldoEncontrado;
}

void mayoresSueldos(int legajo[], float sueldo[]) {
  int legajosMayores[350] = {0};
  float sueldosMayores[350] = {0};
  float mayorSueldo = 0;

  for (int j = 0; j < 350; j++) {

    if (
      mayorSueldo <= sueldo[j] && 
      legajosMayores[j] != legajo[j] &&
      legajo[j] != 0
      ) {
      legajosMayores[j] = legajo[j];
      sueldosMayores[j] = sueldo[j];
    }
  }


  printf("\nMAYORES SUELDOS: \n");
  printf("Legajo: \t Sueldo \n");

  for (int i = 0; i < 350; i++) {
    if(legajosMayores[i] != 0 || sueldosMayores[i] != 0) {
      printf("%d \t %f \n", legajosMayores[i], sueldosMayores[i]);
    }
  }
}

void mostrarVectores(int total[]) {
  printf("\nSUELDOS PAGADOS POR SECCION AL XX/XX/XXX \n");
  printf("Seccion: \t");
  printf("Importe pagado: \n");

  for (int i = 101; i < 107; i++) {
    for (int j = 101; j < 107 - i; j++) {

      if (total[j] > total[j + 1]) {

        int aux = total[j];
        total[j] = total[j + 1];
        total[j + 1] = aux;
      }
    }
  }

  for (int i = 101; i < 109; i++) {
    printf("%d \t", i);
    printf("%d \t \t \t \t \n", total[i]);
  }
}