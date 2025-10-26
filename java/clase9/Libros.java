package clase9;

public class Libros extends Publicacion implements Prestable{
    private String autor;

    Libros(String titulo, int ano, int ejemplares, String autor){
        super(titulo, ano, ejemplares);
        this.autor = autor;
    }

    @Override
    public void prestar() {
        if (ejemplares > 0)
            ejemplares--;
        else System.out.println("no hay libros disponibles");
    }

    @Override
    public void devolver() {
        ejemplares++;
    }

    public String getTitulo(){
        return titulo;
    }

    public int getAno(){
        return ano;
    }

    public int getEjemplares(){
        return ejemplares;
    }

    public String getAutor(){
        return autor;
    }

    public Libros getLibro(){
        return this;
    }
}
