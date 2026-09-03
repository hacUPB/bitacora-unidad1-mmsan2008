# (Yo respondí las preguntas, pero le pedí a ChatGPT que me marcara las respuestas con un símbolo para que se puedan ubicar.)

# Actividad 3: Mapa de memoria de un programa escrito en C++

<img width="479" height="526" alt="image" src="https://github.com/user-attachments/assets/8eb7c997-cb93-43c0-8d93-432c6162a53a" />

---

# Actividad 4: Experimentos

🟢 los comentarios estan dentro de los codigos.

---

# Actividad 5: Copia de objetos y su ubicación en memoria

## Reflexión final para esta actividad

## 1. Explica qué ocurre al copiar un objeto en C++ y en C#. ¿Qué diferencias encuentras?

🟢 En c# al copiar un objeto directamente se copia el valor
En cambio, en C++ se copia mediante una referencia, guardando el valor en la dirección de memoria.

## 2. ¿Qué es `copia` en C++ y en C#? ¿Es una copia independiente de `original`?

🟢 En C# se copió mediante una copia por valor y es independiente del original
y en C++ se copia mediante una referencia y hace referencia al mismo objeto, entonces no es independiente.

---

# Actividad integradora de investigación

## A. Predicción (sin ejecutar el código):

## 1. ¿Cuál será la salida final en la consola de este programa?

🟢 en val_A suma por valor su salida será 30 ya que 20 + 10 30 pero val_A seguirá siendo 20 ya que nada mas recive una copia.
en val_b suma por referencia su salida será 30 y modifica la dirección de memoria ya que hace la operación dentro de una referencia del objeto original
en val_c suma por puntero su salida será 30 ya que va a la dirección de memoria de val_c y modifica directamente su contenido
y el contador pasa de 1 - 2 - 3 y incrementa  ya que la variable estática conserva su valor cuando sale de la función y la vuelve a llamar

## 2. Dibuja un mapa de memoria conceptual de este programa justo antes de que `main` finalice. Debes indicar en qué segmento de memoria (Stack, Heap, Datos Globales/Estáticos, Código) se encontraría cada una de las siguientes variables: `contador_global`, `contador_estatico`, `val_A`, `val_B`, `val_C` (dentro de main), el parámetro a de la función `sumaPorValor`, la función main misma.

<img width="400" height="703" alt="image" src="https://github.com/user-attachments/assets/4c8efc8b-d60c-49f1-934d-7577d6f0a540" />

---

# B. Verificación y análisis (usando el depurador)

## 3. Compara la salida real con tu predicción. Si hubo diferencias, explica por qué ocurrieron. Evidencia clave: capturas de pantalla antes y después de los puntos de interés (¿Cuáles son esos puntos? -> tu tarea analizarlo).

🟢 La salida real coincidió con la predicción realizada val_A permaneció en 20 porque fue pasado por valor, mientras que val_B y val_C cambiaron a 30 porque fueron modificados mediante referencia y puntero. Además, contador estático conservó su valor entre las llamadas y aumentó de 1 a 3.

(Este análisis lo puede hacer en clase pero en mi casa me sale este error al ejecutar el programa entonces no puedo sacar las capturas )

<img width="1908" height="1010" alt="image" src="https://github.com/user-attachments/assets/e83a0982-07c7-4583-9cab-c8383f7d3241" />

## 6. Describe qué demuestran estas capturas sobre la diferencia entre los diferentes tipos de paso por parámetros analizados.

🟢 Las capturas demuestran que pasar un parámetro por valor crea una copia por lo que los cambios no afectan a la variable original. por otro lado pasar por referencia o por puntero permite modificar directamente la variable original, Por eso val_a queda en 20, mientras que val_b y val_c terminan en 30.

## 7 Explica con tus propias palabras el comportamiento de contador_estatico. ¿Por qué “recuerda” su valor entre llamadas a la función ejecutarContador? ¿En qué se diferencia de una variable local normal?

🟢 La variable estática solo se inicializa una vez y esta mantiene su valor durante toda la ejecución del programa por eso en cada llamada aumenta 1-2-3

---

# Actividad 6: Hola Objeto: creación de un objeto en el stack

Este experimento es fundamental porque conecta el concepto fundamental de POO (objetos) con este curso.

Vas a crear una clase sencilla llamada Punto que represente un punto en el espacio con dos coordenadas (`x` e `y`). Luego, crearás un objeto de esta clase en el `stack` y utilizarás el depurador para inspeccionar su contenido y dirección de memoria.

### Pasos:

* Abre Visual Studio y crea un nuevo proyecto de consola en C++.
* Define la siguiente clase en un archivo `.cpp` (puedes incluir todo en `main.cpp`):

## 1. ¿Cuál es la diferencia entre un constructor y un destructor en C++?

🟢 El constructor se ejecuta cuando se crea un objeto y sirve para inicializarlo en cambio El destructor se ejecuta cuando el objeto deja de existir y sirve para realizar la limpieza necesaria en el heap

## 3. ¿Cuál es la diferencia entre un objeto y una clase en C++?

🟢 una clase es la estructura o plantilla que define las características y funciones de algo y un objeto es una instancia creada a partir de esa clase, En este caso Punto es la clase y p es el objeto.

## 5. ¿Qué diferencia notas entre el objeto Punto en C++ y C#?

🟢 En C++ al escribir Punto p(10, 20); p es directamente un objeto creado en el stack.

En C# cuando se utiliza una clase con new, la variable normalmente es una referencia que apunta al objeto creado en el heap.

