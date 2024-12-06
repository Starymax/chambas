%%%%% SUMATORIA %%%%%

sumatoria([],0).
sumatoria([Cabeza|Cola], Suma):-
    sumatoria(Cola, Sumacola),
    Suma is Cabeza + Sumacola.

%%%%% CONTAR %%%%%

contar([],0).
contar([_|Cola], Conteo):-
    contar(Cola, Conteocola),
    Conteo is Conteocola + 1.

%%%%% MEDIA %%%%%

media(Lista, Media):-
    sumatoria(Lista, Suma),
    contar(Lista, Conteo),
    Conteo > 0,
    Media is Suma/Conteo.

%%%%% PARIDAD %%%%%

es_par(X):- 
    0 is mod(X,2).
es_impar(X):-
    1 is mod(X,2).

%%%%% ORDENAR LISTA %%%%%

ordenar_lista([],[]).
ordenar_lista([X|Y], Z):-
    ordenar_lista(Y, Z1), inserta(X, Z1, Z).
inserta(X, [], [X]).
inserta(X, [Y|Z], [X,Y|Z]):- 
    X=<Y.
inserta(X, [Y|Z], [Y|W]):- 
    X>Y, inserta(X, Z, W).

%%%%% EXTRAER ELEMENTO %%%%%

k_elemento([Res|_], 0, Res).
k_elemento([_|N], K, Res):-
    K > 0, K1 is K - 1, k_elemento(N, K1, Res).

%%%%% MEDIANA %%%%%

mediana(Lista, Mediana):-
    contar(Lista, Conteo),
    es_impar(Conteo),
    K is (Conteo + 1)/2,
    ordenar_lista(Lista, Orden),
    k_elemento(Orden, K-1, Mediana).

mediana(Lista, Mediana):-
    contar(Lista, Conteo),
    es_par(Conteo),
    ordenar_lista(Lista, Orden),
    k_elemento(Orden, (Cnteo/2) + 1, Mediana1),
    k_elemento(Orden, (Cnteo/2), Mediana2),
    Mediana is (Mediana1 + Mediana2)/2.

%%%%% MODA %%%%%

%%%%% PRODUCTORIO %%%%%

productorio([], 0).
productorio([X|Y], Res):-
    productorio(Y, Z), Res is Z * X.