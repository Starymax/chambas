package clase5;

public class Inmueble{
    protected int area;
    protected String direccion;

    public Inmueble(){
        this.area = 0;
        this.direccion = null;
    }
    public Inmueble(int area, String direccion){
        this.area = area;
        this.direccion = direccion;
    }
    @Override
    public String toString(){
        return "El inmueble tiene un area de: " + this.area + " en la direccion: " + this.direccion;
    }
}
