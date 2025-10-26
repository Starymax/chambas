package clase10.pqt2;

public class Libros {
    private String name, autor;
    private int id;
    private boolean prestado;

    public Libros(String name, String autor){
        this.name = name;
        this.autor = autor;
        id = 0;
        prestado = false;
    }

    public String getAutor() {
        return autor;
    }
    public int getId() {
        return id;
    }
    public String getName() {
        return name;
    }
    public void setId(int id) {
        this.id = id;
    }
    public boolean getPrestado(){
        return prestado;
    }
    public void prestar(){
        prestado = true;
    }
    public void devolver(){
        prestado = false;
    }
}
