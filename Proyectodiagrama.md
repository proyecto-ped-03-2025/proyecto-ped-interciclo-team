## 1. FLUJO PRINCIPAL DEL PROGRAMA

```
                           ┌─────────────────┐
                           │     INICIO      │
                           └────────┬────────┘
                                    │
                           ┌────────▼────────┐
                           │  MENÚ PRINCIPAL │
                           └────────┬────────┘
                                    │
                 ┌──────────────────┼──────────────────┐
                 │                  │                  │
                 ▼                  ▼                  ▼
         ┌──────────────┐    ┌──────────────┐    ┌──────────────┐
         │ Inscribir    │    │ Ver Listado  │    │ Jugar        │
         │ Participantes│    │ Participantes│    │ Competencia  │
         └──────────────┘    └──────────────┘    └──────────────┘
                 │                  │                  │
                 └──────────────────┼──────────────────┘
                                    │
                 ┌──────────────────┼──────────────────┐
                 │                  │                  │
                 ▼                  ▼                  ▼
         ┌──────────────┐    ┌──────────────┐    ┌──────────────┐
         │ Ver Ayuda    │    │ Integrantes  │    │ Salir        │
         │ del Juego    │    │ del Grupo    │    │              │
         └──────────────┘    └──────────────┘    └──────┬───────┘
                 │                  │                     │
                 └──────────────────┼─────────────────────┘
                                    │
                           ┌────────▼────────┐
                           │    ¿Otra        │
                           │   opción?       │
                           └────────┬────────┘
                                    │
                         ┌──────────┴──────────┐
                         │                     │
                        SÍ                    NO
                         │                     │
                         │                     ▼
                         │            ┌─────────────────┐
                         │            │      FIN        │
                         │            └─────────────────┘
                         │
                         └──────────────────────┘
```

---

## 2. FLUJO DE INSCRIPCIÓN DE PARTICIPANTES

```
              ┌────────────────────────────────┐
              │  INSCRIPCIÓN DE PARTICIPANTES  │
              └────────────┬───────────────────┘
                           │
                  ┌────────▼────────┐
                  │ ¿Cuántos        │
                  │ participantes?  │
                  │ (min 2, máx 10) │
                  └────────┬────────┘
                           │
                ┌──────────┴──────────┐
                │                     │
             VÁLIDO               INVÁLIDO
                │                     │
                │                     ▼
                │              ┌─────────────┐
                │              │ Error:      │
                │              │ Rango       │
                │              │ Incorrecto  │
                │              └──────┬──────┘
                │                     │
                │                     └────────────┐
                │                                   │
                ▼                                   │
        ┌──────────────┐                           │
        │ Crear Lista  │                           │
        │ Circular     │                           │
        └──────┬───────┘                           │
               │                                   │
               ▼                                   │
        ┌──────────────────┐                      │
        │ Para cada        │                      │
        │ participante:    │                      │
        │ 1. Solicitar     │                      │
        │    nombre        │                      │
        │ 2. Solicitar     │                      │
        │    carácter ID   │                      │
        │ 3. Crear nodo    │                      │
        │ 4. Insertar en   │                      │
        │    lista circular│                      │
        └──────┬───────────┘                      │
               │                                   │
               ▼                                   │
        ┌──────────────┐                          │
        │ ¿Hay más     │                          │
        │ jugadores?   │                          │
        └──────┬───────┘                          │
               │                                  │
            ┌──SÍ──┐                              │
            │      └─────────┐                    │
            │                ▼                    │
            │        ┌──────────────────┐         │
            │        │ Siguiente        │         │
            │        │ Participante     │         │
            │        └──────┬───────────┘         │
            │               │                     │
            │               └────────────────┐    │
            │                                ▼    │
            │                        ┌────────────┘
            │                        │
            NO                       │
            │                        │
            ▼                        ▼
        ┌──────────────┐      ┌───────────────┐
        │ Participantes│      │    Reintentar │
        │ inscritos    │      └───────┬───────┘
        │ exitosamente │              │
        └──────┬───────┘              │
               │                      │
               └──────────┬───────────┘
                          │
                   ┌──────▼──────┐
                   │ Volver menú │
                   │  principal  │
                   └─────────────┘
```

---

## 3. FLUJO DE VISUALIZACIÓN DE PARTICIPANTES

