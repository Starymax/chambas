package clase6;

import java.util.ArrayList;

public class EmpresaMain {
    private String nombre;
    private Gerente gerente;
    private ArrayList<Trabajador> trabajadores;

    public EmpresaMain(String nombre, Gerente gerente){
        this.nombre = nombre;
        this.gerente = gerente;
        this.trabajadores = new ArrayList<>();
    }

    public void agregarTrabajador(Trabajador t){
        if (!(t instanceof Gerente)) {
            trabajadores.add(t);
        }
    }

    public int calcularTotalSueldos(){
        int total = 0;
        for (Trabajador t : trabajadores){
            total = total + t.getSueldo();
        }
        return total;
    }

    public void mostrarSueldos(){
        System.out.println("Salario del gerente: " + gerente.getSueldo());
        for (Trabajador t : trabajadores)
            System.out.println("Salario de " + t.nombre + ": " + t.getSueldo());
        System.out.println("Total a pagar en sueldos: " + calcularTotalSueldos());
    }

    public static void main(String[] args) {
        EmpresaMain empresa = new EmpresaMain("emprepapu", new Gerente("diego", 1, 5));

        empresa.agregarTrabajador(new Trabajador("gael", 2, 100, 40));
        empresa.agregarTrabajador(new PorContrato("guicho", 3, 2000));
        empresa.agregarTrabajador(new PorComision("caporal", 4, 5000));
        empresa.agregarTrabajador(new Trabajador("ian", 5, 120, 35));
        empresa.agregarTrabajador(new PorContrato("oswaldo", 6, 1500));

        empresa.mostrarSueldos();
    }
}