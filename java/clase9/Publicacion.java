package clase9;

public abstract class Publicacion{
    protected String titulo;
    protected int ano;
    protected int ejemplares;

    public Publicacion(String titulo, int ano, int ejemplares){
        this.titulo = titulo;
        this.ano = ano;
        this.ejemplares = ejemplares;
    }

    abstract public String getTitulo();
    abstract public int getAno();
    abstract public int getEjemplares();
    abstract public String getAutor();
}
