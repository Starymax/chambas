package clase2;

public class Persona{
    private String nombre;
    private int edad;
    private float altura;
    private boolean mayor;

    public Persona(){
        this.nombre = ":v";
        this.edad = 0;
        this.altura = 0;
        this.mayor = false;
    }
    public Persona(String nombre, int edad, float altura){
        this.nombre = nombre;
        this.edad = edad;
        this.altura = altura;
        if(edad >= 18)
            this.mayor = true;
        else this.mayor = false;
    }
    public String getNombre(){
        return this.nombre;
    }
    public int getEdad(){
        return this.edad;
    }
    public float getAltura(){
        return this.altura;
    }
    public boolean getMayor(){
        return this.mayor;
    }
    public void setNombre(String nombre){
        this.nombre = nombre;
    }
}
