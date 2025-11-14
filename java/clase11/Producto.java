package clase11;

public class Producto {
    private String nombre;
    private int precio;
    private int cantidad;

    public Producto(String nombre, int precio, int cantidad){
        this.nombre= nombre;
        this.precio = precio;
        this.cantidad = cantidad;
    }

    public int venderProductos(int c){
        this.cantidad -= c;
        return cantidad;
    }
    public int agregarProductos(int c){
        this.cantidad += c;
        return cantidad;
    }
    public int descuento(int descuento){
        return this.precio*descuento/100;
    }
    public String actualizarNombre(String nombre){
        this.nombre = nombre;
        return this.nombre;
    }
}
