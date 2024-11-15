# Proyecto K-Conexidad MATEMATICAS DISCRETAS


<p align="center">
  <a href="https://skillicons.dev">
    <img src="https://skillicons.dev/icons?i=git,github,vscode,linux&perline=12" />
  </a>
</p>
<p align="center">
  <a href="https://skillicons.dev">
    <img src="https://skillicons.dev/icons?i=c&perline=12" />
  </a>
</p>


## Instrucciones de compilación

### Versión de compilador recomendada y sistemas testeados
El código esta compilado con gcc en linux. La distribucion utilizada en el testeo es Windows subsystem for linux (WSL) Ubuntu.

La versión de gcc recomendada para compilar el proyecto es *gcc (GCC) 11.4.0*.

### Comandos para ejecutar el código 
Para compilarlo y ejecutarlo simplemente ejecute ```make run``` después de clonar el repositorio en el directorio del mismo, en deonde se encuentra el archivo ```Makefile```.

Si make llegase a fallar se puede ejecutar el comando manualmente con:

```sh
gcc -I ./include -o main.exe ./src/dfs.c ./src/entrada.c ./src/main.c ./src/memoria.c ./src/pila.c
```


Después de compilarlo simplemente ejecutar ```./main.exe``` en el directorio del proyecto.