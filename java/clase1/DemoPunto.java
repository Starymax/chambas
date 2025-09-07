package clase1;

import java.util.Scanner;

public class DemoPunto{
    public static void main(String[] args){
        System.out.println("hola");

        Punto p = new Punto(2,1);

        System.out.println("coordenada X: " + p.leerX());
        System.out.println("coordenada Y: " + p.leerY());

        p.mueveDcha(4);

        System.out.println("coordenada X despues de mover 4 a la derecha: " + p.leerX());

        p.mueveArr(2);
      
        System.out.println("coordenada Y despues de mover 2 hacia arriba: " + p.leerY());

        System.out.println("distancia entre las coordenadas 10,10 y X y Y: " + p.distancia(10,10));

        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        System.out.println(x);
        System.out.println(toString());
    }
}