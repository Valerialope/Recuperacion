#include <stdio.h>
#include "funciones.h"

#define TAMANOMATRIZ 100

int main() {
    char NProducto[TAMANOMATRIZ][30] = {0};
    float cantidadPrecio[TAMANOMATRIZ][2] = {0};
    int productos_ingresados = 0;

    // Cargar productos al inicio del programa
    cargarProductosDesdeArchivo(NProducto, cantidadPrecio, &productos_ingresados);

    int opcion;
    do {
        printf("\n----- Menu -----\n");
        printf("1. Ingresar producto\n");
        printf("2. Mostrar productos\n");
        printf("3. Buscar producto\n");
        printf("4. Editar producto\n");
        printf("5. Eliminar producto\n");
        printf("0. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer de entrada

        switch (opcion) {
            case 1:
                ingresarProductos(NProducto, cantidadPrecio, TAMANOMATRIZ, &productos_ingresados);
                break;
            case 2:
                mostrarProductos(NProducto, cantidadPrecio, productos_ingresados);
                break;
            case 3:
                buscarProducto(NProducto, cantidadPrecio, productos_ingresados);
                break;
            case 4:
                editarProducto(NProducto, cantidadPrecio, productos_ingresados);
                break;
            case 5:
                eliminarProducto(NProducto, cantidadPrecio, &productos_ingresados);
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }

    } while (opcion != 0);

    // Guardar productos al salir del programa
    guardarProductosEnArchivo(NProducto, cantidadPrecio, productos_ingresados);

    return 0;
}
