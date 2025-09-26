package clase6;

public class PorContrato extends Trabajador{
    private int impuesto;

    public PorContrato(String name, int id, int impuesto){
        super(name, id, 0, 0);
        this.impuesto = impuesto;
        this.sueldo = calcularSueldo();
    }
    public int calcularSueldo(){
        return 10000 - impuesto;
    }
    public int getSueldo(){
        return this.sueldo;
    }
}
