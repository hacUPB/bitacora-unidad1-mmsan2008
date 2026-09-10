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
despues de crea la clase de explocion particule que hereda igualmente de particle esta determina como va a ser la explocion como su tamaño y color despues se crea CircularExplosion que hereda de ExplosionParticle y esta determina la forma circular de la explocion de esta misma manera tambien se crea RandomExplosion que hace que las explociones tengan diferentes posiciones y startexplocion que determina la explocion en forma de estrella
ya ofapp.h actualiza las particulas define en que orden se generan los tipos de explociones  y determina la duracion de las particulas y con que tecla se activan. 

# Actividad 3

¿Qué esperas ver en memoria (hipótesis)? 
en memoria espero ver como la variable vector particles llama a la direccion de memoria de  la instancia de objeto particle 

en la actividad 3 podemos observar al intanciar circular expolición como se aplica el pliformismo en la direccion de memoria se observa como hereda los metodos de particle y les da una direccion de memoria 
