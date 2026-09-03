#include <iostream>
#include <cstdlib>
using namespace std;
// Constante global
const char* const mensaje_ro = "Hola, memoria de solo lectura";

int main() {
    // Variable local (stack)
    int a = 10;
    int b = 20;

    /**********************************************************
    EXPERIMENTO 2
    ***********************************************************/
    char* ptr = (char*)&mensaje_ro;
    cout << "Voy a modificar la memoria en la dirección: " << ptr << endl;
    *ptr = 0;
    /********************************************************/
    return 0;
}

//no se redirecciona en ptr por que la variable mensaje_ro es una constante y pertenese al segmento de codigo que es solo lectura 