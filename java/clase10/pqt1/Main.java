package clase10.pqt1;
import clase10.pqt2.*;

public class Main {
    public static void main(String[] args) {
        Biblioteca bb = new Biblioteca("librazos");
        Usuario tonito = new Usuario("tonito");

        Libros lb = new Libros("principito","nose:v");
        Libros lb1 = new Libros("luna de pluton","dros");
        Libros lb2 = new Libros("biblia","gaelsamei");
        Libros lb3 = new Libros("hola","wn");

        bb.addLibro(lb);
        bb.addLibro(lb1);
        bb.addLibro(lb2);
        bb.addLibro(lb3);

        bb.prestarLibro(tonito, lb2);
        bb.buscar("biblia");
        bb.regresarLibro(tonito, lb2);
        bb.buscar("biblia");
        bb.prestarLibro(tonito, lb2);
        bb.prestarLibro(tonito, lb);

        for(Libros l : bb.getArray()){
            System.out.println(bb.info(l));
        }
    }
}
