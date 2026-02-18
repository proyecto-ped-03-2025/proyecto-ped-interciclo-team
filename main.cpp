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
    void mostrarRecursivoAux(Nodo *actual);

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
    void mostrarRecursivo();
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
    int comparar(char opcion1, char opcion2);
    void mostrarGanador();
    void mostrarPodio();
    void mostrarRondaVisual(char opcion1, char opcion2, Nodo *jugador1, Nodo *jugador2);
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
    string idStr;
    char id;

    cout << "=== INSCRIBIR JUGADOR ===" << endl;

    cin.ignore(); // Limpiamos el buffer de entrada para evitar problemas con getline después de usar cin >> en el menú principal.

    // Validar que el nombre no esté vacío
    do
    {
        cout << "Nombre: ";
        getline(cin, nombre);
        if (nombre.empty()) // Si el nombre está vacío, mostramos un mensaje de error y pedimos que se ingrese nuevamente.
            cout << "El nombre no puede estar vacío.\n";
    } while (nombre.empty());

    // Validar ID de exactamente 1 carácter
    do
    {
        cout << "ID (1 carácter): ";
        cin >> idStr;
        if (idStr.length() != 1)
            cout << "El ID debe ser exactamente 1 carácter. Intente nuevamente.\n";
    } while (idStr.length() != 1);

    cin.ignore(); // Limpiamos el buffer de entrada después de leer el ID para evitar problemas con getline en futuras inscripciones.

    id = idStr[0]; // Asignamos el primer carácter de la cadena idStr al char id.

    lista.insertar(nombre, id); // Llamamos al método insertar de la clase ListaCircular para agregar el nuevo jugador a la lista circular.
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

void Juego::jugarRonda(Nodo *jugador1, Nodo *jugador2)
{
    char opcion1, opcion2;

    cout << "\nRonda: " << jugador1->nombre << " vs " << jugador2->nombre << endl;
    cout << jugador1->nombre << ", elige tu opción (P/A/T): ";
    cin >> opcion1;
    cout << jugador2->nombre << ", elige tu opción (P/A/T): ";
    cin >> opcion2;

    if (!validarOpcion(opcion1) || !validarOpcion(opcion2))
    {
        cout << "Opción inválida. Por favor, elige P, A o T." << endl;
        return;
    }

    mostrarRondaVisual(opcion1, opcion2, jugador1, jugador2); // Mostramos la ronda de manera visual utilizando el método mostrarRondaVisual para representar las opciones elegidas por los jugadores con emojis.

    int resultado = comparar(opcion1, opcion2); // Comparamos las opciones de los jugadores utilizando el método comparar para determinar el resultado de la ronda (empate, victoria del jugador 1 o victoria del jugador 2).

    if (resultado == 0) // Empate
    {
        cout << "Empate entre " << jugador1->nombre << " y " << jugador2->nombre << endl;
        jugador1->puntaje += 1;
        jugador2->puntaje += 1;
    }
    else if (resultado == 1) // Jugador 1 gana
    {
        cout << jugador1->nombre << " gana la ronda contra " << jugador2->nombre << endl;
        jugador1->puntaje += 3;
    }
    else // Jugador 2 gana (resultado == 2)
    {
        cout << jugador2->nombre << " gana la ronda contra " << jugador1->nombre << endl;
        jugador2->puntaje += 3;
    }
}

bool Juego::validarOpcion(char opcion)
{

    if (opcion == 'P' || opcion == 'A' || opcion == 'T')
        return true;

    cout << "Opcion invalida. Intente nuevamente.\n";
    return false;
}

// Para poder validar la cantidad de participantes antes de iniciar la competencia, asegurando que haya al menos 2 jugadores inscritos.
bool Juego::validarCantidadParticipantes(int cantidad)
{
    return cantidad >= 2;
}

