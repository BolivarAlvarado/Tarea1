#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "usuarios.h"
#include "productos.h"

int main() {
    //Se verifica el login
    if (!verificarLogin())
        return 0;

    //Se cargan los productos, se crea un arreglo para guardar las ventas ingresadas
    int nProd;
    Producto *productos = cargarProductos(&nProd);

    Venta ventas[50];
    int nVentas = 0;

    int factura = obtenerUltimaFactura() + 1;

    while (1) {
        char codigo[20];
        int cant;

        printf("\nIngrese código de producto (0 para terminar): ");
        scanf("%s", codigo);

        if (strcmp(codigo, "0") == 0)
            break;

        int pos = buscarProducto(productos, nProd, codigo);

        if (pos == -1) {
            printf("Producto no encontrado.\n");
            continue;
        }

        printf("Cantidad a vender: ");
        scanf("%d", &cant);

        if (cant > productos[pos].cantidad) {
            printf("Inventario insuficiente.\n");
            continue;
        }

        Venta v;
        v.factura = factura;
        strcpy(v.codigo, productos[pos].codigo);
        strcpy(v.nombre, productos[pos].nombre);
        v.cantidadVendida = cant;
        v.costo = productos[pos].costo;
        v.precio = productos[pos].precio;

        ventas[nVentas++] = v;
    }

    int confirmar;
    printf("\nConfirmar venta? (1=Sí, 0=No): ");
    scanf("%d", &confirmar);

    if (confirmar) {
        for (int i = 0; i < nVentas; i++) {
            int pos = buscarProducto(productos, nProd, ventas[i].codigo);
            productos[pos].cantidad -= ventas[i].cantidadVendida;
        }

        guardarProductos(productos, nProd);
        registrarVentas(ventas, nVentas);

        printf("Venta registrada.\n");
    } else {
        printf("Venta cancelada.\n");
    }

    free(productos);
    return 0;
}
