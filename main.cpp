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

    Nodo(string nombre, char id){
        this->nombre = nombre;
        this->id= id;
        puntaje = 0;
        siguiente = nullptr;

    }
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


void ListaCircular::insertar(string nombre, char id){
    Nodo* nuevo = new Nodo(nombre, id);

    if (estaVacia()){
        cabeza = nuevo;
        nuevo -> siguiente = cabeza;
    } else {
        Nodo* temp= cabeza;
        while(temp->siguiente!=cabeza){
            temp = temp-> siguiente;
        }

        temp -> siguiente =nuevo;
        nuevo -> siguiente = cabeza;
    }


}
int main(){







    return 0;
}