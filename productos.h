#ifndef PRODUCTOS_H
#define PRODUCTOS_H

typedef struct {
    char codigo[20];
    char nombre[50];
    int cantidad;
    float costo;
    float precio;
} Producto;

typedef struct {
    int factura;
    char codigo[20];
    char nombre[50];
    int cantidadVendida;
    float costo;
    float precio;
} Venta;

//Metodos que se usan para los productos

Producto* cargarProductos(int *n);
void guardarProductos(Producto *p, int n);
int buscarProducto(Producto *p, int n, char *codigo);
int obtenerUltimaFactura();
void registrarVentas(Venta *v, int n);

#endif
