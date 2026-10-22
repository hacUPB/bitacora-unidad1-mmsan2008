
## 1. Incluye una captura de pantalla del ejemplo funcionando en tu máquina.
<img width="1919" height="1009" alt="Captura de pantalla 2026-10-06 142245" src="https://github.com/user-attachments/assets/34aec486-1e8a-4c81-a2ef-179c071b6361" />
## 2. Observa el proyecto, trata de entenderlo, pero ten presente que lo analizaremos más adelante.

## 3. ¿Qué preguntas te surgen al ver el código? Anota al menos tres preguntas que te gustaría investigar más adelante (no te preocupes que la idea de esta unidad es que las resuelvas).
como se ejecuta esto mediante la gpu? para que sirve crear ventanas? que es glf?

# GLFW, opengl32.lib, GLAD, GLM y los drivers de la GPU.
# ¿Qué rol cumple cada uno? 
GLFW sirve para crear ventanas manejar el teclado y el mause y dar contexto a open gl
opengl32.lib Permite iniciar opengl
GLAD carga las funciones de opengl
glm es una bibiloteca de matematicas que sirve para hacer animaciones graficos o transformaciones 
# ¿Cómo se relacionan entre sí?
cada una tiene su relacion y glfw opengl32.lib y glad son fundamentales para crear el proyecto glm no es obligatoriom pero ayuda y facilita algunas cosas 


# glViewport(0, bufferHeight/2, bufferWidth/2, bufferHeight/2);`
Cambia los valores de bufferWidth y bufferHeight: divide por 2, por 4, multiplica por 2, por 4, etc. 
¿Qué pasa? el viwport cambia y el triangulo se sale de la pantalla y se estira 
¿Qué observas? el triangulo se ve diferente
¿Qué crees que está pasando? que el viwport no tiene el mismo tamaño de la pantalla y se corta 

# Resumen 

probando y entediendo los conceptos en el codigo , experimente que pasaba si cambiaba la resolcion a 1920 x 1080 y me salio ese mensaje 
<img width="1039" height="55" alt="image" src="https://github.com/user-attachments/assets/9688a33d-109a-41f6-82eb-1e7fef12bae5" />
tambien probe cambiando el viwport el color y el triangulo y consegui esto.
<img width="1003" height="597" alt="image" src="https://github.com/user-attachments/assets/0dfb5af1-dc73-4de8-9525-cca2de6653c1" />
tambien experimente modificando los vertices y cambia el sentido del trangulo
<img width="359" height="363" alt="image" src="https://github.com/user-attachments/assets/614566fe-9f9e-4cac-b394-b6e797470579" />
# R//
con esto puede entender que el triangulo funciona mediante vertices VAO mediante una matriz array
he entendido en esta actividad 
que glfw es una biblioteca que por la cual mediante instrucciones de un contexto opengl puedo crear una ventana y con Framebuffer guardar la memoria de la ventana en 
la gpu y es donde se dibujan cada cuadro como una hoja y el Viewport es el area del framebuffer que se visualiza


# ¿Qué pasa si cambias el primer parámetro de glDrawArrays a GL_LINES? 
el triangulo se convierte en una linea 
<img width="378" height="376" alt="image" src="https://github.com/user-attachments/assets/14a3f2e4-9933-450a-bfb1-202bd77788aa" />
# ¿Qué pasa si lo cambias a GL_POINTS? 
se crean 3 puntos en forma de triangulo
<img width="372" height="380" alt="image" src="https://github.com/user-attachments/assets/f4df76ad-20ca-4a9e-ac57-b420e8af25df" />
# ¿Qué pasa si cambias el tercer parámetro a 2? 
solo quedan 2 vertices
<img width="380" height="382" alt="image" src="https://github.com/user-attachments/assets/ecc2a9f0-74eb-4911-be60-0ce7ca595577" />
# ¿Qué pasa si lo cambias a 4?
se crea otro vetice en el medio de triangulo 
<img width="278" height="290" alt="image" src="https://github.com/user-attachments/assets/7a28c07b-9f70-4363-b708-a1b22d927c47" />
En esta unidad no profundizaremos en los tipos de primitivas, pero es importante que entiendas que OpenGL puede dibujar diferentes tipos de primitivas (triángulos, líneas, puntos, etc.).


