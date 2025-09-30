package clase7;

import java.util.ArrayList;
import java.util.Scanner;

public class Empresa{
    public static void main(String[] args) {
        ArrayList<Servicio> ser = new ArrayList<>();
        ser.add(new TrabajoPintura("gael", "caporal", 60, 20));
        ser.add(new TrabajoJardineria("gael", "antorcha", 60, 20));
        ser.add(new TrabajoPintura("gael", "marlene", 60, 20));
        ser.add(new TrabajoJardineria("gael", "marlene", 60, 20));

        Scanner sc = new Scanner(System.in);
        System.out.println("de que cliente quieres saber pues carambolas");
        String nombre = sc.nextLine();
        double total = 0;

        for(int i = 0; i<4; i++){
            if(nombre.equalsIgnoreCase(ser.get(i).getname())){
                total += ser.get(i).costeTotal();
            }
        }
        System.out.println(nombre + " debe a nu: " + total);
        sc.close();
    }
}