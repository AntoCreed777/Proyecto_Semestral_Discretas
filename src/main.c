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

    /*
    // Lista con los vertices que se ignoraran
    int ignorados[] = {0, -1}; // Se indica el fin de la lista con -1

    // Se verifica si el grafo es conexo
    impresion_resultado_dfs(dfs_coneccidad(grafo, n_vertices, ignorados));
    */

    // Se verifica la conexidad del grafo ignorando un vertice
    for (int i = 0; i < n_vertices; i++){
        int ignorados[] = {i, -1}; // Se indica el fin de la lista con -1
        printf(BLANCO "Ignorando el vertice " AMARILLO "%d" BLANCO " :\t" RESET_COLOR, i);
        impresion_resultado_dfs(dfs_coneccidad(grafo, n_vertices, ignorados));
    }

    printf("\n\n");

    // Se verifica la conexidad del grafo ignorando dos vertices
    for (int i = 0; i < n_vertices; i++) {
        for (int j = 0; j < n_vertices; j++) {
            if (i != j) {
                int ignorados[] = {i, j, -1}; // Se indica el fin de la lista con -1
                printf(BLANCO "Ignorando los vertices " AMARILLO "%d" BLANCO " y " AMARILLO "%d" BLANCO " :\t" RESET_COLOR, i, j);
                impresion_resultado_dfs(dfs_coneccidad(grafo, n_vertices, ignorados));
            }
        }
    }

    printf("\n\n");

    // Se verifica la conexidad del grafo ignorando tres vertices
    for (int i = 0; i < n_vertices; i++) {
        for (int j = 0; j < n_vertices; j++) {
            for (int k = 0; k < n_vertices; k++) {
                if (i != j && i != k && j != k) {
                    int ignorados[] = {i, j, k, -1}; // Se indica el fin de la lista con -1
                    printf(BLANCO "Ignorando los vertices " AMARILLO "%d" BLANCO ", " AMARILLO "%d" BLANCO " y " AMARILLO "%d" BLANCO " :\t" RESET_COLOR, i, j, k);
                    impresion_resultado_dfs(dfs_coneccidad(grafo, n_vertices, ignorados));
                }
            }
        }
    }

    printf("\n\n");

    // Se verifica la conexidad del grafo ignorando cuatro vertices
    for (int i = 0; i < n_vertices; i++) {
        for (int j = 0; j < n_vertices; j++) {
            for (int k = 0; k < n_vertices; k++) {
                for (int l = 0; l < n_vertices; l++) {
                    if (i != j && i != k && i != l && j != k && j != l && k != l) {
                        int ignorados[] = {i, j, k, l, -1}; // Se indica el fin de la lista con -1
                        printf(BLANCO "Ignorando los vertices " AMARILLO "%d" BLANCO ", " AMARILLO "%d" BLANCO ", " AMARILLO "%d" BLANCO " y " AMARILLO "%d" BLANCO " :\t" RESET_COLOR, i, j, k, l);
                        impresion_resultado_dfs(dfs_coneccidad(grafo, n_vertices, ignorados));
                    }
                }
            }
        }
    }

    liberacion_memoria_grafo(grafo, n_vertices); // Se libera la memoria de la lista de adyacencia
    return 0;
}