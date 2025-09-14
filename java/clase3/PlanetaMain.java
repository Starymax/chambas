package clase3;

import java.util.Scanner;

public class PlanetaMain{
    public static Planeta ingresar(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Ingrese el nombre del planeta: ");
        String nombre = sc.nextLine();
        System.out.println("Ingrese los satélites del planeta: ");
        int sat = sc.nextInt();
        System.out.println("Ingrese la masa del planeta: ");
        double masa = sc.nextDouble();
        System.out.println("Ingrese el volumen del planeta: ");
        double vol = sc.nextDouble();
        System.out.println("¿El planeta es observable? (true/false)");
        boolean obs = sc.nextBoolean();
        sc.nextLine();
        Planeta p = new Planeta(nombre, sat, masa, vol, obs);
        sc.close();
        return p;
    }
    public static void main(String[] args){
        SistemaSolar ss = new SistemaSolar(ingresar());
        ss.p.imprimir();
    }
}
