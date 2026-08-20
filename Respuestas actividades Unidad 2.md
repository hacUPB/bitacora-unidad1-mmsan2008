Actividad 5: Copia de objetos y su ubicación en memoria

**Reflexión final para esta actividad**

1. Explica qué ocurre al copiar un objeto en C++ y en C#. ¿Qué diferencias encuentras?


2. ¿Qué es `copia` en C++ y en C#? ¿Es una copia independiente de `original`?

Actividad integradora de investigación

**A. Predicción (sin ejecutar el código):**

1. ¿Cuál será la salida final en la consola de este programa?
2. Escribe la salida completa que esperas.
3. Dibuja un mapa de memoria conceptual de este programa justo antes de que `main` finalice. Debes indicar en qué segmento de memoria (Stack, Heap, Datos Globales/Estáticos, Código) se encontraría cada una de las siguientes variables: `contador_global`, `contador_estatico`, `val_A`, `val_B`, `val_C` (dentro de main), el parámetro a de la función `sumaPorValor`, la función main misma.
**B. Verificación y análisis (usando el depurador):**
Ejecuta el programa paso a paso (F10) con un `breakpoint` al inicio de `main`.
4. Compara la salida real con tu predicción. Si hubo diferencias, explica por qué ocurrieron. Evidencia clave: capturas de pantalla antes y después de los puntos de interés (¿Cuáles son esos puntos? -> tu tarea analizarlo).
5. Describe qué demuestran estas capturas sobre la diferencia entre los diferentes tipos de paso por parámetros analizados.
6. Explica con tus propias palabras el comportamiento de contador_estatico. ¿Por qué “recuerda” su valor entre llamadas a la función ejecutarContador? ¿En qué se diferencia de una variable local normal?

# **Actividad 6: Hola Objeto: creación de un objeto en el stack**

Este experimento es fundamental porque conecta el concepto fundamental de POO (objetos) con este curso.

Vas a crear una clase sencilla llamada Punto que represente un punto en el espacio con dos coordenadas (`x` e `y`). Luego, crearás un objeto de esta clase en el `stack` y utilizarás el depurador para inspeccionar su contenido y dirección de memoria.

### Pasos:

- Abre Visual Studio y crea un nuevo proyecto de consola en C++.
- Define la siguiente clase en un archivo `.cpp` (puedes incluir todo en `main.cpp`):

1. ¿Cuál es la diferencia entre un constructor y un destructor en C++?
2. ¿Cuál es la diferencia entre un objeto y una clase en C++?
3. ¿Qué diferencia notas entre el objeto Punto en C++ y C#?
4. ¿Qué es `p` en C++ y qué es `p` en C#? (en uno de ellos `p` es un objeto y en el otro es una referencia a un objeto).
5. ¿En qué parte de memoria se almacena `p` en C++ y en C#?
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
				
