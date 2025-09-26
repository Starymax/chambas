package clase6;

public class Trabajador{
    protected String nombre;
    protected int id;
    protected int sueldo;
    private int pagoHora;
    private int horas;

    public Trabajador(){
        nombre = null;
        id = 0;
        sueldo = 0;
        pagoHora = 0;
        horas = 0;
    }
    public Trabajador(String name, int id, int pago, int horas){
        nombre = name;
        this.id = id;
        this.pagoHora = pago;
        this.horas = horas;
        this.sueldo = calcularSueldo();
    }

    public int calcularSueldo(){
        return horas * pagoHora;
    }
    public int getSueldo(){
        return this.sueldo;
    }
}
