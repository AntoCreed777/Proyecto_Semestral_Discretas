#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constantes.h"
#include "entrada.h"

#define tamaño_ruta 256
#define BUFFER_SIZE 1024

void entrada_grafo(int ***grafo, int *n_vertices) {
    char *ruta_grafo = "/mnt/c/Users/AntoCreed777/Documents/GitHub/Proyecto_Semestral_Discretas/grafo.txt";
    printf("Ruta del archivo: %s\n", ruta_grafo);
    
    FILE *file = fopen(ruta_grafo, "r");
    if (file == NULL) {
        perror(ROJO "Error al abrir el archivo" RESET_COLOR);
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d", n_vertices);
    printf(CIAN "\nNumero de vertices: %d\n" RESET_COLOR, *n_vertices);

    // Asignar memoria para la matriz de adyacencia
    *grafo = (int**)malloc(sizeof(int*) * (*n_vertices));
    for (int i = 0; i < *n_vertices; i++) {
        (*grafo)[i] = (int*)malloc(sizeof(int) * (*n_vertices+1));
    }

    char buffer[BUFFER_SIZE];
    int i = -1; // Comienza en -1 para omitir la primera fila

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char *numero = strtok(buffer, ",: ");
        int j = 0;
        while (numero != NULL && i != -1) {
            // Omitir la primera columna que contiene el vertice al que la fila corresponde
            if (j > 0) (*grafo)[i][j - 1] = atoi(numero) - 1;  // Se omite la primera columna  // Se resta 1 para que los vertices comiencen en 0

            numero = strtok(NULL, ",: ");
            j++;
        }

        if(i != -1) (*grafo)[i][j - 1] = -1; // Marcar el final de la fila
        i++;
    }

    fclose(file);
}