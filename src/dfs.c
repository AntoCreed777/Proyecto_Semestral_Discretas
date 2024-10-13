#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "constantes.h"
#include "dfs.h"
#include "pila.h"

#define ERROR 2

// Retorna 1 si el grafo es conexo, 0 en caso contrario ; 2 si hay un error
int dfs_coneccidad(int **grafo, int cantidad_nodos, int *ignorados) {
    // Se crea un arreglo de booleanos para marcar los vertices visitados
    bool *visitados = (bool*)malloc(sizeof(bool) * cantidad_nodos);
    if (visitados == NULL) {
        perror(ROJO "Error al reservar memoria para el arreglo de visitados" RESET_COLOR);
        return ERROR;
    }
    
    for (int i = 0; i < cantidad_nodos; i++) visitados[i] = false;
    for (int i = 0; ignorados[i] != -1; i++) visitados[ignorados[i]] = true;    // Se marcan los vertices ignorados

    Pila pila;
    inicializarPila(&pila);

    // Se busca un vertice inicial que no haya sido ignorado
    int v = 0;
    while (visitados[v] && v < cantidad_nodos) v++;
    if (v == cantidad_nodos) {
        printf(ROJO "No se encontro un vertice inicial" RESET_COLOR);
        return ERROR;
    }

    if (!push(&pila, v)) {
        perror(ROJO "Error al insertar el elemento en la pila" RESET_COLOR);
        return ERROR;
    }

    while (!pilaVacia(&pila)) {
        int u = pop(&pila);
        visitados[u] = true;
        for (int i = 0; grafo[u][i] != -1; i++) {
            if (!visitados[grafo[u][i]]) {
                if (!push(&pila, grafo[u][i])) {
                    perror(ROJO "Error al insertar el elemento en la pila" RESET_COLOR);
                    return ERROR;
                }
            }
        }
    }

    liberarPila(&pila);

    // Verificar si todos los nodos fueron visitados
    for (int i = 0; i < cantidad_nodos; i++) {
        if (!visitados[i]) {
            free(visitados);
            return false;
        }
    }

    free(visitados);
    return true;
}