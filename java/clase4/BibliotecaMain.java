package clase4;

import java.util.ArrayList;
import java.util.Scanner;

public class BibliotecaMain {
    private ArrayList<Estante> estantes;

    public BibliotecaMain(){
        this.estantes = new ArrayList<Estante>();
        estantes.add(new Estante());
    }
    public void addEstante(){
        estantes.add(new Estante(estantes.size()));
    }
    public void addLibros(String nombre, String autor, int isbn){
        Estante ff = estantes.get(estantes.size() - 1);
        if(ff.getColeccion().size() == 19){
            addEstante();
            ff = estantes.get(estantes.size() - 1);
        }
        ff.newLibro(nombre, autor, isbn);
    }
    public int contarLibros(){
        int num = 0;
        for(Estante e: this.estantes){
            num = num + e.getColeccion().size();
        }
        return num;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        BibliotecaMain biblioteca = new BibliotecaMain();

        System.out.println("ingrese el nombre del libro a ingresar: ");
        String name = sc.nextLine();
        System.out.println("ingrese el autor: ");
        String autor = sc.nextLine();
        System.out.println("ingrese el isbn: ");
        int isbn = sc.nextInt();
        biblioteca.addLibros(name, autor, isbn);

        System.out.println("ingrese el numero de estante en el que desea buscar");
        Estante actual = biblioteca.estantes.get(sc.nextInt());
        sc.nextLine();
        System.out.println("Ingrese el nombre del libro a buscar: ");
        name = sc.nextLine();
        if(actual.checkLibro(name))
            System.out.println("El libro: " + name + " existe");
        else System.out.println("El libro: " + name + " no existe");
        sc.close();

        System.out.println("la cantidad total de libros en la biblioteca es: " + biblioteca.contarLibros());
    }
}
