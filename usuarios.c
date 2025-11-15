#include <stdio.h>
#include <string.h>
#include "usuarios.h"

int verificarLogin() {
    char user[30], pass[30];
    int intentos = 0;

//MAX 3 Intentos de inicio de sesión
    while (intentos < 3) {
        //Pide el usuario y la contraseña
        printf("Usuario: ");
        scanf("%s", user);

        printf("Clave: ");
        scanf("%s", pass);

        FILE *f = fopen("vendedores.txt", "r");
        if (!f) {
            printf("No se pudo abrir vendedores.txt\n");
            return 0;
        }

        char linea[150];
        int encontrado = 0;
        //Verifica si el usuario se encuentra en el archivo
        while (fgets(linea, sizeof(linea), f)) {
            Usuario u;

            char *token = strtok(linea, ",");
            strcpy(u.usuario, token);

            token = strtok(NULL, ",");
            strcpy(u.clave, token);

            token = strtok(NULL, "\n");
            strcpy(u.nombre, token);

            if (strcmp(user, u.usuario) == 0 && strcmp(pass, u.clave) == 0) {
                printf("Bienvenido %s\n", u.nombre);
                encontrado = 1;
                break;
            }
        }

        fclose(f);

        if (encontrado) return 1;

        intentos++;
        printf("Credenciales incorrectas. Intentos: %d/3\n", intentos);
    }

    printf("Se excedieron los intentos. Saliendo...\n");
    return 0;
}
