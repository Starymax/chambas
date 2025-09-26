package clase5;

public class InmuebleMain{
    public static void main(String[] args) {
        Inmueble inmueble = new Inmueble(25, "norte");
        Vivienda vivienda = new Vivienda(25, "sur", 3, 45);
        Locales local = new Locales(25, "este", "media vuelta", "wiwiwi");
        System.out.println(inmueble.toString());
        System.out.println(vivienda.toString());
        System.out.println(local.toString());
    }
}
