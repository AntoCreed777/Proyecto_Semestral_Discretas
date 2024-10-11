#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "constantes.h"
#include "dfs.h"
#include "pila.h"

#define ERROR 2

// Retorna 1 si el grafo es conexo, 0 en caso contrario ; 2 si hay un error
int dfs_coneccidad(int **grafo, int cantidad_nodos, int v, bool *visitados) {
    Pila pila;
    inicializarPila(&pila);
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
    for (int i = 0; i < cantidad_nodos; i++)
        if (!visitados[i]) return false;
    
    return true;
}