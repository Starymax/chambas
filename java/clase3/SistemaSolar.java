package clase3;

import java.util.ArrayList;

public class SistemaSolar{
    private ArrayList<Planeta> p;
    private ArrayList<Estrella> e;

    public SistemaSolar(){
        p = new ArrayList<>();
        e = new ArrayList<>();
    }
    public SistemaSolar(Planeta planeta){
        p = new ArrayList<>();
        p.add(planeta);
    }
    public void agregarPlaneta(Planeta planeta){
        p.add(planeta);
    }
    public ArrayList<Planeta> getPlaneta(){
        return p;
    }
    public void agregarEstrella(Estrella est){
        e.add(est);
    }
    public ArrayList<Estrella> getEstrella(){
        return e;
    }
    public void imprimirPlanetas(int i){
        for(int h = 0; h < i; h++){
            Planeta planeta = p.get(h);
            System.out.println("Planeta: " + planeta.getNombre());
            System.out.println("Satelites: " + planeta.getSat());
            System.out.println("Masa: " + planeta.getMasa());
            System.out.println("Volumen: " + planeta.getVol());
            if(planeta.getObs())
                System.out.println("Es observable a simple vista");
            else System.out.println("No es observable a simple vista");
            System.out.println("Densidad: " + planeta.densidad());
        }
    }
}