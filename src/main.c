#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "constantes.h"
#include "entrada.h"
#include "memoria.h"
#include "dfs.h"

void impresion_grafo(int **grafo, int n_vertices){
    for(int i = 0; i < n_vertices; i++){
        for(int j = 0; grafo[i][j] != -1; j++){
            printf(AMARILLO "%d " RESET_COLOR,grafo[i][j]);
        }
        printf("\n");
    }
}

void impresion_resultado_dfs(int conexo){
    if(conexo == true) printf(VERDE "El grafo es conexo\n" RESET_COLOR);
    else if(conexo == false) printf(MAGENTA "El grafo no es conexo\n" RESET_COLOR);
    else printf(ROJO "Error al verificar la conexidad del grafo\n" RESET_COLOR);
}

int main(){
    int **grafo = NULL; // Lista de adyacencia indexado a 0
    int n_vertices;
    entrada_grafo(&grafo, &n_vertices); // Se obtiene la lista de adyacencia (hay que liberar memoria)

    // Se imprime la lista de adyacencia
    //impresion_grafo(grafo, n_vertices);

    // Lista con los vertices que se ignoraran
    int ignorados[] = {0, -1}; // Se indica el fin de la lista con -1

    // Se verifica si el grafo es conexo
    impresion_resultado_dfs(dfs_coneccidad(grafo, n_vertices, ignorados));

    liberacion_memoria_grafo(grafo, n_vertices); // Se libera la memoria de la lista de adyacencia
    return 0;
}