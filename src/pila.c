#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "constantes.h"
#include "pila.h"


/**
 * @brief Inicializa una pila
 * 
 * @param pila Pila a inicializar
 */
void inicializarPila(struct Pila *pila) {
    pila->elementos = NULL;
    pila->tope = -1;
    pila->capacidad = 0;
}

/**
 * @brief Inserta un elemento en el tope de la pila
 * 
 * @param pila Pila en la que se insertará el elemento
 * @param elemento Elemento a insertar
 * 
 * @return true Si la inserción fue exitosa
 */
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

/**
 * @brief Elimina y devuelve el elemento en el tope de la pila
 * 
 * @param pila Pila de la que se eliminará el elemento
 * 
 * @return int Elemento eliminado
 */
int pop(struct Pila *pila) {
    if (pila->tope < 0) return -1;  // Si la pila está vacía
    return pila->elementos[pila->tope--];
}

/**
 * @brief Verifica si la pila está vacía
 * 
 * @param pila Pila a verificar
 * 
 * @return true Si la pila está vacía
 */
bool pilaVacia(struct Pila *pila) {
    return pila->tope < 0;
}

/**
 * @brief Libera la memoria asignada a la pila
 * 
 * @param pila Pila a liberar
 */
void liberarPila(struct Pila *pila) {
    free(pila->elementos);
    pila->elementos = NULL;
    pila->tope = -1;
    pila->capacidad = 0;
}