```
            ┌─────────────────────────────┐
            │ VER LISTADO DE PARTICIPANTES│
            └────────────┬────────────────┘
                         │
             ┌───────────▼───────────┐
             │ ¿Hay participantes    │
             │ inscritos?            │
             └───────────┬───────────┘
                         │
                    ┌────┴─────┐
                    │           │
                   SÍ           NO
                    │           │
                    ▼           ▼
            ┌──────────────┐ ┌────────────────┐
            │ Mostrar:     │ │ Mensaje: No hay│
            │ 1. Número    │ │ participantes  │
            │ 2. Nombre    │ │ inscritos      │
            │ 3. Carácter  │ └────────┬───────┘
            │    ID        │         │
            └──────┬───────┘         │
                   │                 │
                   │                 │
                   └────────┬────────┘
                            │
                     ┌──────▼──────┐
                     │ Volver menú │
                     │  principal  │
                     └─────────────┘
```

---

## 4. FLUJO PRINCIPAL DEL JUEGO (COMPETENCIA)

```
              ┌──────────────────────┐
              │ INICIAR COMPETENCIA  │
              └──────────┬───────────┘
                         │
                ┌────────▼────────┐
                │ ¿Hay al menos 2 │
                │ participantes?  │
                └────────┬────────┘
                         │
                    ┌────┴────┐
                    │          │
                   SÍ          NO
                    │          │
                    ▼          ▼
            ┌──────────────┐ ┌──────────────┐
            │ Inicializar  │ │ Error: Se    │
            │ puntajes en  │ │ necesitan    │
            │ cero para    │ │ mínimo 2     │
            │ todos        │ │ jugadores    │
            └──────┬───────┘ └──────┬───────┘
                   │               │
                   │               └──────┐
                   │                      │
                   ▼                      │
            ┌─────────────────────────┐  │
            │ Crear nodo actual       │  │
            │ en la lista circular    │  │
            │ (primer jugador)        │  │
            └──────┬──────────────────┘  │
                   │                     │
                   ▼                     │
            ┌────────────────┐           │
            │ Para cada ronda│           │
            │ (todos vs todos│           │
            │  = n*(n-1)/2)  │           │
            └──────┬─────────┘           │
                   │                     │
                   ▼                     │
            ┌──────────────────────┐     │
            │ Obtener Jugador 1    │     │
            │ (nodo actual)        │     │
            │                      │     │
            │ Avanzar a siguiente  │     │
            │ jugador (siguiente   │     │
            │ nodo en la lista)    │     │
            │                      │     │
            │ Obtener Jugador 2    │     │
            └──────┬───────────────┘     │
                   │                     │
                   ▼                     │
            ┌──────────────────────┐     │
            │ JUGAR RONDA ENTRE    │     │
            │ JUGADOR 1 Y 2        │     │
            │ (Ver diagrama 5)     │     │
            └──────┬───────────────┘     │
                   │                     │
                   ▼                     │
            ┌──────────────────────┐     │
            │ ¿Todas las rondas    │     │
            │ completadas?         │     │
            └──────┬───────────────┘     │
                   │                     │
            ┌──────┴──────┐              │
            │             │              │
           NO             SÍ             │
            │             │              │
            └─────┬───────┘              │
                  │                      │
                  ▼                      │
        ┌──────────────────────┐         │
        │ DETERMINAR GANADOR   │         │
        │ (Mayor puntaje)      │         │
        └──────┬───────────────┘         │
               │                        │
               ▼                        │
        ┌──────────────────────┐        │
        │ MOSTRAR RESULTADOS:  │        │
        │ 1. Tabla de puntajes │        │
        │ 2. Ganador           │        │
        │ 3. Mención de honor  │        │
        │    (2do y 3er lugar) │        │
        └──────┬───────────────┘        │
               │                        │
               └──────────┬─────────────┘
                          │
                   ┌──────▼──────┐
                   │ Volver menú │
                   │  principal  │
                   └─────────────┘
```

---

## 5. FLUJO DE UNA RONDA (Jugador 1 vs Jugador 2)

