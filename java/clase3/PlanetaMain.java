package clase3;

import java.util.Scanner;

public class PlanetaMain{
    public static Planeta crear(Scanner sc){
        System.out.println("Ingrese el nombre del planeta: ");
        String nombre = sc.nextLine();
        System.out.println("Ingrese los satélites del planeta: ");
        int sat = sc.nextInt();
        sc.nextLine();
        System.out.println("Ingrese la masa del planeta: ");
        double masa = sc.nextDouble();
        sc.nextLine();
        System.out.println("Ingrese el volumen del planeta: ");
        double vol = sc.nextDouble();
        sc.nextLine();
        System.out.println("¿El planeta es observable? (Y/N)");
        String ob = sc.nextLine();
        boolean obs;
        if(ob.equals("Y"))
            obs = true;
        else obs = false;
        Planeta p = new Planeta(nombre, sat, masa, vol, obs);
        return p;
    }
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        SistemaSolar ss = new SistemaSolar();
        ss.agregarPlaneta(crear(sc));
        System.out.println();
        ss.agregarPlaneta(crear(sc));
        int i = 2;
        ss.imprimirPlanetas(i);
        sc.close();
    }
}