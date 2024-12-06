es_hombre(luis).
es_mujer(ana).
engendro_a(luis,maria).
engendro_a(luis,jose).
engendro_a(ana,maria).
engendro_a(ana,juan).

%REGLAS%

es_madre(X,Y):-es_mujer(X),engendro_a(X,Y).
es_padre(X,Y):-es_hombre(X),engendro_a(X,Y).
es_hermano(X,Y):-es_padre(Z,X),es_padre(Z,Y),X\=Y.
es_hermano(X,Y):-es_madre(Z,X),es_madre(Z,Y),X\=Y.
es_hermano(X,Y):-(es_padre(Z,X),es_padre(Z,Y),X\=Y);(es_mujer(X),engendro_a(X,Y)).