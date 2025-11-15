#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "productos.h"

Producto* cargarProductos(int *n) {
    FILE *f = fopen("producto.txt", "r");
    if (!f) {
        printf("No se pudo abrir producto.txt\n");
        *n = 0;
        return NULL;
    }

    Producto *lista = NULL;
    char linea[200];
    *n = 0;

    while (fgets(linea, sizeof(linea), f)) {
        Producto temp;
        char *token = strtok(linea, ",");
        strcpy(temp.codigo, token);

        token = strtok(NULL, ",");
        strcpy(temp.nombre, token);

        token = strtok(NULL, ",");
        temp.cantidad = atoi(token);

        token = strtok(NULL, ",");
        temp.costo = atof(token);

        token = strtok(NULL, "\n");
        temp.precio = atof(token);

        lista = realloc(lista, (*n + 1) * sizeof(Producto));
        lista[*n] = temp;
        (*n)++;
    }

    fclose(f);
    return lista;
}
//Actualiza los cambios realizados en el archivo
void guardarProductos(Producto *p, int n) {
    FILE *f = fopen("producto.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(f, "%s,%s,%d,%.2f,%.2f\n",
                p[i].codigo, p[i].nombre, p[i].cantidad, p[i].costo, p[i].precio);
    }
    fclose(f);
}
//Busca por codigo el producto 
int buscarProducto(Producto *p, int n, char *codigo) {
    for (int i = 0; i < n; i++) {
        if (strcmp(p[i].codigo, codigo) == 0)
            return i;
    }
    return -1;
}
//
int obtenerUltimaFactura() {
    FILE *f = fopen("ventas.txt", "r");
    if (!f) return 0;

    char linea[200];
    int ultima = 0;

    while (fgets(linea, sizeof(linea), f)) {
        int factura;
        sscanf(linea, "%d", &factura);
        ultima = factura;
    }

    fclose(f);
    return ultima;
}
//Registra todas las ventas realizadas
void registrarVentas(Venta *v, int n) {
    FILE *f = fopen("ventas.txt", "a");
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d,%s,%s,%d,%.2f,%.2f\n",
                v[i].factura, v[i].codigo, v[i].nombre,
                v[i].cantidadVendida, v[i].costo, v[i].precio);
    }
    fclose(f);
}
