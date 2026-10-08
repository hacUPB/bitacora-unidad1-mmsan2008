
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
tambien experimente modificando los vertices
<img width="359" height="363" alt="image" src="https://github.com/user-attachments/assets/614566fe-9f9e-4cac-b394-b6e797470579" />
y cambia el sentido del trangulo
con esto puede entender que el triangulo funciona mediante vertices VAO mediante una matriz array
he entendido en esta actividad 
que glfw es una biblioteca que por la cual mediante instrucciones de un contexto opengl puedo crear una ventana y con Framebuffer guardar la memoria de la ventana en 
la gpu y es donde se dibujan cada cuadro como una hoja y el Viewport es el area del framebuffer que se visualiza

¿Qué pasa si cambias el primer parámetro de glDrawArrays a GL_LINES? 
el triangulo se convierte en una linea 
<img width="378" height="376" alt="image" src="https://github.com/user-attachments/assets/14a3f2e4-9933-450a-bfb1-202bd77788aa" />
¿Qué pasa si lo cambias a GL_POINTS? 
se crean 3 puntos en forma de triangulo
<img width="372" height="380" alt="image" src="https://github.com/user-attachments/assets/f4df76ad-20ca-4a9e-ac57-b420e8af25df" />
¿Qué pasa si cambias el tercer parámetro a 2? 
solo quedan 2 vertices
<img width="380" height="382" alt="image" src="https://github.com/user-attachments/assets/ecc2a9f0-74eb-4911-be60-0ce7ca595577" />
¿Qué pasa si lo cambias a 4?
se crea otro vetice en el medio de triangulo 
<img width="278" height="290" alt="image" src="https://github.com/user-attachments/assets/7a28c07b-9f70-4363-b708-a1b22d927c47" />
En esta unidad no profundizaremos en los tipos de primitivas, pero es importante que entiendas que OpenGL puede dibujar diferentes tipos de primitivas (triángulos, líneas, puntos, etc.).

