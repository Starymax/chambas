package clase7;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class EmpresaTest {

    @Test
    void testTrabajoPinturaCosteTotal() {
        TrabajoPintura pintura = new TrabajoPintura("gael", "caporal", 60, 20);
        assertEquals(1260.0, pintura.costeTotal(), 0.001);
    }

    @Test
    void testTrabajoJardineriaCosteTotal() {
        TrabajoJardineria jardineria = new TrabajoJardineria("gael", "antorcha", 60, 20);
        assertEquals(1320.0, jardineria.costeTotal(), 0.001);
    }

    @Test
    void testGetNombreTrabajoPintura() {
        TrabajoPintura pintura = new TrabajoPintura("gael", "caporal", 60, 20);
        assertEquals("gael", pintura.getname());
    }

    @Test
    void testGetNombreTrabajoJardineria() {
        TrabajoJardineria jardineria = new TrabajoJardineria("gael", "antorcha", 60, 20);
        assertEquals("gael", jardineria.getname());
    }

    @Test
    void testCosteManoObraPintura() {
        TrabajoPintura pintura = new TrabajoPintura("gael", "caporal", 60, 20);
        assertEquals(1200.0, pintura.costeManoObra(), 0.001);
    }
}