# Makefile para Práctica de Grafos
# Compilador y flags
CC = gcc
CFLAGS = -fdiagnostics-color=always -g -std=c90 -Wall -Wextra -Werror -Wpedantic

# Archivos fuente
SRCS = main.c grafos.c colas.c
OBJS = $(SRCS:.c=.o)
TARGET = grafos_programa

# Regla principal
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Reglas de compilación
main.o: main.c grafos.h colas.h 
	$(CC) $(CFLAGS) -c main.c

grafos.o: grafos.c grafos.h colas.h
	$(CC) $(CFLAGS) -c grafos.c

colas.o: colas.c colas.h
	$(CC) $(CFLAGS) -c colas.c

# Limpieza
clean:
	rm -f $(OBJS) $(TARGET)

# Recompilar todo
rebuild: clean all

# Ejecutar programa
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean rebuild run