# ¿Cómo puedes interactuar con la aplicación? Menciona específicamente las teclas y qué efecto parecen tener sobre las partículas.
se puede interactuar con las teclas s,a,r,n 
S: para el movimiento de las particulas 
A: hace como la funcion de un iman i atrae las particulas a donde este el mause 
R: repele las particulas y estas se alejan de donde este el mouse
N: hace que vuelva a movimiento por defecto de las particulas 

# ¿Observas los diferentes tipos de “partículas”? ¿Se comportan todas igual inicialmente?
las particulas se comportan igual todas van a la misma velocidad y revotan en las paredes de igual manera la unica diferencia es su color y tamaño 
siendo rojo mas pequeño verde medianas azules mas grandes
# Toma algunas capturas de pantalla de la aplicación en diferentes momentos (estado inicial, después de presionar ‘a’, ‘r’, ‘s’, ‘n’) y añádelas a tu bitácora.
# N
<img width="1015" height="752" alt="image" src="https://github.com/user-attachments/assets/d9f8f186-0f38-4cb2-9566-748a0e75d439" />
# S 
<img width="1017" height="764" alt="image" src="https://github.com/user-attachments/assets/ab627500-2f48-4128-9add-1f25f6aa70f8" />
# A 
<img width="796" height="594" alt="image" src="https://github.com/user-attachments/assets/c98fc7e9-c328-4ad4-be41-5c806d39b92d" />
# R
<img width="1014" height="759" alt="image" src="https://github.com/user-attachments/assets/3c0383ab-463b-4ca1-aa03-9361cf72a939" />

# ¿Qué crees que está pasando “detrás de cámaras” cuando presionas las teclas? Formula una hipótesis inicial sobre cómo la aplicación cambia el comportamiento de las partículas.
yo creo que cada ves que presiono n s a o r el programa cambia de estado al estado asignado a cada tecla y estos estados son clases y sub clases


# Explica con tus propias palabras el propósito del patrón Observer. ¿Qué problema resuelve?
el patron obeserver permite mediante una subscripcion notificar a varios objetos un evento que se este llamando 

# Dibuja un diagrama que muestre la relación entre `Subject`, `Observer`, `ofApp` y `Particle` en el caso de estudio, indicando quién es el Sujeto y quiénes los Observadores.

# Construye un diagrama de secuencia que muestre cómo funciona el patrón Observer al presionar una tecla.

# ¿Qué ventajas crees que ofrece usar el patrón Observer en esta aplicación en comparación con, por ejemplo, que `ofApp::update` recorriera todas las partículas y les dijera directamente que cambien su comportamiento basado en una variable global? Piensa en términos de acoplamiento y extensibilidad.
