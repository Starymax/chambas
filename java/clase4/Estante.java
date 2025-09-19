package clase4;

import java.util.ArrayList;

public class Estante {
    private int codigo;
    private ArrayList<Libros> coleccion;

    public Estante(){
        this.codigo = 0;
        this.coleccion= new ArrayList<Libros>();
    }
    public Estante(int num){
        this.codigo = num;
        this.coleccion= new ArrayList<Libros>();
    }
    public int getCodigo(){
        return codigo;
    }
    public ArrayList<Libros> getColeccion(){
        return coleccion;
    }
    public void newLibro(String nombre, String autor, int isbn){
        coleccion.add(new Libros(nombre, autor, isbn));
    }
    public boolean checkLibro(String nombre){
        boolean value = false;
        for(Libros l: this.coleccion){
            if(l.getNombre().equals(nombre))
                value = true;
        }
        return value;
    }
}
