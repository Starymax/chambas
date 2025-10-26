package clase10.pqt2;
import java.util.ArrayList;
import clase10.pqt1.Usuario;

public class Biblioteca {
    private String nombre;
    private ArrayList<Libros> lbs;

    public Biblioteca(String nombre){
        this.nombre = nombre;
        lbs = new ArrayList<>();
    }

    public void buscar(String nm){
        Libros aux = null;
        for(Libros l : lbs)
            if(l.getName().equals(nm))
                aux = l;
        if(aux != null)
            System.out.println(info(aux));
        else System.out.println("no existe el libro");
    }

    public void addLibro(Libros lb){
        lb.setId(lbs.size());
        lbs.add(lb);
    }
    public String getNombre() {
        return nombre;
    }
    public ArrayList<Libros> getArray(){
        return lbs;
    }
    public void prestarLibro(Usuario pp, Libros lb){
        pp.pedirLibro(lb);
    }
    public void regresarLibro(Usuario pp, Libros lb){
        pp.devolverLibro(lb);
    }

    public String info(Libros lb){
        if(lb.getPrestado()) return(lb.getId() + " " + lb.getName() + '\n' + lb.getAutor() + '\n' + "prestado" + '\n');
        else return(lb.getId() + " " + lb.getName() + '\n' + lb.getAutor() + '\n' + "no prestado" + '\n');
    }
}
