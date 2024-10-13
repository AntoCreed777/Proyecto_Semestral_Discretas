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

    // Lista de vertices ignorados que representa los vertices que se eliminan del grafo (pero sin modificar la lista de adyacencia)
    bool *ignorados = (bool*)malloc(sizeof(bool) * n_vertices);
    for(int i = 0; i < n_vertices; i++) ignorados[i] = false;

    //  ZONA PARA IGNORAR VERTICES

    ignorados[0] = true;
    ignorados[1] = true;
    ignorados[2] = true;

    //  FIN DE ZONA PARA IGNORAR VERTICES

    // Se verifica si el grafo es conexo
    int conexo = dfs_coneccidad(grafo, n_vertices, ignorados);
    if(conexo == true) printf(VERDE "El grafo es conexo\n" RESET_COLOR);
    else if(conexo == false) printf(MAGENTA "El grafo no es conexo\n" RESET_COLOR);
    else printf(ROJO "Error al verificar la conexidad del grafo\n" RESET_COLOR);


    liberacion_memoria_grafo(grafo, n_vertices); // Se libera la memoria de la lista de adyacencia
    free(ignorados); // Se libera la memoria de la lista de vertices ignorados
    return 0;
}