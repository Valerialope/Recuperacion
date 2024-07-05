#ifndef FUNCIONES_H
#define FUNCIONES_H

void ingresarProductos(char NProducto[][30], float cantidadPrecio[][2], int tamanomatriz, int *productos_ingresados);
void mostrarProductos(char NProducto[][30], float cantidadPrecio[][2], int productos_ingresados);
void buscarProducto(char NProducto[][30], float cantidadPrecio[][2], int productos_ingresados);
void editarProducto(char NProducto[][30], float cantidadPrecio[][2], int productos_ingresados);
void eliminarProducto(char NProducto[][30], float cantidadPrecio[][2], int *productos_ingresados);
void cargarProductosDesdeArchivo(char NProducto[][30], float cantidadPrecio[][2], int *productos_ingresados);
void guardarProductosEnArchivo(char NProducto[][30], float cantidadPrecio[][2], int productos_ingresados);

#endif /* FUNCIONES_H */
