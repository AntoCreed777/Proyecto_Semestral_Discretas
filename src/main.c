#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "constantes.h"
#include "entrada.h"
#include "memoria.h"
#include "dfs.h"

#define ERROR 2
#define INF 1e9

/**
 * @brief Imprime la lista de adyacencia del grafo
 * 
 * @param grafo Lista de adyacencia del grafo
 * @param n_vertices Numero de vertices del grafo
 */
void impresion_grafo(int **grafo, int n_vertices){
    for(int i = 0; i < n_vertices; i++){
        for(int j = 0; grafo[i][j] != -1; j++){
            printf(AMARILLO "%d " RESET_COLOR,grafo[i][j]);
        }
        printf("\n");
    }
}


/**
 * @brief Verifica si el grafo es conexo
 * 
 * @param conexo Variable que indica si el grafo es conexo
 */
void impresion_resultado_dfs(int conexo){
    if(conexo == true) printf(VERDE "El grafo es conexo\n" RESET_COLOR);
    else if(conexo == false) printf(MAGENTA "El grafo no es conexo\n" RESET_COLOR);
    else printf(ROJO "Error al verificar la conexidad del grafo\n" RESET_COLOR);
}

/**
 * @brief Verifica si el grafo es k-conexo
 * 
 * @param k_conexo Variable que indica la k-conexidad del grafo
 */
void impresion_resultado_dfs_k_conexo(int k_conexo){
    if(k_conexo == true) printf(AMARILLO "El grafo es %d-conexo\n" RESET_COLOR, k_conexo);
    else if(k_conexo == false) printf(MAGENTA "El grafo no es k-conexo\n" RESET_COLOR);
    else printf(ROJO "Error al verificar la k-conexidad del grafo\n" RESET_COLOR);
}

/**
 * @brief Verifica la conexidad del grafo ignorando conjuntos de vertices
 * 
 * @param grafo Lista de adyacencia del grafo
 * @param n_vertices Numero de vertices del grafo
 */
void rastreo_de_coneccidad_4_salida_completa(int **grafo, int n_vertices){
    // Se verifica la conexidad del grafo sin eliminar vertices
    int ignorados[] = {-1}; // Se indica el fin de la lista con -1
    printf(BLANCO "NO SE IGNORAN VERTICES " AMARILLO "\"GRAFO ORIGINAL\"" BLANCO " :\t" RESET_COLOR);
    impresion_resultado_dfs(dfs_coneccidad(grafo, n_vertices, ignorados));

    printf("\n\n");

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
}

/**
 * @brief Verifica la k-conexidad del grafo
 * 
 * @param grafo Lista de adyacencia del grafo
 * @param n_vertices Numero de vertices del grafo
 * @return int 1 si es 1-conexo, 2 si es 2-conexo, 3 si es 3-conexo, 4 si es 4-conexo, 5 si es k-conexo >= 5, -1 si hay un error
 */
int rastreo_de_k_coneccidad_hasta_4(int **grafo, int n_vertices){
    // Se verifica la conexidad del grafo ignorando un vertice
    for (int i = 0; i < n_vertices; i++){
        int ignorados[] = {i, -1}; // Se indica el fin de la lista con -1
        int conexo = dfs_coneccidad(grafo, n_vertices, ignorados);
        if(conexo == false) return 1;
        else if(conexo == ERROR) return -1;
    }

    printf("\n\n");

    // Se verifica la conexidad del grafo ignorando dos vertices
    for (int i = 0; i < n_vertices; i++) {
        for (int j = 0; j < n_vertices; j++) {
            if (i != j) {
                int ignorados[] = {i, j, -1}; // Se indica el fin de la lista con -1
                int conexo = dfs_coneccidad(grafo, n_vertices, ignorados);
                if(conexo == false) return 2;
                else if(conexo == ERROR) return -1;
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
                    int conexo = dfs_coneccidad(grafo, n_vertices, ignorados);
                    if(conexo == false) return 3;
                    else if(conexo == ERROR) return -1;
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
                        int conexo = dfs_coneccidad(grafo, n_vertices, ignorados);
                        if(conexo == false) return 4;
                        else if(conexo == ERROR) return -1;
                    }
                }
            }
        }
    }

    return 5;   //Para indicar que es k_conexo >= 5
}

/**
 * @brief Encuentra el grado maximo y minimo del grafo
 * 
 * @param grafo Lista de adyacencia del grafo
 * @param n_vertices Numero de vertices del grafo
 */
void busqueda_grados(int **grafo, int n_vertices){
    int grados[2] = {0,INF};  //[0] grado maximo, [1] grado minimo
    for(int i=0;i<n_vertices;i++){
        int grado = 0;
        for(; grafo[i][grado] != -1; grado++);
        if(grado > grados[0]) grados[0] = grado;
        if(grado < grados[1]) grados[1] = grado;
    }
    
    printf(AMARILLO "Grado maximo: %d\n" RESET_COLOR, grados[0]);
    printf(AMARILLO "Grado minimo: %d\n" RESET_COLOR, grados[1]);
}


int main(){
    int **grafo = NULL; // Lista de adyacencia indexado a 0
    int n_vertices;
    entrada_grafo(&grafo, &n_vertices); // Se obtiene la lista de adyacencia (hay que liberar memoria)

    // Se imprime la lista de adyacencia
    //impresion_grafo(grafo, n_vertices);

    // Se verifica que el grafo original se conexo
    //deteccion_conexidad_base(grafo, n_vertices);

    // Se eliminan conjuntos de vertices desde 1 hasta 4 y se imprimen las distintas combinaciones y si es o no conexo
    //rastreo_de_coneccidad_4_salida_completa(grafo,n_vertices);

    // Se calculan los grados maximos y minimos del grafo
    //busqueda_grados(grafo, n_vertices);

    // Se verifica la k-conexidad del grafo
    impresion_resultado_dfs_k_conexo(rastreo_de_k_coneccidad_hasta_4(grafo, n_vertices));

    liberacion_memoria_grafo(grafo, n_vertices); // Se libera la memoria de la lista de adyacencia
    return 0;
}