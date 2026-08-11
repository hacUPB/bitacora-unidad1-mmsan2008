#include <iostream>
using namespace std;


void SwapPorValor(int a, int b,int d) {
    cout << "Dentro de modificarPorValor, valor inicial: " << d << endl;
    d=b;
    cout << "Dentro de modificarPorValor, valor modificado: " << b << endl;


    cout << "Dentro de modificarPorValor, valor inicial: " << b << endl;
    b=a;

    cout << "Dentro de modificarPorValor, valor modificado: " << a << endl;

    cout << "Dentro de modificarPorValor, valor inicial: " << a << endl;
    a = d;

    cout << "Dentro de modificarPorValor, valor modificado: " << d << endl;


}


void SwapPorReferencia(int& n) {
    cout << "Dentro de modificarPorReferencia, valor inicial: " << n << endl;
    n += 5;
    cout << "Dentro de modificarPorReferencia, valor modificado: " << n << endl;
}


void SwapPorPuntero(int* n) {
    cout << "Dentro de modificarPorPuntero, valor inicial: " << *n << endl;
    *n += 5;
    cout << "Dentro de modificarPorPuntero, valor modificado: " << *n << endl;
}

int main() {
    int a = 10;    int b = 5;    int c = 10; int d = 0;
    cout << "Valor inicial de a (paso por valor): " << a << endl;
    cout << "Valor inicial de b (paso por referencia): " << b << endl;
    cout << "Valor inicial de c (paso por puntero): " << c << endl;
    cout << "\nLlamando a modificarPorValor(a)..." << endl;
    SwapPorValor(a,b,d);
    cout << "Después de modificarPorValor, valor de a: " << a << endl;
    cout << "\nLlamando a modificarPorReferencia(b)..." << endl;
    SwapPorReferencia(b);
    cout << "Después de modificarPorReferencia, valor de b: " << b << endl;
    cout << "\nLlamando a modificarPorPuntero(&c)..." << endl;
    SwapPorPuntero(&c);
    cout << "Después de modificarPorPuntero, valor de c: " << c << endl;
    return 0;
}