package clase7;
import java.time.LocalDate;

public abstract class Servicio{
	protected String trabajador;
    protected String cliente;
    protected LocalDate fechaInicio = LocalDate.now();

    public Servicio(String trabajador, String cliente){
        this.trabajador = trabajador;
        this.cliente = cliente;
    }

    abstract double costeMaterial();

    abstract double costeManoObra();

    abstract double costeTotal();

    abstract String getname();
}
