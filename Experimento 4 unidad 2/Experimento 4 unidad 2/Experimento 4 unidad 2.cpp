#include <iostream>
#include <cstdlib>
using namespace std;
// Función de ejemplo que muestra la dirección de su variable local estática
void funcionConStatic() {
    static int var_estatica = 100;
    cout << "Dirección de var_estatica (static): " << &var_estatica << endl;
}
void incremento() {
   static int contador = 0;
        contador++;
        cout << "contador = " << contador << endl;
       
}

int main() {    // Variable local (stack)
    incremento();
    incremento();
    incremento();
    int a = 10;
    int b = 20;
    /**********************************************************
    EXPERIMENTO 4
    ***********************************************************/
    static int var_estatica = 42;
    cout << "var_estatica: " << var_estatica << endl;
    /********************************************************/
    funcionConStatic();
    return 0;
}
 //static ayuda a conservar el valor de la variable y permite salir y volver a entrar a la funcion si no tiene static el valor de la variable se pierde