1. ¿Qué es el contexto OpenGL?
   son las instrucciones que se mandan a la gpu para implementar la ventana
3. ¿Cuál es el rol de la biblioteca GLFW y qué ventaja tiene usarla?
   la biblioteca sirve para crear la ventana 
5. ¿Por qué crees que OpenGL necesita un contexto (recuerda la analogía del taller de arte)?
   el contexto es como el estudio y sin este el artista no puede hacer su arte los graficos 
7. ¿En últimas qué será el framebuffer y a qué te recuerda de las dos primeras unidades del curso?
   el framebuffer es como la hoja donde se guarda la memoria y se dibujan los cuadros
9. ¿Qué relación entre en el viewport y el framebuffer?
    el viwport es el que determina el area visible del frambuffer
11. ¿En todo la analizado hasta ahora qué rol juega los drivers de la GPU y la GPU misma?
    
13. ¿Por qué crees que sea necesario activar el VSync? ¿Si no lo activas y la imagen es estática qué crees que pase, y si es dinámica?
    la tasa de refresco de la ventana al mismo valor que la tasa de refresco del monitor, Esto evita el tearing y hace que el movimiento sea más suave.
15. En esta unidad estamos usando OpenGL moderno, pero ¿Qué es OpenGL Legacy? ¿Qué diferencias hay entre ambos?
    el legacy es el modelo de arquitectura de función fija y el moderno elimina esa función fija y obliga al programador a usar sombreadores (shaders)
17. ¿Qué es el shader program? ¿Por qué es importante en OpenGL moderno?
     los shaders son los programas que OpenGL ejecuta en la GPU para procesar los vértices y fragmentos (píxeles) de la escena, y opengl moderno es importante por que es el que permite funcionar los shaders
19. Trata de revisar el código setupTriangle(), intuitivamente ¿Qué crees que hace? ¿Qué crees que es el VAO y el VBO?
     Esta función es fundamental porque define cómo se verá el triángulo en pantalla, el vao es el que permite organizar los vertices y el vbo le da la informacion de tamaño, color etc
21. En el ciclo principal (game loop) de OpenGL, notaste que en cada frame (cuadro) le decimos a openGL que use el shader program y el VAO. Si le indicas esto antes del game loop ¿Será necesario seguirlo haciendo en cada loop? Si no es necesario ¿En qué casos crees que esto puede ser útil? no es estrictamente necesario dentro del game loop si solo estás dibujando un único objeto con un único shader program y un único  (VAO).

## Actividad 4



##  ¿Cuál es la diferencia entre una CPU y una GPU?
la diferencia entre la cpu y la gpu, es que la cpu tienen menos nucleos pero hace tareas mas complejas y scuencialmente, la gpu tiene miles de nucles pero hace muchas tareas mas sencillas simultáneamente


##  ¿Cuáles son los tres pasos claves del pipeline de OpenGL? Explica en tus propias palabras cuál es el objetivo de cada paso.
los tres pasos claves son 
el vertex shading: el objetivo de este es cojer los vértices de los modelos 3D, transforman sus posiciones y se proyectan para determinar dónde aparecerán en la pantalla.
la Rasterización: aqui los triángulos se convierten en fragmentos que corresponden a posibles píxeles de la imagen.
El fragment shader: este calcula el color de los fragmentos.
   
##  La gran novedad que introduce OpenGL moderno es el pipeline programable. ¿Qué significa esto? ¿Qué diferencia hay entre el pipeline fijo y el programable? ¿Qué ventajas le ves a esto? y si el pipeline es programable, ¿Qué tengo que programar
si el pipeline es programable, significa que podemos escribir programas llamados shaders para controlar determinadas etapas del procesamiento gráfico, en lugar de depender exclusivamente de las operaciones predefinidas por OpenGL.
la diferencia entre el pipeline fijo y el programable es que en el fijo todo es más predeterminado y en el programable nos permite crear shaders personalizados.
Veo varias ventajas, como tener más libertad y crear más cosas fuera de lo normal, con más creatividad, control y personalización.
si el pipeline es programable principalmente se programan los shaders que necesita una aplicación



