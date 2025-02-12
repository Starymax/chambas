% TABLERO
tabla([Cero, Uno, Dos, Tres, Cuatro, Cinco, Seis, Siete, Ocho]) :-
    write(' '), write(Cero), write(' | '), write(Uno), write(' | '), write(Dos), nl,
    write('---+---+---'), nl,
    write(' '), write(Tres), write(' | '), write(Cuatro), write(' | '), write(Cinco), nl,
    write('---+---+---'), nl,
    write(' '), write(Seis), write(' | '), write(Siete), write(' | '), write(Ocho), nl.

% INICIAR EL JUEGO
jugar :-
    write('ELIGE PIBE:'), nl,
    write('1. Un jugador '), nl,
    write('2. Dos jugadores'), nl,
    read(Modo),
    (Modo = 1 -> juego_pc_basico([' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ']);
     Modo = 2 -> juego2([' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ']);
     write('Numero no valido, intenta pulsando 1 o 2.'), nl, jugar).

% MODO BASICO: UN JUGADOR CONTRA LA COMPUTADORA

% SE LLAMA AL PREDICADO DE EL TURNO DEL BOT BASICO, TENIAMOS PENSADO IMPLEMENTAR EL AVANZADO PERO NO LO LOGRAMOS %

juego_pc_basico(Tablero) :-
    write('Escribe tu nombre, tu seras las X: '), read(Jugador),
    turno_pc_basico(Tablero, Jugador, 'X').

turno_pc_basico(Tablero, Jugador, Simbolo) :-
    revisar_estado1(Tablero, Jugador, Simbolo, Estado),
    (Estado = continuar  ->
        tabla(Tablero),

    % TURNO DEL JUGADOR
    
        (Simbolo = 'X' -> 
            write('VAS ERMANO (Elige una casilla del 0 al 8): '), read(Posicion), 
            (verificar(Tablero, Posicion) -> 
                (mover(Tablero, Posicion, Simbolo, NuevoTablero),
                revisar_estado1(NuevoTablero, Jugador, Simbolo, NuevoEstado),
                (NuevoEstado = continuar ->
                    turno_pc_basico(NuevoTablero, Jugador, 'O');
                    NuevoEstado = detener)); 
                (write('CIELOS VIEJO, ESA CASILLA YA ESTA MARCADA, PUCHALE OTRA VEZ'), nl, 
                turno_pc_basico(Tablero, Jugador, 'X'))); 
    
    % TURNO DE LA COMPUTADORA 

        write('AHI VA EL BOT...'), nl, 
        elegir_movimiento_basico(Tablero, Posicion), 
        mover(Tablero, Posicion, 'O', NuevoTablero),
        revisar_estado1(NuevoTablero, Jugador, 'O', NuevoEstado),
        (NuevoEstado = continuar ->
            turno_pc_basico(NuevoTablero, Jugador, 'X'); 
            NuevoEstado = detener));
        Estado = detener).

%% REVISAR SI YA EXISTE UN GANADOR O EL TABLERO ESTA LLENO LO QUE SIGNIFICARIA UN EMPATE %%
 % MEDIANTE UNA BANDERA SE DETERMINA CUANDO EL JUEGO TIENE QUE SEGUIR %
revisar_estado1(Tablero, Jugador, Simbolo, Estado) :- 
    (ganador(Tablero, Simbolo) -> 
        (Simbolo = 'X' -> write('YIYI PAPA LE GANASTE AL BOT, '), write(Jugador), nl;
        Simbolo = 'O' -> write('FF JASJDAJSDJAS LE GANO EL BOT!'), nl),
        tabla(Tablero),
        Estado = detener;

    empate(Tablero) -> 
        write('JASJDASJDJA NADIE GANO'), nl,
        tabla(Tablero),
        Estado = detener;
Estado = continuar).
    

% MODO MULTIJUGADOR %

juego2(Tablero) :-
    write('Jugador 1 (Tu seras las X): '), read(Jugador1),
    write('Jugador 2 (Tu seras las O): '), read(Jugador2),
    turno2(Tablero, Jugador1, Jugador2, 'X').

turno2(Tablero, Jugador1, Jugador2, Simbolo) :-
    revisar_estado2(Tablero, Jugador1, Jugador2, Simbolo, Estado),
    (Estado = continuar ->
        tabla(Tablero),

        % TURNO DE LOS JUGADORES

            (Simbolo = 'X' -> 
                write('LE TOCA A '), write(Jugador1);
                write('LE TOCA A '), write(Jugador2)), nl, 
                write('Elige una casilla del 0 al 8: '), read(Posicion),
                (verificar(Tablero, Posicion) ->
                    mover(Tablero, Posicion, Simbolo, NuevoTablero),
                    revisar_estado2(NuevoTablero, Jugador1, Jugador2, Simbolo, Estado),
                    (Estado = continuar ->
                        (Simbolo = 'X' -> NuevoSimbolo = 'O'; NuevoSimbolo = 'X'), 
                        turno2(NuevoTablero, Jugador1, Jugador2, NuevoSimbolo));
                    (write('CIELOS VIEJO, ESA CASILLA YA ESTA MARCADA, PUCHALE OTRA VEZ'), nl,
                    turno2(Tablero, Jugador1, Jugador2, Simbolo)));
                    Estado = detener).