int Juego::contarParticipantes()
{
    return lista.obtenerTamano();
}
// Para comparar las opciones de los jugadores y determinar el resultado de la ronda, devolviendo un valor que indica si es un empate, victoria del jugador 1 o victoria del jugador 2.
int Juego::comparar(char opcion1, char opcion2)
{
    if (opcion1 == opcion2)
        return 0; // Empate

    if ((opcion1 == 'P' && opcion2 == 'T') || // Piedra vence a Tijera
        (opcion1 == 'T' && opcion2 == 'A') || // Tijera vence a Papel
        (opcion1 == 'A' && opcion2 == 'P'))   // Papel vence a Piedra

        return 1; // Jugador 1 gana

    return 2; // Jugador 2 gana
}

// Solo el ganador
void Juego::mostrarGanador()
{
    Nodo *ganador = lista.obtenerGanador(); // Llamamos al método obtenerGanador de la clase ListaCircular para obtener el nodo del jugador con el puntaje más alto.

    if (ganador == nullptr)
    {
        cout << "No hay ganador." << endl;
        return;
    }

    cout << "\n¡" << ganador->nombre << " es el GANADOR! " << endl;
    cout << "Puntos totales: " << ganador->puntaje << endl;
}
void Juego::mostrarPodio()
{
    if (lista.obtenerTamano() == 0)
    {
        cout << "No hay jugadores en el podio." << endl;
        return;
    }

    Nodo *primero = nullptr, *segundo = nullptr, *tercero = nullptr; // Inicializamos punteros para los tres mejores jugadores (podio) como nullptr.

    // Recorrer y encontrar los 3 mejores
    Nodo *temp = lista.obtenerCabeza(); // Creamos un nodo temporal para recorrer la lista circular, comenzando desde la cabeza.
    do
    {
        // Comparamos el puntaje del jugador actual (temp) con los puntajes de los jugadores en el podio (primero, segundo, tercero) para determinar su posición en el podio.
        if (primero == nullptr || temp->puntaje > primero->puntaje)
        {
            tercero = segundo; // Si encontramos un nuevo primer lugar, el segundo lugar actual pasa a ser el tercero, y el primer lugar actual pasa a ser el segundo.
            segundo = primero; // Luego, actualizamos el primer lugar con el nuevo jugador que tiene el puntaje más alto.
            primero = temp;    // Si el jugador actual tiene un puntaje mayor que el primer lugar, actualizamos el podio en consecuencia.
        }
        // Si el jugador actual no es el nuevo primer lugar, verificamos si es el nuevo segundo lugar comparando su puntaje con el del segundo lugar actual.
        else if (segundo == nullptr || temp->puntaje > segundo->puntaje)
        {
            tercero = segundo; // Si el jugador actual tiene un puntaje mayor que el segundo lugar pero no mayor que el primer lugar, actualizamos el tercer lugar con el segundo lugar actual, y luego actualizamos el segundo lugar con el nuevo jugador.
            segundo = temp;    // Si el jugador actual tiene un puntaje mayor que el segundo lugar pero no mayor que el primer lugar, actualizamos el tercer lugar con el segundo lugar actual, y luego actualizamos el segundo lugar con el nuevo jugador.
        }
        // Si el jugador actual no es el nuevo primer lugar ni el nuevo segundo lugar, verificamos si es el nuevo tercer lugar comparando su puntaje con el del tercer lugar actual.
        else if (tercero == nullptr || temp->puntaje > tercero->puntaje)
        {
            tercero = temp; // Si el jugador actual tiene un puntaje mayor que el tercer lugar pero no mayor que el primer o segundo lugar, actualizamos el tercer lugar con el nuevo jugador.
        }

        temp = temp->siguiente; //| Avanzamos al siguiente nodo en la lista circular para continuar el recorrido.
    } while (temp != lista.obtenerCabeza());

    // Mostrar podio
    cout << "\n╔════════════════════════════════════════════════════╗" << endl;
    cout << "║                    PODIO                             ║" << endl;
    cout << "╚════════════════════════════════════════════════════╝\n"
         << endl;

    if (primero)
        cout << " 1er Lugar: " << primero->nombre << " - " << primero->puntaje << " pts" << endl;

    if (segundo)
        cout << " 2do Lugar: " << segundo->nombre << " - " << segundo->puntaje << " pts" << endl;

    if (tercero)
        cout << " 3er Lugar: " << tercero->nombre << " - " << tercero->puntaje << " pts" << endl;

    cout << endl;
}

