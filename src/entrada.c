#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constantes.h"
#include "entrada.h"

#define tamaño_ruta 256
#define BUFFER_SIZE 1024


/**
 * @brief Recibe la ruta de un archivo y lo abre
 * 
 * @return FILE* Archivo abierto
 * @note Sale del programa si el usuario ingresa "exit"
 */
FILE *recibir_archivo() {
    char ruta[tamaño_ruta];
    printf(AMARILLO "Ingrese la ruta del archivo (\"exit\" para salir del programa): " RESET_COLOR);
    scanf("%s", ruta);

    do{
        if (strcmp(ruta, "exit") == 0) exit(EXIT_SUCCESS);

        FILE *file = fopen(ruta, "r");
        if (file == NULL) {
            perror(ROJO "Error al abrir el archivo" RESET_COLOR);
            printf(AMARILLO "\nIngrese la ruta del archivo (\"exit\" para salir del programa): " RESET_COLOR);
            scanf("%s", ruta);
        }
        else return file;
    } while (1);
}


/**
 * @brief Obtiene la lista de adyacencia de un grafo
 * 
 * @param grafo Lista de adyacencia del grafo (Se modifica por referencia)
 * @param n_vertices Numero de vertices del grafo (Se modifica por referencia)
 */
void entrada_grafo(int ***grafo, int *n_vertices) {
    FILE *file = recibir_archivo();

    fscanf(file, "%d", n_vertices);
    printf(CIAN "\nNumero de vertices: %d\n\n" RESET_COLOR, *n_vertices);

    // Asignar memoria para la matriz de adyacencia
    *grafo = (int**)malloc(sizeof(int*) * (*n_vertices));
    for (int i = 0; i < *n_vertices; i++) {
        (*grafo)[i] = (int*)malloc(sizeof(int) * (*n_vertices+1));
    }

    char buffer[BUFFER_SIZE];
    int vertice = 0;
    
    fgets(buffer, sizeof(buffer), file);  // Ignorar la primera linea
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char *numero = strtok(buffer, ",: ");
        int j = 0;
        while (numero != NULL) {
            if (j == 0) vertice = atoi(numero) - 1;  // Se resta 1 para que los vertices comiencen en 0
            else (*grafo)[vertice][j - 1] = atoi(numero) - 1;  // Se resta 1 para que los vertices comiencen en 0

            numero = strtok(NULL, ",: ");
            j++;
        }
        (*grafo)[vertice][j - 1] = -1; // Marcar el final de la fila
    }

    fclose(file);
}