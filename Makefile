# Nombre del ejecutable
TARGET = tercer_paso

# Archivos objeto
OBJS = main.o usuarios.o productos.o

# Compilador
CC = gcc

# Opciones de compilación
CFLAGS = -Wall -g

# compilar todo y generar el ejecutable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Compilar main.c
main.o: main.c usuarios.h productos.h
	$(CC) $(CFLAGS) -c main.c -o main.o

# Compilar usuarios.c
usuarios.o: usuarios.c usuarios.h
	$(CC) $(CFLAGS) -c usuarios.c -o usuarios.o

# Compilar productos.c
productos.o: productos.c productos.h
	$(CC) $(CFLAGS) -c productos.c -o productos.o

asm:
	$(CC) -S main.c -o main.s
	$(CC) -S usuarios.c -o usuarios.s
	$(CC) -S productos.c -o productos.s

objdump:
	objdump -d main.o > main_objdump.s
	objdump -d usuarios.o > usuarios_objdump.s
	objdump -d productos.o > productos_objdump.s

# Limpiar archivos generados
clean:
	rm -f *.o *.s $(TARGET)

