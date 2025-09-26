package clase6;

public class PorComision extends Trabajador{
    private int ventas;

    public PorComision(String name, int id, int ventas){
        super(name, id, 0, 0);
        this.ventas = ventas;
        this.sueldo = calcularSueldo();
    }
    public int calcularSueldo(){
        return 5000 + (ventas/10);
    }
    public int getSueldo(){
        return this.sueldo;
    }
}