// Para mostrar de manera visual las opciones elegidas por los jugadores en cada ronda, utilizando emojis para representar piedra, papel y tijera, y mostrando claramente quién eligió qué opción.
void Juego::mostrarRondaVisual(char opcion1, char opcion2, Nodo *jugador1, Nodo *jugador2)
{
    cout << "\n╔════════════════════════════════════════════════════╗" << endl;
    cout << "║                    ¡RONDA!                         ║" << endl;
    cout << "╠════════════════════════════════════════════════════╣" << endl;
    cout << "║  " << jugador1->nombre << "              " << jugador2->nombre << endl;
    cout << "║     ";

    if (opcion1 == 'P')
        cout << "📄 PAPEL";
    else if (opcion1 == 'T')
        cout << "✂️ TIJERA";
    else if (opcion1 == 'A')
        cout << "🪨 PIEDRA";

    cout << "       VS       ";

    if (opcion2 == 'P')
        cout << "📄 PAPEL";
    else if (opcion2 == 'T')
        cout << "✂️ TIJERA";
    else if (opcion2 == 'A')
        cout << "🪨 PIEDRA";

    cout << "     ║\n";
    cout << "╚════════════════════════════════════════════════════╝\n"
         << endl;
}
void ListaCircular::mostrarRecursivo()
{
    if (estaVacia())
    {
        cout << "No hay participantes.\n";
        return;
    }

    mostrarRecursivoAux(cabeza);
}
void ListaCircular::mostrarRecursivoAux(Nodo *actual)
{
    cout << "Nombre: " << actual->nombre
         << " | Puntaje: " << actual->puntaje
         << " | ID: " << actual->id << endl;

    if (actual->siguiente != cabeza)
        mostrarRecursivoAux(actual->siguiente);
}

void Juego::menuPrincipal()
{
    int opcion;

    do
    {
        cout << "\n==============================\n";
        cout << "      PIEDRA PAPEL TIJERA\n";
        cout << "==============================\n";
        cout << "1. Inscribir participante\n";
        cout << "2. Ver listado de participantes\n";
        cout << "3. Iniciar competencia\n";
        cout << "4. Mostrar ganador\n";
        cout << "5. Ayuda\n";
        cout << "6. Integrantes\n";
        cout << "7. Mostrar podio\n";
        cout << "8. Reiniciar puntajes\n";
        cout << "9. Mostrar ronda visual\n";
        cout << "10. Mostrar participantes recursivamente\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            inscribir();
            break;

        case 2:
            verListadoParticipantes();
            break;

        case 3:
            jugarCompetencia();
            break;

        case 4:
            mostrarGanador();
            break;

        case 5:
            mostrarAyuda();
            break;

        case 6:
            mostrarIntegrantes();
            break;
        case 7:
            mostrarPodio();
            break;
        case 8:
            lista.reiniciarPuntajes();
            cout << "\nPuntajes reiniciados. Puedes iniciar una nueva competencia.\n";
            break;
        case 9:
            mostrarRondaVisual('P', 'T', new Nodo("Jugador 1", 'X'), new Nodo("Jugador 2", 'Y')); // Ejemplo de visualización de ronda con opciones predeterminadas.
            break;
        case 10:
            lista.mostrarRecursivo();
            break;

        case 0:
            cout << "\nSaliendo del programa...\n";
            break;

        default:
            cout << "\nOpcion invalida. Intente nuevamente.\n";
        }

    } while (opcion != 0);
}

int main()
{
    Juego juego;           // Crear objeto del juego
    juego.menuPrincipal(); // Llamar al menú principal
    return 0;
}
