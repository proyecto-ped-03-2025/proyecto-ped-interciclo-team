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

//Se implementa para poder Insertar
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

//Verficar si se inscribieron bien(mostrar)
void ListaCircular::mostrar(){
    if (estaVacia()){
        cout << "No hay jugadores inscritos"<<endl;
        return;
    }

    Nodo* temp = cabeza;

    do{
        cout<< "Nombre: "<< temp->nombre
        <<" | ID:"<< temp-> id
        << " | Puntos: "<< temp-> puntaje << endl;

        temp = temp -> siguiente;



    } while (temp!=cabeza);



}




/*
Lo implementamos para verificar si la lista circular esta vacía.
*/

bool ListaCircular::estaVacia() {
    // La lista está vacía si la cabeza es nullptr
    return cabeza == nullptr;
}

int main()
{

    return 0;
}