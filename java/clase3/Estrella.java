package clase3;

public class Estrella {
    private String nombre;

    public Estrella(){
        this.nombre = null;
    }
    public Estrella(String nombre){
        this.nombre = nombre;
    }
    public void setNombre(String nombre){
        this.nombre = nombre;
    }
    public String getNombre(){
        return this.nombre;
    }
}
