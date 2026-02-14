#include <iostream>

#include <string>

using namespace std;

// Estructura de nodo:
struct Nodo
{
    string nombre;
    float puntaje;
    char id;
    Nodo *siguiente;
};

class ListaCircular
{
private:
    Nodo *cabeza;

public:
    // constructor
    ListaCircular();
    void insertar(string nombre, char id);
    void mostrar();
    bool estaVacia();
    int obtenerTamano();
    Nodo *obtenerCabeza();
    void reiniciarPuntajes();
    Nodo *obtenerSiguiente(Nodo *nodo);
    Nodo *obtenerGanador();
};

/*
Lo implementamos para verificar si la lista circular esta vacía.
*/

bool ListaCircular::estaVacia()
{
    // La lista está vacía si la cabeza es nullptr
    return cabeza == nullptr;
}

int main()
{

    return 0;
}