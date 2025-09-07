package clase2;

import java.util.Scanner;

public class PersonaMain{
    public static void main(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Ingrese el nombre de la persona: ");
        String nombre = sc.nextLine();
        System.out.println("Ingrese la edad de la Persona: ");
        int edad = sc.nextInt();
        System.out.println("Ingrese la altura de la persona: ");
        int altura = sc.nextInt();
        Persona p1 = new Persona(nombre, edad, altura);
    }
}