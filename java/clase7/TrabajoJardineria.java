package clase7;

public class TrabajoJardineria extends Servicio{
    private int macetas;
    private double sup;

    /**
     * 
     * @param trabajador
     * @param cliente
     * @param sup
     * @param macetas
     */
    public TrabajoJardineria(String trabajador, String cliente, double sup, int macetas){
        super(trabajador, cliente);
        this.macetas = macetas;
        this.sup = sup;
    }
/**
 * calcula el costo del material
 */
    @Override
    public double costeMaterial(){
        double coste = macetas * 10;
        if (sup < 50)
            coste += 100;
        else coste += 200;
        return coste;
    }
/**
 * calcula el costo de la mano de obra
 */
    @Override
    public double costeManoObra(){
        return (macetas * 10 + sup * 15);
    }
/**
 * calcula el costo total
 */
    @Override
    public double costeTotal(){
        return costeManoObra() + costeMaterial();
    }
    /**
     * regresa el nombre del cliente
     */
    @Override
    public String getname(){
        return this.cliente;
    }
}
