package clase6;

public class Gerente extends Trabajador{
    private int anos;

    public Gerente(String name, int id, int anos){
        super(name, id, 0, 0);
        this.anos = anos;
        this.sueldo = this.calcularSueldo();
    }
    public int calcularSueldo(){
        int plata = 0;
        for(int i = 0; i < anos; i++){
            plata = plata + 1000;
        }
        return 7500 + plata;
    }
    public int getSueldo(){
        return this.sueldo;
    }
}
