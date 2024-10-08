#include <stdio.h>
#include <stdlib.h>
#include "entrada.h"
#include "memoria.h"

int main(){
    int ** grafo = entrada_grafo(); // Se obtiene la matriz de adyacencia (hay que liberar memoria)

    // Se imprime la matriz de adyacencia
    for(int i = 0; grafo[i] != NULL; i++){
        for(int j = 0; grafo[i][j] != -1; j++){
            printf("%d ",grafo[i][j]);
        }
        printf("\n");
    }









    liberacion_memoria_grafo(grafo); // Se libera la memoria de la matriz de adyacencia
    return 0;
}