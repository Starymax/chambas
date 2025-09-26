package clase5;

public class Locales extends Inmueble{
    private String giro;
    private String nombre;

    public Locales(){
        this.giro = null;
        this.nombre = null;
    }
    public Locales(int area, String dir, String giro, String nombre){
        super(area, dir);
        this.giro = giro;
        this.nombre = nombre;
    }
    @Override
    public String toString(){
        return "El local de nombre: " + this.nombre + " tiene un area de: " + this.area +  " en la direccion: " + this.direccion + " y un giro a: " + this.giro;
    }
}
