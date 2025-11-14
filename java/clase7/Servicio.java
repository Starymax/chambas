package clase7;
import java.time.LocalDate;

public abstract class Servicio{
	protected String trabajador;
    protected String cliente;
    protected LocalDate fechaInicio = LocalDate.now();

    /**
     * 
     * @param trabajador
     * @param cliente
     */
    public Servicio(String trabajador, String cliente){
        this.trabajador = trabajador;
        this.cliente = cliente;
    }
/**
 * pa calcular el coste del material
 * @return
 */
    abstract double costeMaterial();
/**
 * pa calcular el coste de la mano d obra
 * @return
 */
    abstract double costeManoObra();
/**
 * pa calcular el coste total
 * @return
 */
    abstract double costeTotal();
/**
 * pa recibir el nombre del cliente
 * @return
 */
    abstract String getname();
}
