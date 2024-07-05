#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresarProductos(char NProducto[][30], float cantidadPrecio[][2], int tamanomatriz, int *productos_ingresados) {
    if (*productos_ingresados >= tamanomatriz) {
        printf("No hay espacio suficiente para ingresar más productos.\n");
        return;
    }

    printf("Ingrese el nombre del producto: ");
    scanf("%29[^\n]", NProducto[*productos_ingresados]);
    getchar(); // Limpiar buffer de entrada

    printf("Ingrese la cantidad del producto: ");
    scanf("%f", &cantidadPrecio[*productos_ingresados][0]);

    printf("Ingrese el precio del producto: ");
    scanf("%f", &cantidadPrecio[*productos_ingresados][1]);

    (*productos_ingresados)++;
    printf("Producto ingresado correctamente.\n");

  }




void mostrarProductos(char NProducto[][30], float cantidadPrecio[][2], int productos_ingresados) {
    printf("\n%-15s%-15s%-15s\n", "N.Producto", "Cantidad", "Precio");
    for (int i = 0; i < productos_ingresados; i++) {
        printf("%-15s%-15.2f%-15.2f\n", NProducto[i], cantidadPrecio[i][0], cantidadPrecio[i][1]);
    }
}

void buscarProducto(char NProducto[][30], float cantidadPrecio[][2], int productos_ingresados) {
    char buscar[30];
    printf("Ingrese el nombre del producto a buscar: ");
    scanf(" %29[^\n]", buscar);
    getchar(); // Limpiar buffer de entrada

    int encontrado = 0;
    for (int i = 0; i < productos_ingresados; i++) {
        if (strcmp(NProducto[i], buscar) == 0) {
            printf("Producto encontrado:\n");
            printf("Nombre: %s\n", NProducto[i]);
            printf("Cantidad: %.2f\n", cantidadPrecio[i][0]);
            printf("Precio: %.2f\n", cantidadPrecio[i][1]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}

void editarProducto(char NProducto[][30], float cantidadPrecio[][2], int productos_ingresados) {
    char buscar[30];
    printf("Ingrese el nombre del producto a editar: ");
    scanf(" %29[^\n]", buscar);
    getchar(); // Limpiar buffer de entrada

    int encontrado = 0;
    for (int i = 0; i < productos_ingresados; i++) {
        if (strcmp(NProducto[i], buscar) == 0) {
            printf("Ingrese el nuevo nombre del producto: ");
            scanf(" %29[^\n]", NProducto[i]);
            getchar(); // Limpiar buffer de entrada

            printf("Ingrese la nueva cantidad del producto: ");
            scanf("%f", &cantidadPrecio[i][0]);

            printf("Ingrese el nuevo precio del producto: ");
            scanf("%f", &cantidadPrecio[i][1]);

            printf("Producto editado correctamente.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}

void eliminarProducto(char NProducto[][30], float cantidadPrecio[][2], int *productos_ingresados) {
    char buscar[30];
    printf("Ingrese el nombre del producto a eliminar: ");
    scanf(" %29[^\n]", buscar);
    getchar(); // Limpiar buffer de entrada

    int encontrado = 0;
    for (int i = 0; i < *productos_ingresados; i++) {
        if (strcmp(NProducto[i], buscar) == 0) {
            for (int j = i; j < *productos_ingresados - 1; j++) {
                strcpy(NProducto[j], NProducto[j + 1]);
                cantidadPrecio[j][0] = cantidadPrecio[j + 1][0];
                cantidadPrecio[j][1] = cantidadPrecio[j + 1][1];
            }
            (*productos_ingresados)--;
            printf("Producto eliminado correctamente.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}

void cargarProductosDesdeArchivo(char NProducto[][30], float cantidadPrecio[][2], int *productos_ingresados) {
    FILE *archivo;
    archivo = fopen("productos.txt", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo productos.txt\n");
        return;
    }

    int i = 0;
    while (fscanf(archivo, "%29s %f %f\n", NProducto[i], &cantidadPrecio[i][0], &cantidadPrecio[i][1]) == 3) {
        i++;
    }
    *productos_ingresados = i;

    fclose(archivo);
}

void guardarProductosEnArchivo(char NProducto[][30], float cantidadPrecio[][2], int productos_ingresados) {
    FILE *archivo;
    archivo = fopen("productos.txt", "w");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo productos.txt\n");
        return;
    }

    for (int i = 0; i < productos_ingresados; i++) {
        fprintf(archivo, "%s %.2f %.2f\n", NProducto[i], cantidadPrecio[i][0], cantidadPrecio[i][1]);
    }

    fclose(archivo);
}
