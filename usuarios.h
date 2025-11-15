#ifndef USUARIOS_H
#define USUARIOS_H

//Estructura para los usuarios

typedef struct {
    char usuario[30];
    char clave[30];
    char nombre[50];
} Usuario;

//Función para validar el login
int verificarLogin();

#endif
