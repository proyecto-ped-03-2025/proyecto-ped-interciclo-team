## 1. FLUJO PRINCIPAL DEL PROGRAMA

                    +------------------+
                    |     INICIO       |
                    +------------------+
                             |
                             v
                    +------------------+
                    |   Juego juego    |
                    |  (crear objeto)  |
                    +------------------+
                             |
                             v
        +-----------------------------------------------+
        |               MENU PRINCIPAL                  |
        |                                               |
        |   1. Inscribir participante                   |
        |   2. Ver listado de participantes             |
        |   3. Iniciar competencia                      |
        |   4. Mostrar ganador                          |
        |   5. Ayuda                                    |
        |   6. Integrantes                              |
        |   7. Mostrar podio                            |
        |   8. Reiniciar puntajes                       |
        |   9. Mostrar participantes recursivamente     |
        |  10. Salir                                    |
        +-----------------------------------------------+
                             |
       +----------+----------+----------+----------+
       |          |          |          |          |
       v          v          v          v          v

+---------+ +-------+ +--------+ +--------+ +--------+
|[1] | |[2] | |[3] | |[4] | |[5] |
|Inscribir| |Ver | |Iniciar | |Mostrar | |Ayuda |
|(Diagr.2)| |Listado| |Compet. | |Ganador | |(Diagr.8|
| | |(D.3) | |(D.4) | |(D.7) | | |
+---------+ +-------+ +--------+ +--------+ +--------+
| | | | |
+----------+----------+----------+----------+
|
+----------+----------+----------+----------+
| | | | |
v v v v v
+---------+ +--------+ +--------+ +--------+ +--------+
|[6] | |[7] | |[8] | |[9] | |[10] |
|Integran-| |Mostrar | |Reiniciar|Mostrar | |Salir |
|tes(D.8) | |Podio | |Puntajes|Recursivo| | |
| | |(D.9) | |(D.10) | (D.11) | | |
+---------+ +--------+ +--------+ +--------+ +--------+
| | | | |
+----------+----------+----------+----+-----+
| |
| v
| +-----------+
| | FIN |
| +-----------+
v
+---------------------+
| opciones != 10? |
+---------------------+
|
+----------+----------+
| |
SI NO
| |
v v
Volver al Menu +-----------+
| FIN |
+-----------+

```

---

## 2. FLUJO DE INSCRIPCION DE PARTICIPANTE

```

         +-----------------------------+
         |    INSCRIBIR PARTICIPANTE   |
         +-----------------------------+
                       |
                       v
         +-----------------------------+
         |  cin.ignore()               |
         |  (limpiar buffer)           |
         +-----------------------------+
                       |
         +-------------v-----------+ <---------+
         |  Solicitar nombre       |           |
         |  getline(cin, nombre)   |           |
         +-------------+-----------+           |
                       |                       |
         +-------------v-----------+           |
         |   nombre.empty()?       |           |
         +-------------+-----------+           |
                       |                       |
              +--------+--------+              |
              |                 |              |
              SI               NO              |
              |                 |              |
              v                 |              |
    +------------------+        |              |
    | "El nombre no    |        |              |
    |  puede estar     +--------+              |
    |  vacio"          |--------^--------------+
    +------------------+
                       |
                       v (nombre valido)
         +-------------v-----------+ <---------+
         |  Solicitar ID           |           |
         |  cin >> idStr           |           |
         +-------------+-----------+           |
                       |                       |
         +-------------v-----------+           |
         |  idStr.length() != 1?   |           |
         +-------------+-----------+           |
                       |                       |
              +--------+--------+              |
              |                 |              |
              SI               NO              |
              |                 |              |
              v                 |              |
    +------------------+        |              |
    | "El ID debe ser  |        |              |
    |  exactamente 1   +--------+              |
    |  caracter"       |--------^--------------+
    +------------------+
                       |
                       v (ID valido)
         +-----------------------------+
         |  cin.ignore()               |
         |  id = idStr[0]              |
         +-----------------------------+
                       |
                       v
         +-----------------------------+
         |  Crear nodo con:            |
         |  - nombre                   |
         |  - id                       |
         |  - puntaje = 0              |
         |  - siguiente = nullptr      |
         +-----------------------------+
                       |
                       v
         +-----------------------------+
         |      Lista vacia?           |
         +-----------------------------+
                       |
              +--------+--------+
              |                 |
              SI               NO
              |                 |
              v                 v
    +----------------+  +------------------------+
    | cabeza = nuevo |  | Recorrer hasta el      |
    | nuevo->sig.    |  | ultimo nodo            |
    |   = cabeza     |  | ultimo->sig. = nuevo   |
    +-------+--------+  | nuevo->sig. = cabeza   |
            |           +----------+-------------+
            |                      |
            +----------+-----------+
                       |
                       v
         +-----------------------------+
         | "!nombre inscrito           |
         |  correctamente!"            |
         +-----------------------------+
                       |
                       v
         +-----------------------------+
         |      Volver al menu         |
         +-----------------------------+

```

---

## 3. FLUJO DE VISUALIZACION DE PARTICIPANTES

```

         +-----------------------------+
         | VER LISTADO DE PARTICIPANTES|
         +-----------------------------+
                       |
                       v
         +-----------------------------+
         |       Lista vacia?          |
         +-----------------------------+
                       |
              +--------+--------+
              |                 |
              SI               NO
              |                 |
              v                 v
    +----------------+  +---------------------------+
    | "No hay        |  |  Para cada nodo (do-while)|
    |  jugadores     |  |  Mostrar:                 |
    |  inscritos"    |  |  - Nombre                 |
    +-------+--------+  |  - ID                     |
            |           |  - Puntos                 |
            |           +------------+--------------+
            |                        |
            +----------+-------------+
                       |
                       v
                +-------------+   --
                | Volver al   |
                | menu        |
                +-------------+

```

---

## 4. FLUJO PRINCIPAL DE LA COMPETENCIA

```

         +-----------------------------+
         |    INICIAR COMPETENCIA      |
         +-----------------------------+
                       |
                       v
         +-----------------------------+
         |  Obtener cantidad de        |
         |  participantes              |
         +-----------------------------+
                       |
                       v
         +-----------------------------+
         |      cantidad >= 2?         |
         +-----------------------------+
                       |
              +--------+--------+
              |                 |
              SI               NO
              |                 |
              v                 v
    +----------------+  +------------------------+
    | Reiniciar      |  | "Se necesitan al menos |
    | puntajes       |  |  2 participantes"      |
    | (todos = 0)    |  | return                 |
    +-------+--------+  +------------------------+
            |
            v
    +----------------+
    | actual = cabeza|
    | (primer jugad.)|
    +-------+--------+
            |
            v
    +--------------------------------------------+
    |  BUCLE EXTERNO: do-while                   |
    |  (actual recorre toda la lista)            |
    +--------------------------------------------+
            |
            v
    +----------------+
    | rival = actual |
    |  ->siguiente   |
    +-------+--------+
            |
            v
    +--------------------------------------------+
    |  BUCLE INTERNO: while rival != cabeza      |
    +--------------------------------------------+
            |
            v
    +--------------------------------------------+
    |  JUGAR RONDA (actual vs rival)             |
    |  (Ver diagrama 5)                          |
    +--------------------------------------------+
            |
            v
    +--------------------+
    | rival = rival      |
    |   ->siguiente      |
    +--------+-----------+
             |
    +--------v-----------+
    |  rival != cabeza?  |
    +--------+-----------+
             |
     +-------+-------+
     |               |
     SI              NO
     |               |
     v               v

(repite +--------------------+
bucle | actual = actual |
interno) | ->siguiente |
+--------+-----------+
|
+---------v---------+
| actual != cabeza? |
+---------+---------+
|
+-------+-------+
| |
SI NO
| |
v v
(repite +------------------+
bucle | "Competencia |
externo) | finalizada" |
+--------+---------+
|
+--------v---------+
| Volver al menu |
+------------------+

```

---

## 5. FLUJO DE UNA RONDA (Jugador 1 vs Jugador 2)

```

         +-----------------------------+
         |     RONDA: J1 vs J2        |
         +-----------------------------+
                       |
                       v
         +-----------------------------+
         | "Ronda: [J1] vs [J2]"      |
         +-----------------------------+
                       |
         +-------------v-----------+ <---------+
         |  Solicitar opcion J1    |           |
         |  cin >> entrada         |           |
         |  opcion1 = toupper(     |           |
         |    entrada[0])          |           |
         +-------------+-----------+           |
                       |                       |
         +-------------v-----------+           |
         |  validarOpcion(opcion1)?|           |
         +-------------+-----------+           |
                       |                       |
              +--------+--------+              |
              |                 |              |
           VALIDO           INVALIDO           |
              |                 |              |
              |                 v              |
              |       +------------------+     |
              |       | "Opcion invalida.|     |
              |       |  Elige P, A o T" +-----+
              |       +------------------+
              |
              v (opcion1 valida)
         +-------------v-----------+ <---------+
         |  Solicitar opcion J2    |           |
         |  cin >> entrada         |           |
         |  opcion2 = toupper(     |           |
         |    entrada[0])          |           |
         +-------------+-----------+           |
                       |                       |
         +-------------v-----------+           |
         |  validarOpcion(opcion2)?|           |
         +-------------+-----------+           |
                       |                       |
              +--------+--------+              |
              |                 |              |
           VALIDO           INVALIDO           |
              |                 |              |
              |                 v              |
              |       +------------------+     |
              |       | "Opcion invalida.|     |
              |       |  Elige P, A o T" +-----+
              |       +------------------+
              |
              v (ambas opciones validas)
         +-----------------------------+
         |    MOSTRAR RONDA VISUAL     |
         |  +-------------------------+|
         |  |        !RONDA!          ||
         |  |   J1      VS      J2   ||
         |  | [P/A/T]       [P/A/T]  ||
         |  +-------------------------+|
         +-----------------------------+
                       |
                       v
         +-----------------------------+
         |  resultado =                |
         |  comparar(opcion1, opcion2) |
         |  (Ver diagrama 6)           |
         +-----------------------------+
                       |
          +------------+------------+
          |            |            |
          v            v            v

resultado=0 resultado=1 resultado=2
(EMPATE) (GANA J1) (GANA J2)
| | |
v v v
+-----------+ +----------+ +----------+
| J1: +1 pt | | J1: +3pt | | J2: +3pt |
| J2: +1 pt | | J2: +0pt | | J1: +0pt |
+-----+-----+ +----+-----+ +----+-----+
| | |
+-------------+------------+
|
v
+-----------------------------+
| Mostrar resultado de |
| la ronda |
+-----------------------------+
|
v
+-----------------------------+
| Retornar al flujo de |
| competencia |
+-----------------------------+

```

---

## 6. FLUJO DE COMPARACION (Logica del Juego)

```

         +-----------------------------+
         | COMPARAR(opcion1, opcion2)  |
         +-----------------------------+
                       |
                       v
         +-----------------------------+
         |    opcion1 == opcion2?      |
         +-----------------------------+
                       |
              +--------+--------+
              |                 |
              SI               NO
              |                 |
              v                 v
       +-----------+   +---------------------------+
       | return 0  |   | Es combinacion            |
       | (EMPATE)  |   | ganadora para J1?         |
       +-----------+   |  P vs T (Piedra>Tijera)   |
                       |  T vs A (Tijera>Papel)    |
                       |  A vs P (Papel>Piedra)    |
                       +-------------+-------------+
                                     |
                            +--------+--------+
                            |                 |
                            SI               NO
                            |                 |
                            v                 v
                     +-----------+     +-----------+
                     | return 1  |     | return 2  |
                     | (GANA J1) |     | (GANA J2) |
                     +-----------+     +-----------+

```

---

## 7. FLUJO MOSTRAR GANADOR

```

         +-----------------------------+
         |      MOSTRAR GANADOR        |
         +-----------------------------+
                       |
                       v
         +-----------------------------+
         | Recorrer lista (do-while)   |
         | y encontrar nodo con mayor  |
         | puntaje                     |
         +-----------------------------+
                       |
                       v
         +-----------------------------+
         |      ganador == null?       |
         +-----------------------------+
                       |
              +--------+--------+
              |                 |
              SI               NO
              |                 |
              v                 v
    +----------------+  +---------------------------+
    | "No hay        |  | "![nombre] es el GANADOR!"|
    |  ganador"      |  | "Puntos totales: [pts]"   |
    +-------+--------+  +-------------+-------------+
            |                         |
            +----------+--------------+
                       |
                       v
                +-------------+
                | Volver al   |
                | menu        |
                +-------------+

```

---

## 8. FLUJO MOSTRAR AYUDA

```

         +-----------------------------+
         |       MOSTRAR AYUDA         |
         +-----------------------------+
                       |
                       v
         +------------------------------------+
         | Mostrar en pantalla:               |
         |                                    |
         | REGLAS:                            |
         |  - Piedra vence a Tijera           |
         |  - Tijera vence a Papel            |
         |  - Papel vence a Piedra            |
         |  - Iguales = empate                |
         |                                    |
         | OPCIONES: P / A / T                |
         |  P = Piedra                        |
         |  A = Papel                         |
         |  T = Tijera                        |
         |                                    |
         | PUNTOS:                            |
         |  - Victoria  -> +3 puntos          |
         |  - Empate    -> +1 punto           |
         |  - Derrota   ->  0 puntos          |
         |                                    |
         | ESTRUCTURA DEL TORNEO:             |
         |  1. Todos vs todos                 |
         |  2. Una sola vez cada par          |
         |  3. Puntos acumulativos            |
         |                                    |
         | PASOS PARA JUGAR:                  |
         |  1. Inscribir jugadores            |
         |  2. Verificar listado              |
         |  3. Iniciar competencia (min. 2)   |
         |  4. Todos compiten entre si        |
         |  5. Se muestra el ganador          |
         +------------------------------------+
                       |
                       v
                +-------------+
                | Volver al   |
                | menu        |
                +-------------+

```

---

## 9. FLUJO MOSTRAR PODIO

```

         +-----------------------------+
         |       MOSTRAR PODIO         |
         +-----------------------------+
                       |
                       v
         +-----------------------------+
         |      Lista vacia?           |
         +-----------------------------+
                       |
              +--------+--------+
              |                 |
              SI               NO
              |                 |
              v                 v
    +----------------+  +----------------------------------+
    | "No hay        |  | Inicializar:                     |
    |  jugadores     |  | primero = null                   |
    |  en el podio"  |  | segundo = null                   |
    +-------+--------+  | tercero = null                   |
            |           +----------------+-----------------+
            |                            |
            |                            v
            |           +----------------------------------+
            |           | Recorrer lista (do-while):       |
            |           | Para cada nodo:                  |
            |           |                                  |
            |           |  puntaje > primero?              |
            |           |    tercero = segundo             |
            |           |    segundo = primero             |
            |           |    primero = temp                |
            |           |  sino puntaje > segundo?         |
            |           |    tercero = segundo             |
            |           |    segundo = temp                |
            |           |  sino puntaje > tercero?         |
            |           |    tercero = temp                |
            |           +----------------+-----------------+
            |                            |
            |                            v
            |           +----------------------------------+
            |           | Mostrar podio:                   |
            |           | 1er Lugar: [nombre] - [pts]      |
            |           | 2do Lugar: [nombre] - [pts]      |
            |           | 3er Lugar: [nombre] - [pts]      |
            |           | (solo si existen)                |
            |           +----------------+-----------------+
            |                            |
            +----------+-----------------+
                       |
                       v
                +-------------+
                | Volver al   |
                | menu        |
                +-------------+

```

---

## 10. FLUJO REINICIAR PUNTAJES

```

         +-----------------------------+
         |     REINICIAR PUNTAJES      |
         +-----------------------------+
                       |
                       v
         +-----------------------------+
         |       Lista vacia?          |
         +-----------------------------+
                       |
              +--------+--------+
              |                 |
              SI               NO
              |                 |
              v                 v
     (no hace nada)   +---------------------------+
                      | Recorrer lista (do-while) |
                      | asignar puntaje = 0       |
                      | a cada nodo               |
                      +-----------+---------------+
                                  |
                                  v
                      +---------------------------+
                      | "Puntajes reiniciados.    |
                      |  Puedes iniciar una       |
                      |  nueva competencia"       |
                      +-----------+---------------+
                                  |
                                  v
                           +-------------+
                           | Volver al   |
                           | menu        |
                           +-------------+

```

---

## 11. FLUJO MOSTRAR PARTICIPANTES RECURSIVAMENTE

```

         +------------------------------------+
         | MOSTRAR PARTICIPANTES              |
         | RECURSIVAMENTE                     |
         +------------------------------------+
                       |
                       v
         +-----------------------------+
         |       Lista vacia?          |
         +-----------------------------+
                       |
              +--------+--------+
              |                 |
              SI               NO
              |                 |
              v                 v
    +----------------+  +---------------------------+
    | "No hay        |  | Llamar:                   |
    |  participantes"|  | mostrarRecursivoAux(cabeza|
    +-------+--------+  +-----------+---------------+
            |                       |
            |                       v
            |           +--------------------------+
            |           | [mostrarRecursivoAux]    |
            |           |                          |
            |           | Mostrar:                 |
            |           | - Nombre                 |
            |           | - Puntaje                |
            |           | - ID                     |
            |           +----------+---------------+
            |                      |
            |           +----------v---------------+
            |           | actual->siguiente        |
            |           |     != cabeza?           |
            |           +----------+---------------+
            |                      |
            |             +--------+--------+
            |             |                 |
            |             SI               NO
            |             |                 |
            |             v                 v
            |    +------------------+  (fin de recursion)
            |    | Llamada recursiva|
            |    | mostrarRecursivo |
            |    | Aux(actual->sig.)|
            |    +------------------+
            |
            +----------+
                       |
                       v
                +-------------+
                | Volver al   |
                | menu        |
                +-------------+

```

---

```
