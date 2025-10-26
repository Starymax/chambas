package clase10.pqt1;
import clase10.pqt2.*;
import java.util.ArrayList;

public class Usuario{
    private String name;
    private ArrayList<Libros> lbs;

    public Usuario(String nm){
        name = nm;
        lbs = new ArrayList<>();
    }
    
    public void pedirLibro(Libros lb){
        lbs.add(lb);
        lb.prestar();
    }
    public void devolverLibro(Libros lb){
        lbs.remove(lb);
        lb.devolver();
    }
    public String getName() {
        return name;
    }
}
