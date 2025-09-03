package clase1;

public class DemoPunto{
    public static void main(String[] args){
        System.out.println("hola");

        Punto p;
        p = new Punto(2,1);

        System.out.println("coordenada X: " + p.leerX());
        System.out.println("coordenada Y: " + p.leerY());

        p.fijarY(4);

        System.out.println("coordenada X: " + p.leerX());
      
        System.out.println("coordenada Y: " + p.leerY());
    }
}