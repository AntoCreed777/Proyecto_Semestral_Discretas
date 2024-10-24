```
FUNCION main()
    grafo <- NULL  // Inicializar el grafo vacío
    n_vertices <- 0  // Inicializar el número de vértices

    grafo, n_vertices <- ingresar_nuevo_grafo()  // Obtener el grafo ingresado por el usuario

    MIENTRAS VERDADERO
        eleccion_opciones(grafo, n_vertices)

FIN FUNCION
```

```
FUNCION eleccion_opciones(grafo, n_vertices)
    IMPRIMIR "1. Verificar conexidad del grafo"
    IMPRIMIR "2. Verificar k-conexidad del grafo"
    IMPRIMIR "3. Verificar grados máximos y mínimos del grafo"
    IMPRIMIR "4. Ingresar nuevo grafo"
    IMPRIMIR "5. Salir"
    IMPRIMIR "Ingrese la opción deseada:"

    opcion <- LEER_ENTRADA()  // Leer la opción del usuario como cadena
    opcion <- CONVERTIR_A_ENTERO(opcion)  // Convertir la entrada a entero

    SI opcion ES 1 ENTONCES
        ignorados <- [-1]  // No se ignoran vértices (-1 indica final de lista)
        IMPRIMIR "NO SE IGNORAN VÉRTICES 'GRAFO ORIGINAL':"
        resultado <- verificar_conexidad(grafo, n_vertices, ignorados)
        IMPRIMIR resultado

    SI opcion ES 2 ENTONCES
        resultado <- verificar_k_conexidad_hasta_4(grafo, n_vertices)
        IMPRIMIR resultado

    SI opcion ES 3 ENTONCES
        busqueda_grados(grafo, n_vertices)  // Buscar grados máximos y mínimos

    SI opcion ES 4 ENTONCES
        liberar_memoria_grafo(grafo, n_vertices)  // Liberar la memoria del grafo anterior
        grafo, n_vertices <- ingresar_nuevo_grafo()  // Ingresar un nuevo grafo

    SI opcion ES 5 ENTONCES
        liberar_memoria_grafo(grafo, n_vertices)  // Liberar memoria antes de salir
        TERMINAR_PROGRAMA()

    SI opcion ES OTRA ENTONCES
        IMPRIMIR "Opción inválida"
FIN FUNCION
```


```
FUNCIÓN dfs_coneccidad(grafo, cantidad_nodos, ignorados)
    // Crear un arreglo booleano para marcar los nodos visitados
    visitados <- arreglo de booleanos de tamaño cantidad_nodos
    SI visitados ES NULL ENTONCES
        IMPRIMIR "Error al reservar memoria"
        RETORNAR 2  // Error

    // Inicializar todos los nodos como no visitados
    PARA i DESDE 0 HASTA cantidad_nodos - 1 HACER
        visitados[i] <- falso

    // Marcar los nodos ignorados como visitados
    PARA i DESDE 0 HASTA FIN DE ignorados HACER
        SI ignorados[i] == -1 ENTONCES
            TERMINAR
        visitados[ignorados[i]] <- verdadero

    // Inicializar la pila
    pila <- nueva pila vacía
    v <- 0

    // Encontrar un nodo inicial no ignorado
    MIENTRAS (v < cantidad_nodos) Y (visitados[v] ES verdadero) HACER
        v <- v + 1

    SI v == cantidad_nodos ENTONCES
        IMPRIMIR "No se encontró un nodo inicial"
        LIBERAR visitados
        RETORNAR 2  // Error

    // Insertar el nodo inicial en la pila
    TRATAR DE INSERTAR, SI NO SE PUEDE INSERTAR v EN LA PILA ENTONCES
        IMPRIMIR "Error al insertar en la pila"
        LIBERAR visitados
        RETORNAR 2  // Error

    // Realizar DFS iterativo
    MIENTRAS la pila NO ESTÉ VACÍA HACER
        u <- quitar de la pila
        visitados[u] <- verdadero
        PARA cada nodo adyacente a u en el grafo HACER
            SI el nodo adyacente NO ha sido visitado ENTONCES
                TRATAR DE INSERTAR, SI NO SE PUEDE INSERTAR el nodo adyacente EN LA PILA ENTONCES
                    IMPRIMIR "Error al insertar en la pila"
                    LIBERAR visitados
                    RETORNAR 2  // Error

    // Verificar si todos los nodos no ignorados fueron visitados
    PARA i DESDE 0 HASTA cantidad_nodos - 1 HACER
        SI visitados[i] ES falso ENTONCES
            LIBERAR visitados
            RETORNAR 0  // No es conexo

    LIBERAR visitados
    RETORNAR 1  // Es conexo

FIN FUNCIÓN
```

