collatz(1,[1]).
collatz(N,[N|Cola]):-
    N>1,
    N mod 2 =:= 0,
    N1 is N//2,
    collatz(N1,Cola).
collatz(N,[N|Cola]):-
    N>1,
    N mod 2 =:= 1,
    N1 is 3*N+1,
    collatz(N1,Cola).

f(1, 1).
f(2, 1).
f(X,Res):-
    X>=3,
    X1 is X-1,
    X2 is X-2,
    f(X1, Res1),
    f(X2, Res2),
    Res is (X1*Res1)-(X2*Res2).

funcion(1,0).
funcion(K,Result):-
    K>1,
    K1 is K//2,
    funcion(K1,Result2),
    Result is Result2 + K*K.

es_par(X):- X mod 2 =:= 0.