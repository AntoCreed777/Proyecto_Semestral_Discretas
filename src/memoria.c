#include <stdlib.h>
#include "memoria.h"

/**
 * @brief Libera la memoria de la lista de adyacencia
 * 
 * @param grafo Lista de adyacencia del grafo
 * @param n_vertices Numero de vertices del grafo
 */
void liberacion_memoria_grafo(int **grafo, int n_vertices){
    for(int i = 0; i < n_vertices; i++) free(grafo[i]);
    free(grafo);
}