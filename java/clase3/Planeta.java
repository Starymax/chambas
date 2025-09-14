package clase3;

public class Planeta{
    private String nombre;
    private int satelites;
    private double masa;
    private double volumen;
    private boolean observable;

    public Planeta(){
        this.nombre = null;
        this.satelites = 0;
        this.masa = 0;
        this.volumen = 0;
        this.observable = false;
    }
    public Planeta(String nombre, int satelites, double masa, double volumen, boolean observable){
        this.nombre = nombre;
        this.satelites = satelites;
        this.masa = masa;
        this.volumen = volumen;
        this.observable = observable;
    }
    public void setNombre(String nombre){
        this.nombre = nombre;
    }
    public void setSat(int sat){
        this.satelites = sat;
    }
    public void setMasa(double masa){
        this.masa = masa;
    }
    public void setVol(double vol){
        this.volumen = vol;
    }
    public void setObs(boolean obs){
        this.observable = obs;
    }
    public String getNombre(){
        return this.nombre;
    }
    public int getSat(){
        return this.satelites;
    }
    public double getMasa(){
        return this.masa;
    }
    public double getVol(){
        return this.volumen;
    }
    public boolean getObs(){
        return this.observable;
    }
    public double densidad(){
        return this.masa/this.volumen;
    }
    public void imprimir(){
        System.out.println("Planeta: " + this.nombre);
        System.out.println("Satelites: " + this.satelites);
        System.out.println("Masa: " + this.masa);
        System.out.println("Volumen: " + this.volumen);
        if(this.observable)
            System.out.println("Es observable a simple vista");
        else    System.out.println("No es observable a simple vista");
        System.out.println("Densidad: " + densidad());
    }
}
