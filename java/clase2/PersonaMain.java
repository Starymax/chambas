package clase2;

import java.util.Scanner;

public class PersonaMain {
    public static Persona pedirPersona(Scanner sc) {
        System.out.println("Ingrese el nombre de la persona: ");
        String nombre = sc.nextLine();
        System.out.println("Ingrese la edad de la Persona: ");
        int edad = sc.nextInt();
        System.out.println("Ingrese la altura de la persona: ");
        float altura = sc.nextFloat();
        sc.nextLine();
        Persona p = new Persona(nombre, edad, altura);
        return p;
    }

    public static void mostrarPersona(Persona p) {
        System.out.println("La persona " + p.getNombre() + " tiene la edad de " + p.getEdad() + " anios, y una altura de " + p.getAltura());
        if (p.getMayor())
            System.out.println(p.getNombre() + " es mayor de edad");
        else
            System.out.println(p.getNombre() + " es menor de edad");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Cuantas personas desea ingresar?");
        int cantidad = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i < cantidad; i++) {
            Persona p = pedirPersona(sc);
            mostrarPersona(p);
        }
        sc.close();
    }
}