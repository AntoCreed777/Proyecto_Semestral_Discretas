# Nombre del ejecutable
TARGET = main.out

# Compilador
CC = gcc

# Opciones de compilación
CFLAGS = -I ./include -g -Wall

# Directorio para archivos objeto
OBJ_DIR = build

# Archivos fuente
SOURCES = ./src/main.c ./src/entrada.c ./src/memoria.c ./src/pila.c ./src/dfs.c

# Archivos objeto (guardados en build/)
OBJECTS = $(patsubst ./src/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

.PHONY: all clean run debug memoria

# Regla por defecto: compilar el programa
all: $(TARGET)

# Regla para compilar el programa
$(TARGET): $(OBJECTS)
	@echo "Compilando el programa..."
	@$(CC) $(OBJECTS) -o $(TARGET) $(CFLAGS)

# Regla para compilar los archivos objeto y guardarlos en obj/
$(OBJ_DIR)/%.o: ./src/%.c | $(OBJ_DIR)
	@echo "Compilando $<..."
	@$(CC) -c $< -o $@ $(CFLAGS)

# Crear el directorio obj si no existe
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Regla para ejecutar el programa
run: $(TARGET)
	@echo "Ejecutando el programa...\n"
	@./$(TARGET)

# Regla para debuggear el programa
debug: $(TARGET)
	@gdb ./$(TARGET)

# Regla para investigar las fugas de memoria
memoria: $(TARGET)
	@valgrind --leak-check=full --track-origins=yes ./$(TARGET)

# Regla para limpiar los archivos objeto y el ejecutable
clean:
	@rm -rf $(OBJ_DIR) $(TARGET)