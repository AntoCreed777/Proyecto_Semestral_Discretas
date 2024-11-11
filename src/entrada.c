#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "constantes.h"
#include "entrada.h"

#define tamaño_ruta 256
#define BUFFER_SIZE 1024

/**
 * @brief Imprime los caracteres de una cadena y sus valores ASCII
 * 
 * @param str Cadena a imprimir
 */
void imprimir_caracteres(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        printf("Caracter %d: '%c' (ASCII: %d)\n", i, str[i], (unsigned char)str[i]);
    }
    printf("\n");
}

/**
 * @brief Elimina los caracteres no imprimibles y los espacios de una cadena
 * 
 * @param str Cadena a modificar
 */
void eliminar_caracteres_no_imprimibles(char* str) {
    char* inicial = str;
    char* final = str;

    while (*inicial) {
        if (isprint((unsigned char)*inicial) && !isspace((unsigned char)*inicial)) {
            *final++ = *inicial;
        }
        inicial++;
    }
    *final = '\0';
}

/**
 * @brief Recibe la ruta de un archivo y lo abre
 * 
 * @return FILE* Archivo abierto
 * @note Sale del programa si el usuario ingresa "exit"
 */
FILE *recibir_archivo() {
    char ruta[tamaño_ruta];
    printf(AMARILLO "Ingrese la ruta del archivo (\"exit\" para salir del programa): " RESET_COLOR);
    scanf("%s", ruta);

    do{
        if (strcmp(ruta, "exit") == 0) exit(EXIT_SUCCESS);

        FILE *file = fopen(ruta, "r");
        if (file == NULL) {
            perror(ROJO "Error al abrir el archivo" RESET_COLOR);
            printf(AMARILLO "\nIngrese la ruta del archivo (\"exit\" para salir del programa): " RESET_COLOR);
            scanf("%s", ruta);
        }
        else return file;
    } while (1);
}


/**
 * @brief Obtiene la lista de adyacencia de un grafo
 * 
 * @param grafo Lista de adyacencia del grafo (Se modifica por referencia)
 * @param n_vertices Numero de vertices del grafo (Se modifica por referencia)
 */
void entrada_grafo(int ***grafo, int *n_vertices) {
    FILE *file = recibir_archivo();

    fscanf(file, "%d", n_vertices);
    printf(CIAN "\nNumero de vertices: %d\n\n" RESET_COLOR, *n_vertices);

    // Asignar memoria para la matriz de adyacencia
    *grafo = (int**)malloc(sizeof(int*) * (*n_vertices));
    for (int i = 0; i < *n_vertices; i++) {
        (*grafo)[i] = (int*)malloc(sizeof(int) * 2);  // Asignar memoria inicial para 2 enteros
        (*grafo)[i][0] = -1;  // Marcar el final de la fila
    }
    int *tamano_filas = (int*)malloc(sizeof(int) * (*n_vertices));
    for (int i = 0; i < *n_vertices; i++) tamano_filas[i] = 2;

    char buffer[BUFFER_SIZE];
    int vertice = -1;   // Vertice actual // -1 indica que no se ha leido un vertice
    
    fgets(buffer, sizeof(buffer), file);  // Ignorar la primera linea
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char *numero = NULL;
        int indice_entrada = 0;

        do{
            numero = strtok(numero == NULL ? buffer : NULL, ",: ");
            if (numero == NULL) break;

            // Eliminar caracteres no imprimibles del token
            eliminar_caracteres_no_imprimibles(numero);

            if (indice_entrada == 0) vertice = atoi(numero) - 1;  // Se resta 1 para que los vertices comiencen en 0
            else {
                // Redimensionar la fila si es necesario
                if (indice_entrada >= tamano_filas[vertice]) {
                    tamano_filas[vertice] *= 2;
                    (*grafo)[vertice] = (int*)realloc((*grafo)[vertice], sizeof(int) * tamano_filas[vertice]);
                    if ((*grafo)[vertice] == NULL) {
                        perror(ROJO "Error al redimensionar la fila" RESET_COLOR);
                        exit(EXIT_FAILURE);
                    }
                }
                
                (*grafo)[vertice][indice_entrada - 1] = atoi(numero) - 1;  // Se resta 1 para que los vertices comiencen en 0
                (*grafo)[vertice][indice_entrada] = -1;  // Marcar el final de la fila
            }

            indice_entrada++;
        } while (1);

        vertice = -1;   // Reiniciar el vertice
    }

    fclose(file);
    free(tamano_filas);
}