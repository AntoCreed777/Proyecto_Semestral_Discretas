#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "constantes.h"
#include "entrada.h"
#include "memoria.h"
#include "dfs.h"

#define ERROR 2
#define ERROR_CONEXIDAD -1
#define ERROR_GRAFO_UNITARIO -2
#define INF 1e9

/**
 * @brief Imprime la lista de adyacencia del grafo
 * 
 * @param grafo Lista de adyacencia del grafo
 * @param n_vertices Numero de vertices del grafo
 */
void impresion_grafo(int **grafo, int n_vertices){
    for(int i = 0; i < n_vertices; i++){
        printf(BLANCO "Vertice " VERDE "%d" BLANCO " : " RESET_COLOR, i + 1);
        for(int j = 0; grafo[i][j] != -1; j++){
            printf(AMARILLO "%d " RESET_COLOR,grafo[i][j] + 1);
        }
        printf("\n");
    }
    printf("\n\n");
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
    if(k_conexo == ERROR_CONEXIDAD) printf(ROJO "Error al verificar la k-conexidad del grafo\n" RESET_COLOR);
    else if(k_conexo == ERROR_GRAFO_UNITARIO) printf(AMARILLO "No existe 'k' tal que el grafo sea k-conexo\n" RESET_COLOR);
    else if(k_conexo == 5) printf(AMARILLO "El grafo es k-conexo con k >= 5\n" RESET_COLOR);
    else if (k_conexo == 0) printf(VERDE "El grafo es disconexo\n" RESET_COLOR);
    else printf(VERDE "El grafo es %d-conexo\n" RESET_COLOR, k_conexo);
    printf("\n\n");
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

    printf("\n\n");
}

/**
 * @brief Verifica la k-conexidad del grafo
 * 
 * @param grafo Lista de adyacencia del grafo
 * @param n_vertices Numero de vertices del grafo
 * 
 * @return int - Devuelve:
 *         0 si el grafo es 0-conexo,
 *         1 si el grafo es 1-conexo,
 *         2 si el grafo es 2-conexo,
 *         3 si el grafo es 3-conexo,
 *         4 si el grafo es 4-conexo,
 *         5 si el grafo es k-conexo (k >= 5),
 *        -1 si ocurre un error.
 */
