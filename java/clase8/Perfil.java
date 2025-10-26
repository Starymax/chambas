package clase8;

import java.util.ArrayList;

public class Perfil{
    protected String name;
    protected ArrayList<Pelicula> pelis;

    public Perfil(String name){
        this.name = name;
        this.pelis = new ArrayList<Pelicula>();
    }

    public void agregarPelicula(Pelicula p){
        pelis.add(p);
    }
}