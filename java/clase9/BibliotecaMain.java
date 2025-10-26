package clase9;

import java.util.ArrayList;

public class BibliotecaMain{
    public static void main(String[] args) {
        ArrayList<Publicacion> publis = new ArrayList<Publicacion>();
        Libros p1 = new Libros("sapienswe", 2006, 7, "juan");
        Revista p2 = new Revista("we no escuchaste el ", 2007, 4, "LA MAFIA MENDEZ");
        Libros p3 = new Libros("Los ojos del perro siberiano", 2002, 9, "juan rivas");
        
        publis.add(p1);
        publis.add(p2);
        publis.add(p3);
        
        ((Libros)publis.get(0)).prestar();
    }
}