```
              ┌──────────────────────────┐
              │ RONDA: JUGADOR 1 VS 2    │
              └──────────┬───────────────┘
                         │
                ┌────────▼────────┐
                │ Solicitar:      │
                │ - Opción Jug. 1 │
                │   (P/p/T/t)     │
                │ - Opción Jug. 2 │
                │   (P/p/T/t)     │
                └────────┬────────┘
                         │
            ┌────────────▼────────────┐
            │ Validar opciones       │
            │ (son P, p, T o t)      │
            └────────────┬────────────┘
                         │
                    ┌────┴────┐
                    │          │
                 VÁLIDO     INVÁLIDO
                    │          │
                    │          ▼
                    │   ┌─────────────┐
                    │   │ Error:      │
                    │   │ Opción      │
                    │   │ inválida    │
                    │   │ Reintentar  │
                    │   └────────┬────┘
                    │            │
                    │            └──┐
                    │               │
                    ▼               │
            ┌───────────────────┐   │
            │ COMPARAR OPCIONES │   │
            │ y DETERMINAR      │   │
            │ RESULTADO         │   │
            └───────┬───────────┘   │
                    │               │
                    │               │
         ┌──────────┼──────────┐    │
         │          │          │    │
         ▼          ▼          ▼    │
    ┌────────┐ ┌───────┐ ┌────────┐│
    │ EMPATE │ │GANA J1│ │ GANA J2││
    └────┬───┘ └──┬────┘ └───┬────┘│
         │        │           │    │
         │        ▼           ▼    │
         │    ┌──────┐    ┌──────┐ │
         │    │ J1:  │    │ J2:  │ │
         │    │ +1pt │    │ +1pt │ │
         │    └─┬────┘    └──┬───┘ │
         │      │            │    │
         ▼      ▼            ▼    │
         │    ┌──────┐    ┌──────┐│
         │    │ J1:  │    │ J2:  ││
         │    │ +0.5 │    │ +0.5 ││
         └─►  │ pts  │    │ pts  ││
              └──┬───┘    └───┬──┘│
                 │            │   │
                 └─────┬──────┘   │
                       │          │
                       └──────┬───┘
                              │
                       ┌──────▼──────┐
                       │ Mostrar      │
                       │ resultado de │
                       │ la ronda     │
                       │ - Opciones   │
                       │ - Ganador    │
                       │ - Puntaje    │
                       └──────┬───────┘
                              │
                       ┌──────▼──────┐
                       │ Retornar a   │
                       │ flujo de     │
                       │ competencia  │
                       └─────────────┘
```

---

## 6. FLUJO DE COMPARACIÓN (Lógica del Juego)

```
              ┌────────────────────┐
              │ COMPARAR OPCIONES  │
              │ (P/T vs P/T)       │
              └────────┬───────────┘
                       │
        ┌──────────────┼──────────────┐
        │              │              │
        ▼              ▼              ▼
    PIEDRA         PAPEL         TIJERA
        │              │              │
        │              │              │
    ┌───┴──┐       ┌──┴────┐     ┌───┴──┐
    │      │       │       │     │      │
    ▼      ▼       ▼       ▼     ▼      ▼
   vs P   vs T    vs P   vs T   vs P   vs T
    │      │       │       │     │      │
    ▼      ▼       ▼       ▼     ▼      ▼
 EMPATE  GANA   GANA   EMPATE  GANA  GANA
        OTRO   ESTE           OTRO  ESTE
        │      │       │       │     │      │
        └──────┴───────┴───────┴─────┴──────┘
                       │
                ┌──────▼──────┐
                │ Retornar    │
                │ Resultado   │
                └─────────────┘
```

---

## 7. ESTRUCTURA DE DATOS - LISTA CIRCULAR

```
┌────────────────────────────────────────────────┐
│         LISTA CIRCULAR DINÁMICA                │
│                                                │
│  Ejemplo: 3 jugadores (A, B, C)                │
│                                                │
│   nodo_cabeza (apunta al primero)              │
│        │                                       │
│        ▼                                       │
│   ┌─────────┐    ┌─────────┐    ┌─────────┐  │
│   │ JUGADOR │    │ JUGADOR │    │ JUGADOR │  │
│   │    A    │───►│    B    │───►│    C    │  │
│   │ Puntaje:│    │ Puntaje:│    │ Puntaje:│  │
│   │    0    │    │    0    │    │    0    │  │
│   └─────────┘    └─────────┘    └─────────┘  │
│        ▲              │              │        │
│        │              │              │        │
│        └──────────────┴──────────────┘        │
│             (vuelve al primero)               │
│                                                │
│  nodo_actual -> apunta al jugador              │
│                 que debe jugar                 │
│                                                │
│  ROTACIÓN: nodo_actual = nodo_actual->siguiente
│                                                │
└────────────────────────────────────────────────┘
```

---
