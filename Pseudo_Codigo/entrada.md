```
FUNCIÓN recibir_archivo()
    DEFINIR ruta COMO cadena de longitud tamaño_ruta
    IMPRIMIR "Ingrese la ruta del archivo (\"exit\" para salir del programa): "
    LEER ruta

    HACER
        SI ruta ES IGUAL A "exit" ENTONCES
            TERMINAR el programa exitosamente

        ABRIR archivo EN modo lectura CON nombre ruta
        SI archivo ES NULO ENTONCES
            IMPRIMIR "Error al abrir el archivo"
            IMPRIMIR "Ingrese la ruta del archivo (\"exit\" para salir del programa): "
            LEER ruta
        SINO
            RETORNAR archivo
    MIENTRAS verdadero
FIN FUNCIÓN
```

```
FUNCIÓN entrada_grafo(PASAR POR REFERENCIA grafo, PASAR POR REFERENCIA n_vertices)
    archivo <- recibir_archivo()  // Llamar a la función para obtener el archivo

    LEER n_vertices DESDE archivo
    IMPRIMIR "Numero de vertices: ", n_vertices

    // Asignar memoria para la lista de adyacencia
    ASIGNAR grafo COMO una matriz de tamaño n_vertices x (n_vertices + 1)

    DEFINIR buffer COMO cadena de tamaño BUFFER_SIZE
    i <- -1  // Comenzar en -1 para omitir la primera fila

    MIENTRAS NO haya terminado el archivo HACER
        LEER línea del archivo en buffer
        numero <- primer token de buffer usando delimitadores ",: "
        j <- 0

        MIENTRAS numero NO SEA nulo Y i NO SEA -1 HACER
            SI j > 0 ENTONCES
                // Guardar los valores de adyacencia, ajustando para que empiecen en 0
                grafo[i][j - 1] <- convertir numero a entero - 1

            numero <- siguiente token
            j <- j + 1

        SI i != -1 ENTONCES
            grafo[i][j - 1] <- -1  // Marcar el final de la fila

        i <- i + 1  // Avanzar al siguiente vértice

    CERRAR archivo
FIN FUNCIÓN
```