```
FUNCIÓN rastreo_de_k_coneccidad_hasta_4(grafo, n_vertices)
    // Verificar conexidad ignorando un vértice
    PARA cada vértice i DESDE 0 HASTA (n_vertices - 1) HACER
        ignorados <- [i, -1]  // Lista con el vértice a ignorar, finalizada en -1
        conexo <- dfs_conexidad(grafo, n_vertices, ignorados)
        SI conexo ES FALSO ENTONCES
            RETORNAR 1  // Es 1-conexo
        SI conexo ES ERROR ENTONCES
            RETORNAR -1  // Error en la verificación

    // Verificar conexidad ignorando dos vértices
    PARA cada vértice i DESDE 0 HASTA (n_vertices - 1) HACER
        PARA cada vértice j DESDE 0 HASTA (n_vertices - 1) HACER
            SI i NO ES IGUAL A j ENTONCES
                ignorados <- [i, j, -1]  // Ignorar dos vértices
                conexo <- dfs_conexidad(grafo, n_vertices, ignorados)
                SI conexo ES FALSO ENTONCES
                    RETORNAR 2  // Es 2-conexo
                SI conexo ES ERROR ENTONCES
                    RETORNAR -1  // Error en la verificación

    // Verificar conexidad ignorando tres vértices
    PARA cada vértice i DESDE 0 HASTA (n_vertices - 1) HACER
        PARA cada vértice j DESDE 0 HASTA (n_vertices - 1) HACER
            PARA cada vértice k DESDE 0 HASTA (n_vertices - 1) HACER
                SI (i NO ES IGUAL A j) Y (i NO ES IGUAL A k) Y (j NO ES IGUAL A k) ENTONCES
                    ignorados <- [i, j, k, -1]  // Ignorar tres vértices
                    conexo <- dfs_conexidad(grafo, n_vertices, ignorados)
                    SI conexo ES FALSO ENTONCES
                        RETORNAR 3  // Es 3-conexo
                    SI conexo ES ERROR ENTONCES
                        RETORNAR -1  // Error en la verificación

    // Verificar conexidad ignorando cuatro vértices
    PARA cada vértice i DESDE 0 HASTA (n_vertices - 1) HACER
        PARA cada vértice j DESDE 0 HASTA (n_vertices - 1) HACER
            PARA cada vértice k DESDE 0 HASTA (n_vertices - 1) HACER
                PARA cada vértice l DESDE 0 HASTA (n_vertices - 1) HACER
                    SI (i NO ES IGUAL A j) Y (i NO ES IGUAL A k) Y (i NO ES IGUAL A l) Y (j NO ES IGUAL A k) Y (j NO ES IGUAL A l) Y (k NO ES IGUAL A l) ENTONCES
                        ignorados <- [i, j, k, l, -1]  // Ignorar cuatro vértices
                        conexo <- dfs_conexidad(grafo, n_vertices, ignorados)
                        SI conexo ES FALSO ENTONCES
                            RETORNAR 4  // Es 4-conexo
                        SI conexo ES ERROR ENTONCES
                            RETORNAR -1  // Error en la verificación

    // Si pasa todas las pruebas, el grafo es k-conexo con k >= 5
    RETORNAR 5

FIN FUNCIÓN
```

```
FUNCIÓN busqueda_grados(grafo, n_vertices)
    grados <- [0, INFINITO]  // Inicializar grados[0] con el grado máximo (0), grados[1] con el grado mínimo (INFINITO)

    PARA i DESDE 0 HASTA (n_vertices - 1) HACER
        grado <- 0
        // Contar el número de vertices adyacentes (el grado del vértice i)
        MIENTRAS grafo[i][grado] != -1 HACER
            grado <- grado + 1

        // Actualizar el grado máximo
        SI grado > grados[0] ENTONCES
            grados[0] <- grado

        // Actualizar el grado mínimo
        SI grado < grados[1] ENTONCES
            grados[1] <- grado

    IMPRIMIR "Grado máximo: ", grados[0]
    IMPRIMIR "Grado mínimo: ", grados[1]

FIN FUNCIÓN
```
