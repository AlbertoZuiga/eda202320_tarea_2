# Tarea 2 EDA 2023-20

## Estructura del Proyecto

### Carpeta `include`
Esta carpeta contiene los archivos `.hpp` que declaran las funciones utilizadas. La carpeta se divide en dos subcarpetas, ambas obtenidas del repositorio del profesor y modificadas para adaptarse a los propósitos del proyecto.

#### Carpeta `lLists`
En esta subcarpeta, realicé los siguientes cambios:
- Eliminé el archivo `linkedLists.hpp` ya que no era necesario para esta tarea.
- Creé el archivo `pair.hpp` para declarar la clase con el mismo nombre.
- Modifiqué las clases contenidas en los archivos `node.hpp`, `queue.hpp` y `stack.hpp` para que los nodos acepten un elemento de la clase `Pair` en lugar de un entero, como estaba configurado originalmente en el repositorio del profesor.

#### Carpeta `maze/maze.hpp`
En este archivo, declaré los nuevos métodos necesarios para la ejecución de la tarea:

1. `void print(std::vector<llist::Pair> solution);`: Esta función ya estaba declarada, pero creé un método adicional para imprimir el vector de pares que contiene la solución, junto con la cantidad de nodos que se recorrieron para llegar a la solución (solo los necesarios).

2. `void printSolution(std::vector<llist::Pair> solution);`: Esta función recibe el mismo vector de solución mencionado anteriormente, pero muestra como salida el laberinto con las coordenadas del camino hacia la solución marcadas con una 'x'.

3. `std::vector<llist::Pair> solveStack(int f1, int c1, int f2, int c2);`: Esta función recibe las coordenadas iniciales y finales y devuelve un vector con los pares de la solución utilizando una pila.

4. `std::vector<llist::Pair> solveQueue(int r1, int c1, int r2, int c2);`: Esta función recibe las coordenadas iniciales y finales y devuelve un vector con los pares de la solución utilizando una cola.

### Carpeta `src`
Esta carpeta contiene los archivos `.cpp` con el código de las funciones declaradas en la carpeta `include`.

### Carpeta `test`
La carpeta `test` contiene el archivo `tarea_2.cpp`, que se utilizará para probar el código. En este archivo, encontrarás ejemplos de cómo funcionan las distintas funciones creadas.

### `CMakeLists.txt`
Este archivo se obtuvo del repositorio del profesor y se editó para que compile los archivos correspondientes.

## Explicación del Código

### Clase `llist::Pair`
La clase `llist::Pair` fue creada para contener las coordenadas de un punto. Tiene como atributos únicamente la fila y columna del punto y métodos para obtener estos atributos y para imprimirlos.

### Métodos de la Clase `maze::Maze`

#### `std::vector<llist::Pair> Maze::solveStack(int r1, int c1, int r2, int c2)`
Este método de la clase `maze::Maze` recibe las coordenadas del punto inicial y final y devuelve un vector de pares `Pair` con los puntos que forman la solución que une los dos puntos. 

El algoritmo funciona de la siguiente manera:
- Crea el vector de solución y lo devuelve vacío si el punto final o inicial corresponde a un muro.
- Crea una pila para revisar las soluciones, un vector para verificar si los puntos han sido visitados o no y un vector que contendrá todos los puntos visitados junto con el punto por el cual se llegó a ese punto. Esto se hace para tener un registro del camino.
- Agrega el punto inicial a la pila y lo marca como visitado.
- Entra en un ciclo que se repetirá hasta que la pila esté vacía, lo que ayuda a finalizar el programa en caso de que no haya solución.
- Dentro del ciclo, se almacenan los valores de fila y columna actuales (en la primera repetición, serán los iniciales) y se elimina el primer elemento de la pila.
- Se verifica si se ha llegado al punto final. Si es así, se registra el camino y se agrega al vector de solución para finalmente devolverlo.
- Si no se ha llegado al punto final, se verifican los puntos vecinos para ver si han sido visitados anteriormente, si son parte del laberinto o si son muros. Luego, se agregan aleatoriamente los puntos vecinos no visitados y se marcan como visitados.
- El ciclo continúa eliminando el primer elemento de la pila.

#### `std::vector<llist::Pair> Maze::solveQueue(int r1, int c1, int r2, int c2)`
Este método funciona de manera similar al anterior, con la diferencia de que en lugar de agregar los puntos a una pila, los agrega a una cola.

#### `void Maze::print(std::vector<llist::Pair> solution)`
Este método se utiliza para imprimir los puntos de la solución en orden, con el formato (x, y). Recorre el vector de solución e imprime el par correspondiente.

#### `void Maze::printSolution(std::vector<llist::Pair> solution)`
Este método muestra el laberinto con el camino de solución marcado con un carácter diferente. Para evitar modificar el grid original y afectar futuros usos del código, se crea un grid auxiliar para modificar los valores de los puntos correspondientes a la solución. A la hora de imprimir, se aplica una tercera condición para mostrar un carácter diferente para el camino de solución.

## Compilación y Ejecución
Para compilar y ejecutar el proyecto, sigue los siguientes pasos:

1. Crea una carpeta llamada 'build' en el directorio principal y navega a esa carpeta:
   ```
   mkdir build && cd build
   ```

2. Ejecuta el comando 'cmake' para generar el archivo Makefile:
   ```
   cmake ../.
   ```

3. Compila el proyecto con 'make':
   ```
   make
   ```

4. Ejecuta el programa:
   ```
   ./laberinto
   ```
