#pragma once

struct Pila {
    int *elementos;
    int tope;
    int capacidad;
};


typedef struct Pila Pila;

void inicializarPila(struct Pila *pila);

bool push(struct Pila *pila, int elemento);

int pop(struct Pila *pila);

bool pilaVacia(struct Pila *pila);

void liberarPila(struct Pila *pila);