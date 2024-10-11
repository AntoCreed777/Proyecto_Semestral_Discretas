#include <stdlib.h>
#include "memoria.h"


void liberacion_memoria_grafo(int **grafo, int n_vertices){
    for(int i = 0; i < n_vertices; i++) free(grafo[i]);
    free(grafo);
}