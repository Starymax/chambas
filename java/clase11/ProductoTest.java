package clase11;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class ProductoTest {

    @Test
    void venderProductos() {
        Producto producto = new Producto("TestProduct", 100, 10);
        assertEquals(5, producto.venderProductos(5));
    }

    @Test
    void agregarProductos() {
        Producto producto = new Producto("TestProduct", 100, 10);
        assertEquals(15, producto.agregarProductos(5));
    }

    @Test
    void descuento() {
        Producto producto = new Producto("TestProduct", 100, 10);
        assertEquals(10, producto.descuento(10));
    }

    @Test
    void actualizarNombre() {
        Producto producto = new Producto("TestProduct", 100, 10);
        assertEquals("NewName", producto.actualizarNombre("NewName"));
    }

    @Test
    void constructorTest() {
        Producto producto = new Producto("TestProduct", 100, 10);
        assertNotNull(producto);
    }
}