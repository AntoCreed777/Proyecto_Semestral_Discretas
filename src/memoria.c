#include <stdlib.h>


void liberacion_memoria_grafo(int **grafo){
    for(int i = 0; grafo[i] != NULL; i++){
        free(grafo[i]);
    }
    free(grafo);
}