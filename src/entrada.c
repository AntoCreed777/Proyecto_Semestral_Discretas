#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamaño_ruta 256
#define BUFFER_SIZE 1024

int** entrada_grafo(){
    char *ruta_grafo = "/mnt/c/Users/AntoCreed777/Documents/GitHub/Proyecto_Semestral_Discretas/grafo.txt";
    printf("Ruta del archivo: %s\n", ruta_grafo);
    
    FILE *file = fopen(ruta_grafo, "r");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    int n_vertices;
    fscanf(file, "%d", &n_vertices);
    printf("\nNumero de vertices: %d\n", n_vertices);

    // Asignar memoria para la matriz de adyacencia
    int **matriz_adyacencia = (int**)malloc(sizeof(int*) * (n_vertices+1));
    matriz_adyacencia[n_vertices] = NULL;   // Marcar el final de la matriz
    for (int i = 0; i < n_vertices; i++) {
        matriz_adyacencia[i] = (int*)malloc(sizeof(int) * (n_vertices+1));
    }

    char buffer[BUFFER_SIZE];
    int i = -1; // Comienza en -1 para omitir la primera fila

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char *numero = strtok(buffer, ",: ");
        int j = 0;
        while (numero != NULL && i != -1) {
            // Omitir la primera columna que contiene el vertice al que la fila corresponde
            if (j > 0) matriz_adyacencia[i][j - 1] = atoi(numero);  // Se omite la primera columna

            numero = strtok(NULL, ",: ");
            j++;
        }

        if(i != -1) matriz_adyacencia[i][j - 1] = -1; // Marcar el final de la fila
        i++;
    }

    fclose(file);
    return matriz_adyacencia;
}