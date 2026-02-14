#include <iostream>
using namespace std;
// Estructura de nodo:
struct Nodo
{
    string nombre;
    float puntaje;
    char id;
    Nodo *siguiente;
};



class ListaCircular{
    private:
    Nodo* cabeza;
    
    public:
    ListaCircular();
    void insertar(string nombre, char id);
    void mostrar();
    bool estaVacia();
    int obtenerTamano();
    Nodo*obtenerCabeza();
    void reiniciarPuntajes();
    Nodo*obtenerSiguiente(Nodo* nodo);
    Nodo*obtenerGanador();
};
int main(){







    return 0;
}