## 7. ¿Qué es `p` en C++ y qué es `p` en C#? (en uno de ellos `p` es un objeto y en el otro es una referencia a un objeto).

🟢 en C++ p es directamente un objeto de tipo punto
en C# p es normalmente una referencia al objeto punto

## 9. ¿En qué parte de memoria se almacena `p` en C++ y en C#?

🟢 en c++ p es una variable local por lo que se guarda en el stack
en c# la referencia p esta en el stack pero al objeto que apunta esta en el heap

## 11. ¿Qué observaste con el depurador acerca de `p`? Según lo que observaste ¿Qué es un objeto en C++?

---

# Actividad 7: Objetos en el heap: creación y observación

Modifica el programa anterior para crear un objeto de la clase Punto de manera dinámica (en el heap) utilizando new. Luego, inspecciona con el depurador la dirección del objeto y compárala con la del objeto en el stack.

## 1. Explicación de la diferencia entre objetos creados en el stack y en el heap.

🟢 Los objetos creados en el stack se eliminan cuando salen de este por otro lado heap guarda los datos con new y solo se puede borrar con  un destructor.

## 2. `pStack` ¿Es un objeto o una referencia a un objeto?

🟢 p stack es un objeto de la clase punto se crea directamente en el stack

## 3. `pHeap` ¿Es un objeto o una referencia a un objeto? Si es una referencia, ¿A qué objeto hace referencia?

🟢 pheap es un puntero que contiene la dirección de un objeto punto creado en el heap

## 4. Observa en Memory1 (Debug->Windows->Memory->Memory1) el contenido de la dirección de memoria de `pHeap`, recuerda escribir en la entrada de texto de Memory1 la dirección de memoria de `&pHeap` y presionar Enter. Compara el contenido de memoria con el contenido de `pHeap` en la pestaña de Locals (Debug->Windows->Locals). ¿Qué observas? ¿Qué significa esto?

🟢 se observa la memoria donde está almacenada la variable pHeap. El contenido de esa posición corresponde a una dirección de memoria que es la dirección del objeto Punto(50, 60) creado en el Heap.

---

# Actividad 8: Funciones y objetos en C++

Analiza, ejecuta, depura y experimenta con el siguiente código en C++.

## Reflexiona sobre lo siguiente

## 1. ¿Qué ocurre después de llamar a la función `cambiarNombre`? ¿Por qué aparece el mensaje `Destructor: Punto cambiado(70, 80) destruido.`?

🟢 al cambiar nombre se crea una copia de original llamada p y dentro de la funcion se cambia el nombre de esta funcion a cambiado y cuando se termina deja de existir la funcion  por eso se destruye con el destructor

## 3. ¿Por qué `original` sigue existiendo luego de llamar `cambiarNombre`?

🟢 por que original y p son dos objetos diferentes ya que p es la copia de original

## 4. ¿En qué parte del mapa de memoria se encuentra `original` y en qué parte se encuentra `p`? ¿Son el mismo objeto? (recuerda usar siempre el depurador para responder estas preguntas).

🟢 Los dos se encuentran en el stack y p es una copia de original entonces no son el mismo objeto

---

## Modifica la función `cambiarNombre`

```cpp
void cambiarNombre(Punto& p, string nuevoNombre) {  p.name = nuevoNombre;}
```

## 1. ¿Qué ocurre ahora? ¿Por qué?

🟢 ahora p es una referencia de el objeto original por lo que al cambiar el nombre tambien se cambia original

---

## Modifica ahora a `cambiarNombre` y a `main` de la siguiente manera:

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

## 1. ¿Qué ocurre ahora? ¿Por qué?

🟢 ahora se pasa la direcion de memoria de original mediante &original y el puntero p apunta al objeto original y modifica directamente su nombre

## 3. En este caso ¿Cuál es la diferencia entre pasar un objeto por valor, por referencia y por puntero?

🟢 Por valor es una copia, por referencia es una referencia del objeto original, y por puntero es la direccion del original.


# Actividad 9: Objetos con miembros estáticos y variables de instancia

##¿Qué puedes concluir de los miembros estáticos y de instancia de una clase en C++? ¿Cómo se gestionan en memoria? ¿Qué ventajas y desventajas tienen? ¿Cuándo es útil utilizarlos?

Los miembros de instancia pertenecen a cada objeto por lo que cada objeto tiene su propio valor y Los miembros estáticos pertenecen a la clase y son compartidos por todos los objetos como total.

En memoria los valores de cada objeto se almacenan junto con el objeto, mientras que el miembro estático se almacena una sola vez.

Una ventaja de los miembros estáticos es que permiten compartir información entre todos los objetos y Una desventaja es que cualquier objeto puede modificar ese valor compartido ademas Son útiles cuando necesitamos llevar un dato común para todos los objetos como el número total de objetos creados

## En el programa, en qué segmento de memoria se están almacenando c1, c2, c3 y Contador::total?
c1 y c2 son objetos creados directamente dentro de main, por lo que se encuentran en el Stack.
c3 es un puntero, por lo que la variable c3 se encuentra en el Stack, pero el objeto que crea mediante new se encuentra en el Heap.
Contador::total es un miembro estático por lo que se encuentra en la zona de variables Globales yEstáticos y es compartido por todos los objetos.

#Actividad 10: Explorando el ciclo de vida de un objeto

##Explica el ciclo de vida de un objeto en el stack versus uno en el heap.

El objeto en el stack se crea automáticamente al entrar  y se destruye cuando sale y En cambio el objeto en el heap se crea con new y permanece hasta que se libera manualmente con un destructor.




