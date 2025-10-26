package clase9;

public class Revista extends Publicacion implements Prestable{
    private String editor;

    Revista(String titulo, int ano, int ejemplares, String editor){
        super(titulo, ano, ejemplares);
        this.editor = editor;
    }

    @Override
    public void prestar(){
        if (ejemplares > 0)
            ejemplares--;
        else System.out.println("no hay libros disponibles");
    }

    @Override
    public void devolver(){
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
        return editor;
    }
}
