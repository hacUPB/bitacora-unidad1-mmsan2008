Actividad 3: Mapa de memoria de un programa escrito en C++
<img width="456" height="753" alt="image" src="https://github.com/user-attachments/assets/a4194460-caae-4b6f-88ab-91dba13138dc" />

Actividad 4: Experimentos
los Comentarios estan dentro de los codigos.

Actividad 5: Copia de objetos y su ubicación en memoria

**Reflexión final para esta actividad**

1. Explica qué ocurre al copiar un objeto en C++ y en C#. ¿Qué diferencias encuentras?
En c# al copiar un objeto directamente se copia el valor 
En cambio, en C++ se copia mediante una referencia, guardando el valor en la dirección de memoria. 


2. ¿Qué es `copia` en C++ y en C#? ¿Es una copia independiente de `original`?
3. 
En C# se copió mediante una copia por valor y es independiente del original
y en C++ se copia mediante una referencia y hace referencia al mismo objeto, entonces no es independiente.


Actividad integradora de investigación

**A. Predicción (sin ejecutar el código):**

1. ¿Cuál será la salida final en la consola de este programa?
2. Escribe la salida completa que esperas.
en val_A suma por valor su salida será 30 ya que 20 + 10 30 pero val_A seguirá siendo 20 ya que nada mas recive una copia.
en val_b suma por referencia su salida será 30 y modifica la dirección de memoria ya que hace la operación dentro de una referencia del objeto original
en val_c suma por puntero su salida será 30 ya que va a la dirección de memoria de val_c y modifica directamente su contenido
y el contador pasa de 1 - 2 - 3 y incrementa  ya que la variable estática conserva su valor cuando sale de la función y la vuelve a llamar

4. Dibuja un mapa de memoria conceptual de este programa justo antes de que `main` finalice. Debes indicar en qué segmento de memoria (Stack, Heap, Datos Globales/Estáticos, Código) se encontraría cada una de las siguientes variables: `contador_global`, `contador_estatico`, `val_A`, `val_B`, `val_C` (dentro de main), el parámetro a de la función `sumaPorValor`, la función main misma.

 <img width="1898" height="1004" alt="image" src="https://github.com/user-attachments/assets/5cc513cf-9c28-4c90-a47e-761b83fb6375" />

**B. Verificación y análisis (usando el depurador):**
Ejecuta el programa paso a paso (F10) con un `breakpoint` al inicio de `main`.
5. Compara la salida real con tu predicción. Si hubo diferencias, explica por qué ocurrieron. Evidencia clave: capturas de pantalla antes y después de los puntos de interés (¿Cuáles son esos puntos? -> tu tarea analizarlo).
La salida real coincidió con la predicción realizada val_A permaneció en 20 porque fue pasado por valor, mientras que val_B y val_C cambiaron a 30 porque fueron modificados mediante referencia y puntero. Además, contadorestatico conservó su valor entre las llamadas y aumentó de 1 a 3.
Este análisis lo puede hacer en clase pero en mi casa me sale este error al ejecutar el programa entonces no puedo sacar las capturas 

<img width="1908" height="1010" alt="image" src="https://github.com/user-attachments/assets/e83a0982-07c7-4583-9cab-c8383f7d3241" />


6. Describe qué demuestran estas capturas sobre la diferencia entre los diferentes tipos de paso por parámetros analizados.
Las capturas demuestran que pasar un parámetro por valor crea una copia por lo que los cambios no afectan a la variable original. por otro lado pasar por referencia o por puntero permite modificar directamente la variable original, Por eso val_a queda en 20, mientras que val_b y val_c terminan en 30.

7 Explica con tus propias palabras el comportamiento de contador_estatico. ¿Por qué “recuerda” su valor entre llamadas a la función ejecutarContador? ¿En qué se diferencia de una variable local normal?
la variable estática solo se inicializa una vez y esta mantiene su valor durante toda la ejecución del programa por eso en cada llamada aumenta 1-2-3


# **Actividad 6: Hola Objeto: creación de un objeto en el stack**

Este experimento es fundamental porque conecta el concepto fundamental de POO (objetos) con este curso.

