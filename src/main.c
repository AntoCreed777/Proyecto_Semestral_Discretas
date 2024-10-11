#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "constantes.h"
#include "entrada.h"
#include "memoria.h"
#include "dfs.h"

int main(){
    int **grafo = NULL; // Lista de adyacencia indexado a 0
    int n_vertices;
    entrada_grafo(&grafo, &n_vertices); // Se obtiene la lista de adyacencia (hay que liberar memoria)

    // Se imprime la lista de adyacencia
    for(int i = 0; i < n_vertices; i++){
        for(int j = 0; grafo[i][j] != -1; j++){
            printf(AMARILLO "%d " RESET_COLOR,grafo[i][j]);
        }
        printf("\n");
    }

    // Se crea un arreglo de booleanos para marcar los vertices visitados
    bool *visitados = (bool*)malloc(sizeof(bool) * n_vertices);
    for (int i = 0; i < n_vertices; i++) visitados[i] = false;

    // Se verifica si el grafo es conexo
    int conexo = dfs_coneccidad(grafo, 5, 0, visitados);
    if(conexo == true) printf(VERDE "El grafo es conexo\n" RESET_COLOR);
    else if(conexo == false) printf(MAGENTA "El grafo no es conexo\n" RESET_COLOR);
    else printf(ROJO "Error al verificar la conexidad del grafo\n" RESET_COLOR);


    liberacion_memoria_grafo(grafo, n_vertices); // Se libera la memoria de la matriz de adyacencia
    free(visitados);

    return 0;
}