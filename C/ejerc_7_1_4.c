#include <stdio.h>

int buscarValor(int[], int);
void ordenar(int[], float[], int[]);
int contar(int[], int[]);

int main() {
  int codigos[10] = {0};   // 10001 a 10010 => 1 a 10
  float precios[10] = {0}; // Real > 0
  int reintento = 0;

  int codigosCantidades[10] = {0};
  int cantidades[10] = {0}; // > 0

  printf("\n \n CARGA DE CODIGOS Y PRECIOS: \n");
  // Carga de codigos y precios
  for (int i = 0; i < 10; i++) {
    do {
      int auxCodigo = 0;
      float auxPrecio = 0;

      printf("Ingrese codigo: \t");
      scanf("%d", &auxCodigo);

      int existe = buscarValor(codigos, auxCodigo);

      if (existe != -1) {
        printf("Error: el codigo ya existe \n");
        reintento = 1;
      } else if ((auxCodigo < 10001 || auxCodigo > 10010) && auxCodigo != 0) {
        printf("Error: el codigo debe estar en el rango de 10001 a 10010 \n");
        reintento = 1;
      } else {
        printf("Ingrese precio unitario: ");
        scanf("%f", &auxPrecio);

        if (auxPrecio <= 0) {
          printf("Error: el precio tiene que ser mayor a cero \n");
          reintento = 1;
        } else {
          reintento = 0;

          codigos[i] = auxCodigo;
          precios[i] = auxPrecio;
        }
      }
    } while (reintento);
  }

  printf("\n \n CARGA DE CODIGOS Y CANTIDADES: \n");

  // Carga de codigos y cantidades
  int indice = 0;
  int puedeIngresar = 1;
  while (puedeIngresar && indice < 10) {
    int auxCodigo = 0;
    int auxCantidad = 0;

    printf("Ingrese codigo: \t");
    scanf("%d", &auxCodigo);

    if (auxCodigo == 0) {
      puedeIngresar = 0;
    } else {
      printf("Ingrese cantidad: \n");
      scanf("%d", &auxCantidad);

      if (auxCantidad <= 0) {
        printf("Error: la cantidad debe ser mayor a 0 \n");
      } if (auxCodigo == 0 || buscarValor(codigos, auxCodigo) == -1) {
        printf("Error: el codigo no existe \n");
      } else {
        codigosCantidades[indice] = auxCodigo;
        cantidades[indice] = auxCantidad;

        indice++;
      }
    }
  }

  // Mostrar listado con codigo, cantidades y importe vendido
  ordenar(codigos, precios, cantidades);

  printf("Codigo \t Cantidad \t Importe vendido \n");
  for (int i = 0; i < 10; i++) {
    float precio = precios[buscarValor(codigos, codigosCantidades[i])];
    float importe = precio * cantidades[i];

    printf("%d \t %d \t \t %f \n", codigos[i], cantidades[i], importe);
  }

  // Probabilidad de productos con 1000 unidades
  int cant = contar(codigosCantidades, cantidades);
  float probabilidad = (float)cant / 10 * 100;
  printf("Porcentaje %f \n", probabilidad);

  // Producto/s que vendio/eron el menor importe
  for (int i = 0; i < 10; i++) {
    
  }

  return 0;
}

void ordenar(int C[], float P[], int cantidades[]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 9 - i; j++) {
      if (cantidades[j] < cantidades[j + 1]) {
        int aux1 = cantidades[j];
        cantidades[j] = cantidades[j + 1];
        cantidades[j + 1] = aux1;

        int aux2 = C[j];
        C[j] = C[j + 1];
        C[j + 1] = aux2;

        float aux3 = P[j];
        P[j] = P[j + 1];
        P[j + 1] = aux3;
      }
    }
  }
}

int buscarValor(int vec[], int valor) {
  for (int i = 0; i < 10; i++) {
    if (valor == vec[i] && vec[i] != 0)
      return i;
  }

  return -1;
}

int contar(int codigosCantidades[], int cantidades[]) {
  int acumuladorPorCodigo[10] = {0};
  int cont = 0;

  for (int i = 0; i < 10; i++) {
    if (cantidades[i] != 0) {
      int indice = codigosCantidades[i] - 10001;
      acumuladorPorCodigo[indice] += cantidades[indice];
    }
  }

  for (int i = 0; i < 10; i++) {
    if (acumuladorPorCodigo[i] > 1000)
      cont++;
  }

  return cont;
}