Vas a crear una clase sencilla llamada Punto que represente un punto en el espacio con dos coordenadas (`x` e `y`). Luego, crearás un objeto de esta clase en el `stack` y utilizarás el depurador para inspeccionar su contenido y dirección de memoria.

### Pasos:

- Abre Visual Studio y crea un nuevo proyecto de consola en C++.
- Define la siguiente clase en un archivo `.cpp` (puedes incluir todo en `main.cpp`):

1. ¿Cuál es la diferencia entre un constructor y un destructor en C++?
El constructor se ejecuta cuando se crea un objeto y sirve para inicializarlo en cambio El destructor se ejecuta cuando el objeto deja de existir y sirve para realizar la limpieza necesaria en el heap
2. ¿Cuál es la diferencia entre un objeto y una clase en C++?
una clase es la estructura o plantilla que define las características y funciones de algo y un objeto es una instancia creada a partir de esa clase, En este caso Punto es la clase y p es el objeto.
3. ¿Qué diferencia notas entre el objeto Punto en C++ y C#?
En C++ al escribir Punto p(10, 20); p es directamente un objeto creado en el stack.
En C# cuando se utiliza una clase con new, la variable normalmente es una referencia que apunta al objeto creado en el heap.
4. ¿Qué es `p` en C++ y qué es `p` en C#? (en uno de ellos `p` es un objeto y en el otro es una referencia a un objeto).
en C++ p es directamente un objeto de tipo punto
en C# p es normalmente una referencia al objeto punto
5. ¿En qué parte de memoria se almacena `p` en C++ y en C#?
en c++ p es una variable local por lo que se guarda en el stack
en c# la referencia p esta en el stack pero al objeto que apunta esta en el heap
6. ¿Qué observaste con el depurador acerca de `p`? Según lo que observaste ¿Qué es un objeto en C++?

# **Actividad 7: Objetos en el heap: creación y observación**

Modifica el programa anterior para crear un objeto de la clase Punto de manera dinámica (en el heap) utilizando new. Luego, inspecciona con el depurador la dirección del objeto y compárala con la del objeto en el stack.

1. Explicación de la diferencia entre objetos creados en el stack y en el heap.
2. `pStack` ¿Es un objeto o una referencia a un objeto?
3. `pHeap` ¿Es un objeto o una referencia a un objeto? Si es una referencia, ¿A qué objeto hace referencia?
4. Observa en Memory1 (Debug->Windows->Memory->Memory1) el contenido de la dirección de memoria de `pHeap`, recuerda escribir en la entrada de texto de Memory1 la dirección de memoria de `&pHeap` y presionar Enter. Compara el contenido de memoria con el contenido de `pHeap` en la pestaña de Locals (Debug->Windows->Locals). ¿Qué observas? ¿Qué significa esto?


# **Actividad 8: Funciones y objetos en C++**

Analiza, ejecuta, depura y experimenta con el siguiente código en C++.

**Reflexiona sobre lo siguiente**:

1. ¿Qué ocurre después de llamar a la función `cambiarNombre`? ¿Por qué aparece el mensaje `Destructor: Punto cambiado(70, 80) destruido.`?
2. ¿Por qué `original` sigue existiendo luego de llamar `cambiarNombre`?
3. ¿En qué parte del mapa de memoria se encuentra `original` y en qué parte se encuentra `p`? ¿Son el mismo objeto? (recuerda usar siempre el depurador para responder estas preguntas).

Modifica la función `cambiarNombre`:

`void cambiarNombre(Punto& p, string nuevoNombre) {  p.name = nuevoNombre;}`

1. ¿Qué ocurre ahora? ¿Por qué?
2. 
Modifica ahora a `cambiarNombre` y a `main` de la siguiente manera:

```cpp
void cambiarNombre(Punto* p, string nuevoNombre) {
		p->name = nuevoNombre;
		}
int main() {    // Objeto original
		Punto original("original",70, 80);
		original.imprimir();
    cambiarNombre(&original, "cambiado");
    original.imprimir();
    return 0;
    }
```

1. ¿Qué ocurre ahora? ¿Por qué?
2. En este caso ¿Cuál es la diferencia entre pasar un objeto por valor, por referencia y por puntero?
				
