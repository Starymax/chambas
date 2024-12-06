% definimos al papa del papa del papa del papa del papa del papa


%% Primera generacion %%

es_hombre(abraham).
es_hombre(clancy).
es_mujer(mona).
es_mujer(jackie).

engendro_a(abraham, herb).
engendro_a(abraham, homero).
engendro_a(mona, homero).
engendro_a(clancy, marge).
engendro_a(clancy, patty).
engendro_a(clancy, selma).
engendro_a(jackie, marge).
engendro_a(jackie, patty).
engendro_a(jackie, selma).


%% Segunda generacion %%

es_hombre(homero).
es_hombre(herb).
es_mujer(marge).
es_mujer(patty).
es_mujer(selma).

engendro_a(homero, bart).
engendro_a(homero, lisa).
engendro_a(homero, maggie).
engendro_a(marge, bart).
engendro_a(marge, lisa).
engendro_a(marge, maggie).
engendro_a(selma, ling).


%% Tercera generacion %%

es_hombre(bart).
es_mujer(lisa).
es_mujer(maggie).
es_mujer(ling).

engendro_a(bart, jiff).
engendro_a(bart, skippy.)
engendro_a(lisa, eliza).
engendro_a(maggie, hija_de_maggie).

%% Cuarta generacion %%

es_hombre(jiff).
es_hombre(skippy).
es_mujer(eliza).
es_mujer(hija_de_maggie).

hijo(jiff).
hijo(skippy).
hijo(eliza).
hijo(hija_de_maggie).

%%%% REGLAS %%%%

es_madre(X,Y):-es_mujer(X),engendro_a(X,Y).
es_padre(X,Y):-es_hombre(X),engendro_a(X,Y).
es_hermano(X,Y):-es_padre(Z,X),es_padre(Z,Y),X\=Y.
es_hermano(X,Y):-es_madre(Z,X),es_madre(Z,Y),X\=Y.
es_hermano(X,Y):-(es_padre(Z,X),es_padre(Z,Y),X\=Y);(es_mujer(X),engendro_a(X,Y)).

