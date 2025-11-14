#ifndef PRODUCTOS_H
#define Productos_H

typedef struct{
    char codigo[20];
    char nombre[50];
    int cantidad;
    float costo;
    float precio;
} Producto;

typedef struct{
    int numFactura;
    char codigo[20];
    char nombre[50];
    int cantidadVendiad;
    float csoto;
    float precio;
    char fecha[15];
} Venta;

Producto *cargarProductos(int *n);
void guardarProductos(Producto *productos, int n);
int buscarProducto(Producto *p, int n, char *codigo);
int obtenerUltimaFactura();
void registrarVenta(Venta * ventas, int nVentas);

#endif