%% REVISAR SI YA GANO O HUBO EMPATE MULTIJUGADOR %%

revisar_estado2(Tablero, Jugador1, Jugador2, Simbolo, Estado) :- 
    (ganador(Tablero, Simbolo) -> 
        (Simbolo = 'X' -> write('Y EL MAS CABRON DE GATO ES: '), write(Jugador1), nl; 
        write('Y EL MAS CABRON DE GATO ES: '), write(Jugador2), nl),
        tabla(Tablero),
        Estado = detener;

    empate(Tablero) -> 
        write('JASJDASJDJA NADIE GANO'), nl,
        tabla(Tablero),
        Estado = detener;
    
    Estado = continuar).


% MOVIMIENTO DE LA COMPUTADORA EN MODO BASICO
elegir_movimiento_basico(Tablero, Posicion) :-
    posiciones_libres(Tablero, Libres),
    (buscar_victoria(Tablero, 'O', Libres, Posicion);
     elegir_movimiento_aleatorio(Libres, Posicion)).

% BUSCAR VICTORIA
buscar_victoria(Tablero, Simbolo, [Posicion|_], Posicion) :-
    mover_simulado(Tablero, Posicion, Simbolo, NuevoTablero),
    ganador(NuevoTablero, Simbolo).
buscar_victoria(Tablero, Simbolo, [_|Resto], Posicion) :-
    buscar_victoria(Tablero, Simbolo, Resto, Posicion).

% MOVIMIENTO ALEATORIO
elegir_movimiento_aleatorio(Libres, Posicion) :-
    length(Libres, N), % QUITAMOS LENGTH??? %      -      %% ÑO %%
    random(0, N, Indice),
    obtener_elemento(Libres, Indice, Posicion).

% OBTENER POSICIONES LIBRES
posiciones_libres(Tablero, Libres) :-
    posiciones_libres(Tablero, Libres, 0).

posiciones_libres([], [], _).
posiciones_libres([Cabeza|Cola], [Indice|Libres], Indice) :-
    \+ (Cabeza = 'X'; Cabeza = 'O'),
    NuevoIndice is Indice + 1,
    posiciones_libres(Cola, Libres, NuevoIndice).
posiciones_libres([_|Cola], Libres, Indice) :-
    NuevoIndice is Indice + 1,
    posiciones_libres(Cola, Libres, NuevoIndice).

% VERIFICAR CASILLA
verificar(Tablero, Posicion) :-
    obtener_elemento(Tablero, Posicion, Valor),
    Valor \= 'X',
    Valor \= 'O'.

% MOVER
mover([_|Cola], 0, Simbolo, [Simbolo|Cola]).
mover([Cabeza|Cola], Posicion, Simbolo, [Cabeza|NuevoCola]) :-
    Posicion > 0,
    NuevoIndice is Posicion - 1,
    mover(Cola, NuevoIndice, Simbolo, NuevoCola).

% SIMULAR MOVER

% SE EVALUAN LOS MOVIMIENTOS POSIBLES SIN QUE SE ACTUALICE EL TABLERO %
mover_simulado([_|Cola], 0, Simbolo, [Simbolo|Cola]).
mover_simulado([Cabeza|Cola], Posicion, Simbolo, [Cabeza|NuevoCola]) :-
    Posicion > 0,
    NuevoIndice is Posicion - 1,
    mover_simulado(Cola, NuevoIndice, Simbolo, NuevoCola).

% GANADOR
ganador(Tablero, Simbolo) :-
    fila(Tablero, Simbolo);
    columna(Tablero, Simbolo);
    diagonal(Tablero, Simbolo).

%% SE VERIFICA EL EMPATE %%
empate([]).
empate([Cabeza|Cola]) :-
    Cabeza \= ' ',
    empate(Cola).

% FILAS
fila([A, A, A, _, _, _, _, _, _], A) :- A \= ' '.
fila([_, _, _, A, A, A, _, _, _], A) :- A \= ' '.
fila([_, _, _, _, _, _, A, A, A], A) :- A \= ' '.

% COLUMNAS
columna([A, _, _, A, _, _, A, _, _], A) :- A \= ' '.
columna([_, A, _, _, A, _, _, A, _], A) :- A \= ' '.
columna([_, _, A, _, _, A, _, _, A], A) :- A \= ' '.

% DIAGONALES
diagonal([A, _, _, _, A, _, _, _, A], A) :- A \= ' '.
diagonal([_, _, A, _, A, _, A, _, _], A) :- A \= ' '.

% OBTENER ELEMENTO DE UNA LISTA
obtener_elemento([Cabeza|_], 0, Cabeza).
obtener_elemento([_|Cola], Posicion, Elemento) :-
    Posicion > 0,
    NuevoIndice is Posicion - 1,
    obtener_elemento(Cola, NuevoIndice, Elemento).






