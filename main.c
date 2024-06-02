#include "funciones.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int n = 0;
  int M = 6;
  int FilaAEditar;
  int funcion = 0;
  char nombreProducto[50];

  printf("Ingrese el número de productos que va a ingresar:\n");
  scanf("%d", &n);

  if (n <= 0) {
    printf("El número de productos debe ser mayor que 0\n");
    return 0;
  }

  printf("NOMBRE DE PRODUCTO     PRECIO     CANTIDAD     CATEGORIA     TALLA   "
         "      GENERO\n");
  char productos[n][M][50];

  for (int i = 0; i < n; i++) {
    printf("Producto %d:\n", i + 1);
    for (int j = 0; j < M; j++) {
      scanf("%s", productos[i][j]);
    }
  }

  while (funcion != 6) {
    printf("digite el numero de la funcion que desea \n(1) eliminar un "
           "producto \n(2) editar un producto \n(3) buscar un producto \n(4) "
           "desea imprimir lista de productos\n(5) agregar productos\n(6)Para salir\n\n\n");
    scanf("%d", &funcion);
    switch (funcion) {
    case 1:
      printf("Ingrese el nombre del producto que desea eliminar:");
      scanf("%s", nombreProducto);
      eliminarFilaPorNombre(&n, M, productos, nombreProducto);
      printf("\n\n\n");
      break;
    case 2:
      printf("Ingrese el número de producto que desea editar: ");
      scanf("%d", &FilaAEditar);
      char nuevoValor[50];
      editarFila(&n, M, productos, FilaAEditar, nuevoValor);
      printf("\n\n\n");
      break;
    case 3:
      printf("Ingrese el nombre de la categoria, talla o genero:\n\n\n");
      scanf("%s", nombreProducto);
      buscarProductoPorNombre(n, M, productos, nombreProducto);
      break;
    case 4:
      imprimirMatriz(n, M, productos);
      printf("\n\n\n");
      break;
    case 5:
      agregarFila(&n, M, productos);
      printf("\n\n\n");
      break;
    }
  }

  return 0;
}
// BUZO    10  5   VERANO  L   MUJER
// SHORT   30  5   PRIMAVERA   L   MUJER
// PANTALON    12  10  INVIERNO    M   HOMBRE
