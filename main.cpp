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

    Nodo(string nombre, char id)
    {
        this->nombre = nombre;
        this->id = id;
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

class Juego
{
private:
    ListaCircular lista;

public:
    // Constructor
    Juego();
    // Métodos principales del menú
    void menuPrincipal();
    void inscribir();
    void verListadoParticipantes();
    void jugarCompetencia();
    void mostrarAyuda();
    void mostrarIntegrantes();
    // Métodos de lógica del juego
    void jugarRonda(Nodo *jugador1, Nodo *jugador2);
    bool validarOpcion(char opcion);
    bool validarCantidadParticipantes(int cantidad);
    int contarParticipantes();
};

ListaCircular::ListaCircular()
{
    cabeza = nullptr; // Inicializamos la cabeza de la lista circular como nullptr, indicando que está vacía.
}

// Se implementa para poder Insertar
void ListaCircular::insertar(string nombre, char id)
{
    Nodo *nuevo = new Nodo(nombre, id);

    if (estaVacia())
    {
        cabeza = nuevo;
        nuevo->siguiente = cabeza;
    }
    else
    {
        Nodo *temp = cabeza;
        while (temp->siguiente != cabeza)
        {
            temp = temp->siguiente;
        }

        temp->siguiente = nuevo;
        nuevo->siguiente = cabeza;
    }
}

Nodo *ListaCircular::obtenerGanador()
{
    if (estaVacia())
        return nullptr;

    Nodo *temp = cabeza;
    Nodo *ganador = cabeza;

    do
    {
        if (temp->puntaje > ganador->puntaje)
        {
            ganador = temp;
        }
        temp = temp->siguiente;
    } while (temp != cabeza);

    return ganador;
}

// Verficar si se inscribieron bien(mostrar)
void ListaCircular::mostrar()
{
    if (estaVacia())
    {
        cout << "No hay jugadores inscritos" << endl;
        return;
    }

    Nodo *temp = cabeza;

    do
    {
        cout << "Nombre: " << temp->nombre
             << " | ID:" << temp->id
             << " | Puntos: " << temp->puntaje << endl;

        temp = temp->siguiente;

    } while (temp != cabeza);
}

void ListaCircular::reiniciarPuntajes()
{
    if (estaVacia())
        return;

    Nodo *temp = cabeza;
    do
    {
        temp->puntaje = 0;
        temp = temp->siguiente;
    } while (temp != cabeza);
}

// Para reiniciar puntos

/*
Lo implementamos para verificar si la lista circular esta vacía.
*/

bool ListaCircular::estaVacia()
{
    // La lista está vacía si la cabeza es nullptr
    return cabeza == nullptr;
}

// Obtener el tamaño de la lista circular.
int ListaCircular::obtenerTamano()
{
    if (estaVacia())
    {
        return 0;
    }

    int contador = 0;

    Nodo *temp = cabeza; // Creamos un nodo temporal.

    // Recorremos la lista circular.
    do
    {
        contador++; // Incrementamos el contador por cada nodo que encontramos.
        temp = temp->siguiente;
    } while (temp != cabeza);

    return contador;
}

// Obtener la cabeza de la lista circular.
Nodo *ListaCircular::obtenerCabeza()
{
    return cabeza; // Devuelve un puntero al nodo cabeza de la lista circular.
}

// Obtener el siguiente nodo en la lista circular.
Nodo *ListaCircular::obtenerSiguiente(Nodo *nodo)
{
    if (nodo == nullptr)
    {
        return nullptr; // Si el nodo es nulo, no hay siguiente, así que devolvemos nullptr.
    }
    return nodo->siguiente; // Devuelve el puntero al siguiente nodo en la lista circular.
}

Juego::Juego()
{
}
// Método para inscribir jugadores en el juego.
void Juego::inscribir()
{
    string nombre;
    char id;

    cout << "=== INSCRIBIR JUGADOR ===" << endl;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "ID (1 carácter): "; //
    cin >> id;

    lista.insertar(nombre, id); // Insertamos el nuevo jugador en la lista circular utilizando el método insertar de la clase ListaCircular.
    cout << "¡" << nombre << " inscrito correctamente!" << endl;
}

int main()
{

    return 0;
}