#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "constantes.h"
#include "pila.h"


// Inicializa una pila vacía
void inicializarPila(struct Pila *pila) {
    pila->elementos = NULL;
    pila->tope = -1;
    pila->capacidad = 0;
}

// Inserta un elemento en el tope de la pila
bool push(struct Pila *pila, int elemento) {
    if (pila->tope >= pila->capacidad - 1) {    // Si la pila está llena
        pila->elementos = (int *)realloc(pila->elementos, sizeof(int) * (pila->capacidad + 1));
        if (pila->elementos == NULL) {
            printf(ROJO "Error al intentar aumentar la capacidad de la pila\n" RESET_COLOR);
            return false;   // Error al intentar aumentar la capacidad de la pila
        }
        pila->capacidad++;
    }
    pila->elementos[++pila->tope] = elemento;
    return true;    // Inserción exitosa
}

// Elimina y devuelve el elemento en el tope de la pila
int pop(struct Pila *pila) {
    if (pila->tope < 0) return -1;  // Si la pila está vacía
    return pila->elementos[pila->tope--];
}

// Devuelve 1 si la pila está vacía, 0 en caso contrario
bool pilaVacia(struct Pila *pila) {
    return pila->tope < 0;
}

// Libera la memoria asignada a la pila
void liberarPila(struct Pila *pila) {
    free(pila->elementos);
    pila->elementos = NULL;
    pila->tope = -1;
    pila->capacidad = 0;
}