int rastreo_de_k_coneccidad_hasta_4(int **grafo, int n_vertices){
    // Se verifica la conexidad del grafo sin eliminar vertices
    if (n_vertices == 1) return ERROR_GRAFO_UNITARIO;

    int ignorados[] = {-1}; // Se indica el fin de la lista con -1
    int conexo = dfs_coneccidad(grafo, n_vertices, ignorados);
    if(conexo == false) return 0;
    else if(conexo == ERROR) return ERROR_CONEXIDAD;

    // Se verifica la conexidad del grafo ignorando un vertice
    if (n_vertices == 2) return 1;

    for (int i = 0; i < n_vertices; i++){
        int ignorados[] = {i, -1}; // Se indica el fin de la lista con -1
        int conexo = dfs_coneccidad(grafo, n_vertices, ignorados);
        if(conexo == false) return 1;
        else if(conexo == ERROR) return ERROR_CONEXIDAD;
    }

    // Se verifica la conexidad del grafo ignorando dos vertices
    if (n_vertices == 3) return 2;
    for (int i = 0; i < n_vertices; i++) {
        for (int j = 0; j < n_vertices; j++) {
            if (i != j) {
                int ignorados[] = {i, j, -1}; // Se indica el fin de la lista con -1
                int conexo = dfs_coneccidad(grafo, n_vertices, ignorados);
                if(conexo == false) return 2;
                else if(conexo == ERROR) return ERROR_CONEXIDAD;
            }
        }
    }

    // Se verifica la conexidad del grafo ignorando tres vertices
    if (n_vertices == 4) return 3;

    for (int i = 0; i < n_vertices; i++) {
        for (int j = 0; j < n_vertices; j++) {
            for (int k = 0; k < n_vertices; k++) {
                if (i != j && i != k && j != k) {
                    int ignorados[] = {i, j, k, -1}; // Se indica el fin de la lista con -1
                    int conexo = dfs_coneccidad(grafo, n_vertices, ignorados);
                    if(conexo == false) return 3;
                    else if(conexo == ERROR) return ERROR_CONEXIDAD;
                }
            }
        }
    }

    // Se verifica la conexidad del grafo ignorando cuatro vertices
    if (n_vertices == 5) return 4;

    for (int i = 0; i < n_vertices; i++) {
        for (int j = 0; j < n_vertices; j++) {
            for (int k = 0; k < n_vertices; k++) {
                for (int l = 0; l < n_vertices; l++) {
                    if (i != j && i != k && i != l && j != k && j != l && k != l) {
                        int ignorados[] = {i, j, k, l, -1}; // Se indica el fin de la lista con -1
                        int conexo = dfs_coneccidad(grafo, n_vertices, ignorados);
                        if(conexo == false) return 4;
                        else if(conexo == ERROR) return ERROR_CONEXIDAD;
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
    
    printf(VERDE "Grado maximo: " BLANCO "%d\n" RESET_COLOR, grados[0]);
    printf(VERDE "Grado minimo: " BLANCO "%d\n" RESET_COLOR, grados[1]);

    printf("\n\n");
}


/**
 * @brief Menu de opciones para el usuario
 * 
 * @param grafo Lista de adyacencia del grafo
 * @param n_vertices Numero de vertices del grafo
 */
void eleccion_opciones(int ***grafo, int *n_vertices) {
    printf(MAGENTA "1. Verificar conexidad del grafo\n" RESET_COLOR);
    printf(MAGENTA "2. Verificar k-conexidad del grafo\n" RESET_COLOR);
    printf(MAGENTA "3. Verificar grados maximos y minimos del grafo\n" RESET_COLOR);
    printf(MAGENTA "4. Mostrar grafo\n" RESET_COLOR);
    printf(MAGENTA "5. Ingresar nuevo grafo\n" RESET_COLOR);
    printf(MAGENTA "6. Salir\n" RESET_COLOR);
    printf(AMARILLO "Ingrese la opcion deseada: " RESET_COLOR);

    char opcion_str[10];
    scanf("%9s", opcion_str);
    int opcion = atoi(opcion_str);

    printf("\n\n");

    switch(opcion) {
        case 1:
            // Se verifica la conexidad del grafo sin eliminar vertices
            printf(BLANCO "NO SE IGNORAN VERTICES " AMARILLO "\"GRAFO ORIGINAL\"" BLANCO " :\t" RESET_COLOR);
            int ignorados[] = {-1}; // Se indica el fin de la lista con -1
            impresion_resultado_dfs(dfs_coneccidad(*grafo, *n_vertices, ignorados));
            printf("\n\n");
            break;
        case 2:
            impresion_resultado_dfs_k_conexo(rastreo_de_k_coneccidad_hasta_4(*grafo, *n_vertices));
            break;
        case 3:
            busqueda_grados(*grafo, *n_vertices);
            break;
        case 4:
            impresion_grafo(*grafo, *n_vertices); // Se imprime la lista de adyacencia
            break;
        case 5:
            liberacion_memoria_grafo(grafo, *n_vertices); // Se libera la memoria de la lista de adyacencia
            entrada_grafo(grafo, n_vertices); // Se obtiene la lista de adyacencia (hay que liberar memoria)
            break;
        case 6:
            liberacion_memoria_grafo(grafo, *n_vertices); // Se libera la memoria de la lista de adyacencia
            exit(EXIT_SUCCESS);
        default:
            printf(ROJO "Opcion invalida\n" RESET_COLOR);
            break;
    }
}


int main(){
    int **grafo = NULL; // Lista de adyacencia indexado a 0
    int n_vertices;
    entrada_grafo(&grafo, &n_vertices); // Se obtiene la lista de adyacencia (hay que liberar memoria)

    while(true) 
        eleccion_opciones(&grafo, &n_vertices);

    return 0;
}