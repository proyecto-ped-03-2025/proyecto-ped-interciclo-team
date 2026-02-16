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

// Para poder mostrar el listado de participantes inscritos en el juego.
void Juego::verListadoParticipantes()
{
    cout << "=== LISTADO DE PARTICIPANTES ===" << endl;
    lista.mostrar(); // Llamamos al método mostrar de la clase ListaCircular para mostrar los participantes inscritos.
}

void Juego::jugarCompetencia()
{

    int cantidad = lista.obtenerTamano();

    if (!validarCantidadParticipantes(cantidad))
    {
        cout << "\nSe necesitan al menos 2 participantes.\n";
        return;
    }

    lista.reiniciarPuntajes();

    Nodo *actual = lista.obtenerCabeza();

    cout << "\n=== INICIANDO COMPETENCIA ===\n";

    do
    {

        Nodo *rival = actual->siguiente;

        while (rival != lista.obtenerCabeza())
        {

            jugarRonda(actual, rival);

            rival = rival->siguiente;
        }

        actual = actual->siguiente;

    } while (actual != lista.obtenerCabeza());

    cout << "\nCompetencia finalizada.\n";
}
void Juego::mostrarAyuda()
{
    cout << "\n╔════════════════════════════════════════════════════╗" << endl;
    cout << "║          AYUDA - PIEDRA, PAPEL O TIJERA            ║" << endl;
    cout << "╚════════════════════════════════════════════════════╝\n"
         << endl;

    cout << "REGLAS DEL JUEGO:" << endl;
    cout << "  • Piedra vence a  Tijera" << endl;
    cout << "  • Tijera vence a Papel" << endl;
    cout << "  • Papel vence a Piedra" << endl;
    cout << "  • Si ambos jugadores eligen lo mismo, es un empate\n"
         << endl;

    cout << "OPCIONES DE JUEGO:" << endl;
    cout << "  P - Piedra" << endl;
    cout << "  A - Papel" << endl;
    cout << "  T - Tijera\n"
         << endl;

    cout << "SISTEMA DE PUNTOS:" << endl;
    cout << "  • Victoria   -> +3 puntos" << endl;
    cout << "  • Empate     -> +1 punto" << endl;
    cout << "  • Derrota    -> 0 puntos\n"
         << endl;

    cout << "ESTRUCTURA DEL TORNEO:" << endl;
    cout << "  1. Todos los jugadores compiten contra todos los demás" << endl;
    cout << "  2. Cada enfrentamiento se juega una sola vez" << endl;
    cout << "  3. Los puntos se acumulan durante todo el torneo\n"
         << endl;

    cout << "PASOS PARA JUGAR:" << endl;
    cout << "  1. Inscribe a los jugadores en el sistema" << endl;
    cout << "  2. Verifica el listado de participantes" << endl;
    cout << "  3. Inicia la competencia (se necesitan al menos 2 jugadores)" << endl;
    cout << "  4. Todos los jugadores competirán entre sí" << endl;
    cout << "  5. Al finalizar, se mostrará el ganador del torneo\n"
         << endl;
}
// Para mostrar los integrantes del proyecto.
void Juego::mostrarIntegrantes()
{
    cout << "\n╔════════════════════════════════════════════════════╗" << endl;
    cout << "║              INTEGRANTES DEL PROYECTO              ║" << endl;
    cout << "╚════════════════════════════════════════════════════╝\n"
         << endl;

    cout << "INTEGRANTE 1:" << endl;
    cout << "  Nombre: KEVIN ADOLFO GUTIERREZ SALINAS" << endl;
    cout << "  Carnet: 00086125\n"
         << endl;

    cout << "INTEGRANTE 2:" << endl;
    cout << "  Nombre: DAVID OCTAVIO CASTRO SANTAMARIA" << endl;
    cout << "  Carnet: 00369425\n"
         << endl;

    cout << "PROYECTO: Piedra, Papel o Tijera" << endl;
}

int main()
{

    return 0;
}