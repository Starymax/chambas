package clase4;

public class Libros {
    private String nombre;
    private String autor;
    private int isbn;

    public Libros(){
        this.nombre = null;
        this.autor = null;
        this.isbn = 0;
    }
    public Libros(String nombre, String autor, int isbn){
        this.nombre = nombre;
        this.autor = autor;
        this.isbn = isbn;
    }
}