##  Si fueras a describir el proceso de **rasterización** ¿Qué dirías?
   el proceso de convertir una imagen en píxeles que los dispositivos puedan mostrar
   
##  ¿Qué son los fragmentos? ¿Es lo mismo un fragmento que un pixel? ¿Por qué?
   son los atributos visuales de cada como el color la profundidad y otros atributos de los fragmentos esta información sirve para el pixel final
##  Explica qué problema resuelve el **Z-buffer** y ¿qué es el depth test?
   El Z-buffer es un mecanismo que permite gestionar la profundidad de los objetos para determinar cuáles están delante de otro sin este mecanismo, un objeto dibujado después podría aparecer por encima de otro aunque estuviera más lejos de la cámara.
el depth test es la prueba que compara la profundidad del fragmento con la que ya está almacenada en el búfer de profundidad.

##  ¿Por qué se presenta el problema del **aliasing**? ¿Qué es el anti-aliasing?
El aliasing aparece porque una imagen digital representa una escena continua mediante una cantidad limitada de píxeles. Cuando hay detalles o bordes que no se pueden representar adecuadamente con esa resolución, aparecen errores visuales.
el anti-aliasing  es un conjunto de técnicas que reducen esos defectos visuales, estimando mejor cómo deben representarse los bordes y los detalles en los píxeles.

##  ¿Qué relación hay entre la iluminación y el fragment shader? ¿Siempre es necesario tener en cuenta la iluminación en un fragment shader? ¿o puedo hacer un fragment shader sin iluminación? Explica que implicaciones tiene esto.
El fragment shader es uno de los lugares donde se puede calcular la iluminación de una superficie sin embargo, no es obligatorio implementar iluminación en todos los fragment shaders
Con iluminación puede representar volumen, sombras y reflejos, requiere cálculos adicionales y el aspecto depende de las luces y los materiales
Sin iluminación, puede producir colores uniformes y estilos gráficos planos, Suele requerir menos cálculos, El color depende de lo que programes directamente.
    
##  ¿Qué implica para la GPU que una aplicación tenga múltiples fuentes de iluminación?
Cuando una escena tiene varias luces, la GPU debe considerar cómo contribuye cada una al aspecto de los objetos.


##  Escribe un resumen en tus propias palabras de lo que se necesita para dibujar un triángulo en OpenGL.
Para dibujar un triángulo se necesita en primera instancia crear un objeto opengl que almacene los datos de los vértices y los envíe a la gpu, ya en el código se inicia creando una función llamada setuptriangle
Definimos los vértices del triángulo; estos dan la forma mediante unas coordenadas de -1 y 1. Después, creamos un objeto VAO y un VBO para obtener la dirección ip de estos. Luego, hacemos binding al VAO y VBO para que se apliquen todos los comandos que se envían desde OpenGL. Se mandan los datos de los vértices al buffer de vértices, se configuran los atributos y, de último, hacemos unbinding del VAO, también tenemos que agregar shaders en este caso se agrega un vertex shader y un fragment shader el vertex shader con los datos de los vértices asigna la posición de estos y el fragment shader asigna el color .

   
##  Escribe un resumen en tus propias palabras de lo que necesitas para poder usar un shader en OpenGL.
   Para poder usar un shader primordialmente se necesita crear un vertex shader y un fragment shader y además asignar la versión de cada uno en el vertex shader necesitamos representar la posición de los datos de los vértices y definir la función principal, en el fragment shader necesitamos asignar el color y de igual forma la función principal.


   ## modificacion de código 
   Modifiqué el código como se indicó, pero no se generó nada. 
<img width="1919" height="1034" alt="image" src="https://github.com/user-attachments/assets/cab028a6-9fac-49b7-8d7f-23bab2be7dca" />

