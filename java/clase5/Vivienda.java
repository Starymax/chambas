package clase5;

public class Vivienda extends Inmueble{
    private int habitaciones;
    private int superficie;

    public Vivienda(){
        this.habitaciones = 0;
        this.superficie = 0;
    }
    public Vivienda(int area, String direccion, int hab, int sup){
        super(area, direccion);
        this.habitaciones = hab;
        this.superficie = sup;
    }
    @Override
    public String toString(){
        return "La vivienda tiene: " + this.habitaciones + " habitaciones y una superficie de " + this.superficie + "en la dirección: " + this.direccion + " en un area de: " + this.area;
    }
}
