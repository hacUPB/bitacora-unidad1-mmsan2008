# ¿Qué es el encapsulamiento para ti? Describe una situación en la que te haya sido útil o donde hayas visto su importancia

encapsulamiento es cuando  se restriegue el acceso de los componentes internos de una clase para proteger su información y yo gestiono ese acceso mediante public private o protected, se puede ver en un computador los componentes internos estan encapsulados en la torre y yo accedo al computadro mediante el teclado y el raton.

# ¿Qué es la herencia? ¿Por qué un programador decidiría usarla? Da un ejemplo simple.

la herencia conciste en crear clases padres he hijos las padres contienen atributos y metodos y los hijos heredan estos atributos y metodos y ya se le puede agregar a estos componentes propios
un programador decide usar la herencia ya que facilita a la hora de crear clases parecidas y así se ahorra colocar los mismos atributos y métodos 

# ¿Qué es el polimorfismo? Describe con tus palabras qué significa que un código sea “polimórfico”.

 el polimorfismo es la posibilidad de un objeto de responder a un método de diferentes formas, y si un codigo es poliformico significa que puede responer a un metodo de diferentes formas.

 

# Actividad 2 
<img width="1919" height="1031" alt="image" src="https://github.com/user-attachments/assets/7c866b7d-235b-46ec-bac7-9922f6577a67" />

en esta actividad se crea un proyecto con open frame words analizando el codigo puede identificar que se utilizan clases abstractas con metodos estos se llaman mediante herencia en otras clases 
primero se crea RisingParticle que hereda de particle esta crea la particula con su posicion y velocidad y determina la codicion para que la particula explote 
Después de crear la clase de explosión partícula que hereda igualmente de particle esta determina cómo va a ser la explosión como su tamaño y color después se crea CircularExplosion que hereda de ExplosionParticle y esta determina la forma circular de la explosión de esta misma manera también se crea RandomExplosion que hace que las explosiones tengan diferentes posiciones y startexplosión que determina la explosión en forma de estrella
ya ofapp.h actualiza las particulas define en que orden se generan los tipos de explociones  y determina la duracion de las particulas y con que tecla se activan. 

# Actividad 3

¿Qué esperas ver en memoria (hipótesis)? 
en memoria espero ver como la variable vector particles llama a la direccion de memoria de  la instancia de objeto particle 

en la actividad 3 podemos observar al intanciar circular expolición como se aplica el pliformismo en la direccion de memoria se observa como hereda los metodos de particle y les da una direccion de memoria 
<img width="1890" height="673" alt="image" src="https://github.com/user-attachments/assets/baf6aa62-eefc-4937-9629-0a7ebd20e266" />


# Actividad 4


¿Qué sucede? aparece un error de compilacion
¿Por qué sucede esto? por que las variables son protected y private
¿Qué puedes concluir? que si una variable es privada o protegida no se puede acceder a los datos y aparece error de compilacion
<img width="1530" height="934" alt="image" src="https://github.com/user-attachments/assets/9d47295c-fcc1-4521-9c7f-401aea667236" />

en esta otra versión aparece error de compilacion otra vez ya que las variables son privadas y no se puede acceder  
<img width="1470" height="837" alt="image" src="https://github.com/user-attachments/assets/1c485948-f353-4ba6-ac64-569f889db940" />
y en el ultimo ejemplo se puede evidenciar como utiliza reinterpret_cast para poder acceder a las variables privadas de esta manera evadiendo el encapsulamiento 


# Actividad 5


<img width="1266" height="987" alt="image" src="https://github.com/user-attachments/assets/562af764-cf26-4d7d-90ad-0d72e3557683" />
Se puede observar como CircularExplosion hereda de ExplosionParticle que a su ves hereda de particle el depurador me proporciona una tabla virtual con los metodos de particle y los atributos de ExplosionParticle 
la herencia se implementa en la clase hijo colocando dos puntos el tipo de encapsulamiento y la clase padre de la que va a heredar

# actividad 6 

**Realiza un dibujo con el cuál expliques cómo se implementa el polimorfismo en tiempo de ejecución. Utiliza el concepto de métodos virtuales y la tabla de funciones virtuales. ¿Qué puedes concluir?**

<img width="1377" height="281" alt="Captura de pantalla 2026-10-01 101051" src="https://github.com/user-attachments/assets/233e7df9-dc28-4cbf-8388-f01c2c349976" />
<img width="1277" height="588" alt="Captura de pantalla 2026-10-01 101106" src="https://github.com/user-attachments/assets/0a6e8e2d-9e70-4a2f-b30d-08ef304792f2" />
<img width="1010" height="323" alt="Captura de pantalla 2026-10-01 101113" src="https://github.com/user-attachments/assets/69a64bfd-f57c-4b4a-8231-e8070e2ce714" />
se puede concluir que se crea una clase abstracta llamada animal con un metodo virtual hacer sonido despues se crean dos clases perro y gato estas heredan de animal el metodo hacer sonido y mediante un puntero que va a el objeto gato y perro en memoria, consulta la entrada en su vtable y ejecuta la función correcta

 **¿Qué relación existe entre los métodos virtuales y el polimorfismo?**
si se define un metodo virtual la clase seria una clase abstracta esto es fundamental para aplicar el polimorfismo ya que mediante una método virtual podemos crear por ejemplo que dos clases hereden este método y hagan una accion diferente 

