# Lista de convenciones a utilizar

- En general si no especificamos directamente utilizamos snake_case (esto incluye nombre de archivos y variables).
- Prefieran nombres largos en vez de cortos que no explican bien el codigo (ejemplo evitar abreviaturas o variables poco descriptivas). 
- Docstrings
    - Ejemplo:
    ``` 
    /**
    * @brief Breve descripción de lo que hace la función.
    * 
    * Descripción más detallada de la función si es necesario.
    * Puede incluir información adicional como algoritmos utilizados,
    * suposiciones, limitaciones, etc.
    * 
    * @param[in]  param1  Descripción del primer parámetro (entrada).
    * @param[in]  param2  Descripción del segundo parámetro (entrada).
    * @param[out] result  Descripción del parámetro de salida si corresponde.
    * 
    * @return Descripción del valor de retorno de la función.
    * 
    * @note Información adicional, como aspectos a tener en cuenta o 
    * recomendaciones sobre cómo usar la función.
    * 
    * @warning Advertencias importantes sobre posibles efectos no deseados.
    */
int suma(int param1, int param2) {
    return param1 + param2;
}

    
- Utilizamos la convencion de los commits (feat, fix,...)
    - Para más detalles ver: https://dev.to/achamorro_dev/conventional-commits-que-es-y-por-que-deberias-empezar-a-utilizarlo-23an 

- La mayoria de igualdades se separan por espacios.  ``` a = 1  ``` en vez de ```a=1```.